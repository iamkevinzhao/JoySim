#ifndef VIZ_VISUALIZER_H
#define VIZ_VISUALIZER_H

#include "viz_config.h"
#include <unordered_map>
#include <list>
#include <JoySimDev/export.h>

namespace widgets {
  class Robot;
  class Playground;
  class RoboTraj;
}

class QWidget;

namespace viz {
class API Visualizer
{
public:
  Visualizer();
  ~Visualizer();
  void Configure(const VizConfig& config);
  VizConfig Config();
  bool ConstructScene();
  void BeamRobot(
      const int &x, const int &y, const float &theta);
  void MoveRobot(
      const int &delta_x, const int &delta_y, const float &delta_theta);
  QWidget* PlaygroundWidget();
  void AddRobotTraj(
      const int& from_x,
      const int& from_y,
      const float& from_a,
      const int& to_x,
      const int& to_y,
      const float& to_a);
  void AddRobotTraj(
      const int &from_x,
      const int &from_y,
      const float &from_a,
      const int &to_x,
      const int &to_y,
      const float &to_a,
      const int& id);
  void ShowRobotTrajByID(const int& id, const bool& show);
private:
  widgets::Playground* playground_ = nullptr;
  widgets::Robot* robot_ = nullptr;
  VizConfig config_;
  std::unordered_map<int, std::list<widgets::RoboTraj*>> robot_trajs_;
};
}

#endif // VIZ_VISUALIZER_H
