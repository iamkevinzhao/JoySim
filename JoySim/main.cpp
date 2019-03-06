#include <QApplication>
#include "JoySimDev/widgets/playground.h"
#include "JoySimDev/widgets/robot.h"

int main(int argc, char* argv[])
{
  QApplication app(argc, argv);
  widgets::Playground playground(200, 200);
  playground.show();
  widgets::Robot robot(180, &playground);
  robot.show();
  robot.Move(10, 10);
  app.exec();
	return 0;
}
