#ifndef SIM_SIMULATOR_H
#define SIM_SIMULATOR_H

#include <memory>
#include "sim_config.h"
#include <vector>

namespace viz {
  class Visualizer;
}

namespace sim {
  class Robot;
  class Odometer;
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
  void AddOdometer(std::shared_ptr<Odometer> odom);
  static std::string Version();
private:
  void ConfigureVisualizer(
      std::shared_ptr<viz::Visualizer> viz, const SimConfig& config);
  std::shared_ptr<viz::Visualizer> viz_;
  std::shared_ptr<Robot> robot_;
  std::vector<std::shared_ptr<Odometer>> odoms_;
  SimConfig config_;
};
}

#endif // SIM_SIMULATOR_H
