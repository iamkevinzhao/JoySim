#ifndef VIZ_VISUALIZER_H
#define VIZ_VISUALIZER_H

#include "viz_config.h"

namespace widgets {
  class Robot;
  class Playground;
}

class QWidget;

namespace viz {
class Visualizer
{
public:
  Visualizer();
  ~Visualizer();
  void Configure(const VizConfig& config);
  VizConfig Config();
  bool ConstructScene();
  void MoveRobot(
      const int &delta_x, const int &delta_y, const float &delta_theta);
  QWidget* PlaygroundWidget();
private:
  widgets::Playground* playground_ = nullptr;
  widgets::Robot* robot_ = nullptr;
  VizConfig config_;
};
}

#endif // VIZ_VISUALIZER_H
