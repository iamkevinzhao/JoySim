#include "odom_config.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <sim/odom_config.h>
#include <sim/odometer.h>
#include <QDebug>
#include <config.h>

namespace widgets {
OdomConfig::OdomConfig(QWidget *parent) : QWidget(parent)
{
  name_ = new QLabel(this);
  dis_label_ = new QLabel(this);
  rot_label_ = new QLabel(this);
  anom_prcnt_label_ = new QLabel(this);
  dis_dev_ = new QLineEdit(this);
  rot_dev_ = new QLineEdit(this);
  anom_prcnt_ = new QLineEdit(this);
  delete_ = new QPushButton(this);

  QGridLayout* layout = new QGridLayout(this);
  int i = 0;
  layout->addWidget(name_, 0, i++);
  layout->addWidget(dis_label_, 0, i++);
  layout->addWidget(dis_dev_, 0, i++);
  layout->addWidget(rot_label_, 0, i++);
  layout->addWidget(rot_dev_, 0, i++);
  layout->addWidget(anom_prcnt_label_, 0, i++);
  layout->addWidget(anom_prcnt_, 0, i++);
  layout->addWidget(delete_, 0, i++);

  name_->setText("Odom");
  dis_label_->setText("Dist");
  rot_label_->setText("Rot");
  anom_prcnt_label_->setText("Anomaly%");
  delete_->setText("Delete");
  delete_->hide();

  sim::OdomConfig config;
  config.ReadINI(JOYSIM_INI_FILE_NAME);
  dis_dev_->setText(QString::number(config.dis_dev));
  rot_dev_->setText(QString::number(config.rot_dev));
  anom_prcnt_->setText(QString::number(config.anomaly_precentage));
}

void OdomConfig::LinkOdom(std::shared_ptr<sim::Odometer> odom) {
  odom_ = odom;
}

std::shared_ptr<sim::Odometer> OdomConfig::Odom() {
  return odom_;
}

void OdomConfig::SetOdomID(const int &id) {
  name_->setText("Odom " + QString::number(id));
}

bool OdomConfig::Configure() {
  if (!odom_) {
    return false;
  }
  sim::OdomConfig config;
  bool ok;
  config.dis_dev = dis_dev_->text().toFloat(&ok);
  if (!ok) {
    return false;
  }
  config.rot_dev = rot_dev_->text().toFloat(&ok);
  if (!ok) {
    return false;
  }
  config.anomaly_precentage = anom_prcnt_->text().toFloat(&ok);
  if (!ok) {
    return false;
  }
  odom_->Configure(config);
  return true;
}
}
