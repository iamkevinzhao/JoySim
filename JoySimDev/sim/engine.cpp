#include "engine.h"
#include <random>

std::random_device gRd;
std::mt19937 gGen(gRd());

namespace sim {
Engine::Engine()
{

}

float Engine::NormRand(const float &stddev) {
  std::normal_distribution<> d{0.0f, stddev};
  return d(gGen);
}
}
