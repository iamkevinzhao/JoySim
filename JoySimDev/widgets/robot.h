#ifndef WIDGETS_ROBOT_H
#define WIDGETS_ROBOT_H

#include "widget_base.h"
#include <QPoint>

namespace widgets {
class Robot : public WidgetBase
{
public:
  Robot(const float& heading, QWidget* parent);
  void Move(const int& x, const int& y);
protected:
  void paintEvent(QPaintEvent *event);
private:
  const float kHeading;
  const int kRadius = 10;
  const int kBeacon = 15;
  const int kWeight = 2;
  const int kMargin;
  const int kCenter;
};
}

#endif // WIDGETS_ROBOT_H
