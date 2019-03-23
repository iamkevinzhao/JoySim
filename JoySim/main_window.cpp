#include "main_window.h"
#include "ui_main_window.h"
#include <JoySimDev/sim/simulator.h>
#include <JoySimDev/viz/visualizer.h>
#include <QShortcut>
#include <JoySimDev/widgets/odom_config.h>
#include <JoySimDev/sim/odometer.h>
#include <iostream>
#include <CPFDev/CPF/odom_fusion.h>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  this->setWindowTitle(
      "JoySim " + QString::fromStdString(sim::Simulator::Version()));

  QShortcut* shortcut;
  shortcut = new QShortcut(QKeySequence("Up"), this);
  connect(
      shortcut, SIGNAL(activated()), this, SLOT(on_UpPushButton_clicked()));
  shortcut = new QShortcut(QKeySequence("Right"), this);
  connect(
      shortcut, SIGNAL(activated()), this, SLOT(on_RightPushButton_clicked()));
  shortcut = new QShortcut(QKeySequence("Left"), this);
  connect(
      shortcut, SIGNAL(activated()), this, SLOT(on_LeftPushButton_clicked()));

  constexpr bool backward = false;
  if (backward) {
    shortcut = new QShortcut(QKeySequence("Down"), this);
    connect(
        shortcut, SIGNAL(activated()), this, SLOT(on_DownPushButton_clicked()));
  } else {
    ui->DownPushButton->setVisible(false);
  }

  constexpr bool hide_joystick = true;
  if (hide_joystick) {
    ui->UpPushButton->setVisible(false);
    ui->DownPushButton->setVisible(false);
    ui->LeftPushButton->setVisible(false);
    ui->RightPushButton->setVisible(false);
  }

  ui->TestPushButton->setVisible(false);

  fusion_.reset(new cpf::OdomFusion);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::AddPlayground(QWidget *playground) {
  ui->PlaygroundVerticalLayout->addWidget(playground);
}

void MainWindow::on_TestPushButton_clicked()
{
  if (visualizer_) {
    static bool show = true;
    show = !show;
    visualizer_->ShowRobotTrajByID(1, show);
  }
}

void MainWindow::on_UpPushButton_clicked()
{
  simulator_->March(-10);
  auto odoms = simulator_->GetOdometers();
  fusion_->Reset();
  for (auto odom : odoms) {
    if (!odom) {
      continue;
    }
    sim::OdomPrimitive od = odom->GetOdomPrimitive();
    fusion_->AddOdom(od.StateVec(), od.CovMat());
  }
  Eigen::Vector2f estimation;
  Eigen::Matrix2f covariance;
  fusion_->Fuse(estimation, covariance);
}

void MainWindow::on_LeftPushButton_clicked()
{
  simulator_->Rotate(-10);
}

void MainWindow::on_DownPushButton_clicked()
{
  simulator_->March(10);
}

void MainWindow::on_RightPushButton_clicked()
{
  simulator_->Rotate(10);
}

void MainWindow::on_AddSensorPushButton_clicked()
{
  std::shared_ptr<sim::Odometer> odom(new sim::Odometer);
  auto widget = new widgets::OdomConfig(this);
  ui->SensorSourceGridLayout->addWidget(widget);
  widget->LinkOdom(odom);
  odoms_.push_back(widget);
  widget->SetOdomID(odoms_.size());
}

void MainWindow::on_StartPushButton_clicked()
{
  ui->StartPushButton->setDisabled(true);

  for (auto widget : odoms_) {
    if (widget) {
      widget->Configure();
    }
  }

  simulator_.reset(new sim::Simulator);
  for (auto widget : odoms_) {
    if (widget) {
      simulator_->AddOdometer(widget->Odom());
    }
  }
  sim::SimConfig config;
  std::shared_ptr<viz::Visualizer> visualizer(new viz::Visualizer);
  simulator_->SetViz(visualizer);
  simulator_->Configure(config);
  visualizer->ConstructScene();
  simulator_->Start();
  AddPlayground(visualizer->PlaygroundWidget());
  visualizer_ = visualizer;

  for (auto widget : odoms_) {
    if (widget) {
      widget->setDisabled(true);
    }
  }
  ui->AddSensorPushButton->setDisabled(true);
}
