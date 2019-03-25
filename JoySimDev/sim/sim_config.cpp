#include "sim_config.h"
#include <QSettings>

namespace sim {
SimConfig::SimConfig()
{

}

bool SimConfig::ReadINI(const QString &name) {
  QSettings settings(name, QSettings::IniFormat);

  const QString kRegion = "/sim";
  bool ok;
  playground_width =
      settings.value(
          kRegion + "/playground_width", playground_width).toInt(&ok);
  playground_height =
      settings.value(
          kRegion + "/playground_height", playground_height).toInt(&ok);
}
}
