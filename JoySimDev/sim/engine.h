#ifndef SIM_ENGINE_H
#define SIM_ENGINE_H

namespace sim {
class Engine
{
public:
  Engine();
  float NormRand(const float& stddev);
  bool Anomaly(const float& percentage);
//  virtual void March(
//      const float& dist, float& sim_dist, float& sim_dev, float& sim_delta_ang);
//  virtual void Rotate(const float& ang, float& sim_ang);
};
}

#endif // ENGINE_H
