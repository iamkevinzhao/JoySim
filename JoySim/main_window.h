#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <memory>

namespace sim {
  class Simulator;
}

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  void AddPlayground(QWidget* playground);
  ~MainWindow();

private slots:
  void on_TestPushButton_clicked();

  void on_UpPushButton_clicked();

  void on_LeftPushButton_clicked();

  void on_DownPushButton_clicked();

  void on_RightPushButton_clicked();

private:
  Ui::MainWindow *ui;
  std::shared_ptr<sim::Simulator> simulator_;

};

#endif // MAIN_WINDOW_H
