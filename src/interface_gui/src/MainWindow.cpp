#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent)
{
  m_ui = std::make_unique<Ui_MainWindow>();
  m_ui->setupUi(this);
}

MainWindow::~MainWindow()
{
}
