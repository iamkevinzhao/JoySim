#ifndef SIM_SIMULATOR_H
#define SIM_SIMULATOR_H

#include <memory>

namespace viz {
  class Visualizer;
}

namespace sim {
class Simulator
{
public:
  Simulator();
  void Command(
      const int& delta_x, const int& delta_y, const float& delta_theta);
  void SetViz(std::shared_ptr<viz::Visualizer> viz);
private:
  std::shared_ptr<viz::Visualizer> viz_;
};
}

#endif // SIM_SIMULATOR_H
