#ifndef SIM_ODOM_CONFIG_H
#define SIM_ODOM_CONFIG_H

#include "engine_config.h"
#include <JoySimDev/export.h>

namespace sim {
struct API OdomConfig : public EngineConfig
{
  float rot_dev = 5.0f;
  float dis_dev = 1.0f;

  OdomConfig();
};
}

#endif // SIM_ODOM_CONFIG_H
