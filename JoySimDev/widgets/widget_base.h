#ifndef WIDGETS_WIDGET_BASE_H
#define WIDGETS_WIDGET_BASE_H

#include <QWidget>

namespace widgets {
class WidgetBase : public QWidget
{
  Q_OBJECT
public:
  WidgetBase(QWidget *parent = 0);
  virtual ~WidgetBase();
};
}

#endif // WIDGETS_WIDGET_BASE_H
