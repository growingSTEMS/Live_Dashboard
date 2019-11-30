#ifndef FTC_LIVE_DASHBOARD_GUI_MAIN_WINDOW_H
#define FTC_LIVE_DASHBOARD_GUI_MAIN_WINDOW_H

#include <memory>

#include "QMainWindow"

#include "LiveDashboard.h"
#include "AppSettings.h"
#include "OutputManager.h"

#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
  Q_OBJECT;
  private:
    //member data
    std::unique_ptr<Ui_MainWindow> m_ui;
    std::unique_ptr<GrowingStems::LiveDashboard::LiveDashboard> m_app;
    std::shared_ptr<GrowingStems::LiveDashboard::AppSettings> m_settings;
    std::shared_ptr<cheeto::OutputManager> m_log;

    //private functions
    void makeConnections();

  public:
    //constructors
    MainWindow(std::shared_ptr<GrowingStems::LiveDashboard::AppSettings> appSettings,
               std::shared_ptr<cheeto::OutputManager> outputManager,
               QWidget* parent = nullptr);
    ~MainWindow();

  signals:

  public slots:
    //public slots
    void btnConnectionClicked();
    void btnRefreshClicked();
    void btnSendClicked();
};

#endif
