#include "main_window.h"
#include "ui_main_window.h"
#include <JoySimDev/sim/simulator.h>
#include <JoySimDev/viz/visualizer.h>
#include <QShortcut>
#include <JoySimDev/widgets/odom_config.h>
#include <JoySimDev/sim/odometer.h>
#include <iostream>
#include <CPFDev/CPF/odom_fusion.h>
#include <JoySimDev/sim/trajectory_estimate.h>

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
  for (auto& odom : odoms) {
    if (!odom) {
      continue;
    }
    sim::OdomPrimitive od = odom->GetOdomPrimitive();
    fusion_->AddOdom(od.StateVec(), od.CovMat());
  }
  Eigen::Vector2f estimation;
  Eigen::Matrix2f covariance;
  cpf::Result result;
  fusion_->Fuse(estimation, covariance, result);
  traj_->Move(estimation(0), estimation(1));
  for (auto& outlier : result.outlier_info) {
    auto odom = odoms[outlier.id];
    wm::Pose prev, now;
    odom->GetOdomPoses(prev, now);
    traj_->AddAnomalyTraj(prev, now);
  }
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

  traj_.reset(new sim::TrajectoryEstimate);

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

  simulator_->AddRobotPart(traj_);

  sim::SimConfig config;
  config.ReadINI();
  std::shared_ptr<viz::Visualizer> visualizer(new viz::Visualizer);
  simulator_->SetViz(visualizer);
  simulator_->Configure(config);
  visualizer->ConstructScene();
  simulator_->Start();
  AddPlayground(visualizer->PlaygroundWidget());
  visualizer_ = visualizer;

  traj_->SetViz(visualizer);

  for (auto widget : odoms_) {
    if (widget) {
      widget->setDisabled(true);
    }
  }
  ui->AddSensorPushButton->setDisabled(true);
}

void MainWindow::on_ShowPlotPushButton_clicked()
{
  const QString kShow = "Show Plot";
  const QString kHide = "Hide Plot";
  bool show;
  if (ui->ShowPlotPushButton->text() == kShow) {
    ui->ShowPlotPushButton->setText(kHide);
    show = true;
  } else {
    ui->ShowPlotPushButton->setText(kShow);
    show = false;
  }
  for (auto& odom : odoms_) {
    auto od = odom->Odom();
    if (od) {
      visualizer_->ShowRobotTrajByID(od->GetTrajID(), show);
      visualizer_->ShowRobotTrajByID(101, show);
    }
  }
}
