#ifndef SIM_SIM_CONFIG_H
#define SIM_SIM_CONFIG_H

namespace sim {
class SimConfig
{
public:
  int playground_width = 400;
  int playground_height = 400;
  bool construct_viz = false;

  SimConfig();
};
}

#endif // SIM_SIM_CONFIG_H
