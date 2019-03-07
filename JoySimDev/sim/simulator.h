#ifndef SIM_SIMULATOR_H
#define SIM_SIMULATOR_H

#include <memory>
#include "sim_config.h"
#include "sim_state.h"

namespace viz {
  class Visualizer;
}

namespace sim {
  class Engine;
}

namespace sim {
class Simulator
{
public:
  Simulator();
  bool Start();
  void Configure(const SimConfig& config);
  void March(const float& distance);
  void Rotate(const float& angle);
  void SetViz(std::shared_ptr<viz::Visualizer> viz);
private:
  void ConfigureVisualizer(
      std::shared_ptr<viz::Visualizer> viz, const SimConfig& config);
  std::shared_ptr<viz::Visualizer> viz_;
  std::shared_ptr<Engine> engine_;
  SimConfig config_;
  SimState state_;
};
}

#endif // SIM_SIMULATOR_H
