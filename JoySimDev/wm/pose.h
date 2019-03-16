#ifndef WM_POSE_H
#define WM_POSE_H

namespace wm {
struct Pose
{
  Pose();
  Pose(const float& x, const float& y, const float& a);
  float x;
  float y;
  float a;
  int ix() const;
  int iy() const;
  void Trans(const float& dist, const float& delta_dev, const float& delta_rot);
  void Print() const;
};
}

#endif // POSE_H
