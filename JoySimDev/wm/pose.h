#ifndef WM_POSE_H
#define WM_POSE_H

namespace wm {
struct Pose
{
  Pose(const int& x, const int& y, const float& a);
  int x;
  int y;
  float a;
};
}

#endif // POSE_H
