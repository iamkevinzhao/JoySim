#ifndef SIM_ODOM_CONFIG_H
#define SIM_ODOM_CONFIG_H

#include "engine_config.h"
#include <JoySimDev/export.h>

class QString;

namespace sim {
struct API OdomConfig : public EngineConfig
{
  float rot_dev = 10.0f;
  float dis_dev = 2.5f;
  float anomaly_precentage = 1.0f;
  float anomaly_degree = 30.0f;

  bool ReadINI(const QString& path);
  OdomConfig();
};
}

#endif // SIM_ODOM_CONFIG_H
