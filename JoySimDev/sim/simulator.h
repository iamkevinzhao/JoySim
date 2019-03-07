#ifndef SIM_SIMULATOR_H
#define SIM_SIMULATOR_H

#include <memory>
#include "sim_config.h"

namespace viz {
  class Visualizer;
}

namespace sim {
class Simulator
{
public:
  Simulator();
  void Configure(const SimConfig& config);
  void Command(
      const int& delta_x, const int& delta_y, const float& delta_theta);
  void SetViz(std::shared_ptr<viz::Visualizer> viz);
private:
  void ConfigureVisualizer(
      std::shared_ptr<viz::Visualizer> viz, const SimConfig& config);
  std::shared_ptr<viz::Visualizer> viz_;
  SimConfig config_;
};
}

#endif // SIM_SIMULATOR_H
