#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include "widget_base.h"

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

#endif // PLAYGROUND_H
