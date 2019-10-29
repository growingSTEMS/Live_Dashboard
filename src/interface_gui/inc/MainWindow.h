#ifndef CHEESY_SOFTWARE_INITIATIVE_TRACKER_H
#define CHEESY_SOFTWARE_INITIATIVE_TRACKER_H

#include <memory>

#include "QMainWindow"

#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
  private:
    std::unique_ptr<Ui_MainWindow> m_ui;

  public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
  signals:
  public slots:
};

#endif
