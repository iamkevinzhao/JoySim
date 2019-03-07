#ifndef SIM_ENGINE_H
#define SIM_ENGINE_H

namespace sim {
class Engine
{
public:
  Engine();
  void March(
      const float& dist, float& sim_dist, float& sim_dev, float& sim_delta_ang);
  void Rotate(const float& ang, float& sim_ang);
};
}

#endif // ENGINE_H