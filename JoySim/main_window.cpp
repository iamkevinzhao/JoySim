#include "main_window.h"
#include "ui_main_window.h"
#include <JoySimDev/sim/simulator.h>
#include <JoySimDev/viz/visualizer.h>

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
  AddPlayground(visualizer->PlaygroundWidget());
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
  simulator_->Command(20, 20, 20);
}