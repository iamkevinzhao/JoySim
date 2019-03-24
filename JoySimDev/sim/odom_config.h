#ifndef SIM_ODOM_CONFIG_H
#define SIM_ODOM_CONFIG_H

#include "engine_config.h"
#include <JoySimDev/export.h>

namespace sim {
struct API OdomConfig : public EngineConfig
{
  float rot_dev = 10.0f;
  float dis_dev = 2.0f;

  OdomConfig();
};
}

#endif // SIM_ODOM_CONFIG_H
