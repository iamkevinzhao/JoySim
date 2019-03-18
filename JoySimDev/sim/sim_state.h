#ifndef SIM_SIM_STATE_H
#define SIM_SIM_STATE_H

#include <JoySimDev/wm/pose.h>

namespace sim {
struct SimState
{
  wm::Pose robot_pose;
};
}

#endif // SIM_STATE_H
