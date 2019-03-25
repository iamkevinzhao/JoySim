#include "odom_config.h"
#include <QSettings>
#include <QDebug>

namespace sim {
OdomConfig::OdomConfig()
{

}

bool OdomConfig::ReadINI(const QString &path) {
  const QString kRegion = "/odometer";
  QSettings settings(path, QSettings::IniFormat);
  bool ok;
  rot_dev = settings.value(kRegion + "/rot_dev", rot_dev).toFloat(&ok);
  if (!ok) {
    return false;
  }
  dis_dev = settings.value(kRegion + "/dis_dev", dis_dev).toFloat(&ok);
  if (!ok) {
    return false;
  }
  anomaly_precentage =
      settings.value(
          kRegion + "/anomaly_precentage", anomaly_precentage).toFloat(&ok);
  if (!ok) {
    return false;
  }
  anomaly_degree =
      settings.value(
          kRegion + "/anomaly_degree", anomaly_degree).toFloat(&ok);
  if (!ok) {
    return false;
  }
  return true;
}
}
