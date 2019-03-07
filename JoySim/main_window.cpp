#include "main_window.h"
#include "ui_main_window.h"
#include <JoySimDev/sim/simulator.h>
#include <JoySimDev/viz/visualizer.h>
#include <QShortcut>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  simulator_.reset(new sim::Simulator);
  sim::SimConfig config;
  std::shared_ptr<viz::Visualizer> visualizer(new viz::Visualizer);
  simulator_->SetViz(visualizer);
  simulator_->Configure(config);
  visualizer->ConstructScene();
  simulator_->Start();
  AddPlayground(visualizer->PlaygroundWidget());

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

}

void MainWindow::on_UpPushButton_clicked()
{
  simulator_->March(-10);
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
