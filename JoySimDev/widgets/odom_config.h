#ifndef WIDGETS_ODOM_CONFIG_H
#define WIDGETS_ODOM_CONFIG_H

#include <QWidget>
#include <memory>
#include <JoySimDev/export.h>

class QLabel;
class QLineEdit;
class QPushButton;

namespace sim {
  class Odometer;
}

namespace widgets {
class API OdomConfig : public QWidget
{
  Q_OBJECT
public:
  explicit OdomConfig(QWidget *parent = nullptr);
  void LinkOdom(std::shared_ptr<sim::Odometer> odom);
  bool Configure();
  std::shared_ptr<sim::Odometer> Odom();
  void SetOdomID(const int& id);
signals:

public slots:
private:
  QLabel* name_;
  QLabel* dis_label_;
  QLabel* rot_label_;
  QLabel* anom_prcnt_label_;
  QLineEdit* dis_dev_;
  QLineEdit* rot_dev_;
  QLineEdit* anom_prcnt_;
  QPushButton* delete_;
  std::shared_ptr<sim::Odometer> odom_;
};
}

#endif // WIDGETS_ODOM_CONFIG_H
