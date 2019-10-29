#include <qapplication.h>
#include <qcommandlineparser.h>

#include "MainWindow.h"
//#include "CmdOptions.h"
//#include "OutputManager.h"

int main(int argc, char** argv)
{
  QApplication app(argc, argv);

  MainWindow mainWindow;
  mainWindow.show();

  return app.exec();
}
