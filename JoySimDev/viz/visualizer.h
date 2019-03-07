#ifndef VIZ_VISUALIZER_H
#define VIZ_VISUALIZER_H

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
  bool ConstructScene();
  void MoveRobot(
      const int &delta_x, const int &delta_y, const float &delta_theta);
  QWidget* PlaygroundWidget();
private:
  widgets::Playground* playground_ = nullptr;
  widgets::Robot* robot_ = nullptr;
};
}

#endif // VIZ_VISUALIZER_H
