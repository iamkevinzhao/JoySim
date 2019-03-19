#ifndef SIM_SIM_CONFIG_H
#define SIM_SIM_CONFIG_H

#include <JoySimDev/export.h>

namespace sim {
struct API SimConfig
{
  int playground_width = 400;
  int playground_height = 400;
  bool construct_viz = false;

  SimConfig();
};
}

#endif // SIM_SIM_CONFIG_H
