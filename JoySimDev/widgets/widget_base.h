#ifndef WIDGET_BASE_H
#define WIDGET_BASE_H

#include <QWidget>

class WidgetBase : public QWidget
{
  Q_OBJECT
public:
  WidgetBase(QWidget *parent = 0);
  virtual ~WidgetBase();
};

#endif // WIDGET_BASE_H
