#include "engine.h"

namespace sim {
Engine::Engine()
{

}

void Engine::March(
    const float &dist, float &sim_dist, float &sim_dev, float &sim_delta_ang) {
  sim_dist = dist;
  sim_dev = 0.0f;
  sim_delta_ang = 0.0f;
}

void Engine::Rotate(const float &ang, float &sim_ang) {
  sim_ang = ang;
}
}
