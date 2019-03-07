#include <QApplication>
#include "JoySimDev/widgets/playground.h"
#include "JoySimDev/widgets/robot.h"
#include "main_window.h"

int main(int argc, char* argv[])
{
  QApplication app(argc, argv);
  MainWindow win;
  win.show();
  app.exec();
	return 0;
}
