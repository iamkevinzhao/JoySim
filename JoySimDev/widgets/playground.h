#ifndef WIDGETS_PLAYGROUND_H
#define WIDGETS_PLAYGROUND_H

#include "widget_base.h"

namespace widgets {
class Playground : public WidgetBase
{
  Q_OBJECT

public:
  explicit Playground(const int width, const int height, QWidget *parent = 0);
  ~Playground();

protected:
  void paintEvent(QPaintEvent *event);

private:
  const int kWidth = 0;
  const int kHeight = 0;
};
}

#endif // WIDGETS_PLAYGROUND_H
