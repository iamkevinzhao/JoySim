#include <QApplication>
#include "JoySimDev/widgets/playground.h"

int main(int argc, char* argv[])
{
  QApplication app(argc, argv);
  widgets::Playground playground(200, 200);
  playground.show();
  app.exec();
	return 0;
}
