#include <memory>
#include <iostream>

#include <QPushButton>

#include "LiveDashboard.h"
#include "MainWindow.h"
#include "AppSettings.h"
#include "NetworkManager.h"
#include "GuiNetworkManager.h"

//using declarations
using GrowingStems::LiveDashboard::Verbosity;

//private functions
void MainWindow::makeConnections()
{
  //button connections
  connect(m_ui->btnSend, &QPushButton::clicked, this, &MainWindow::btnSendClicked);
  connect(m_ui->btnRefresh, &QPushButton::clicked, this, &MainWindow::btnRefreshClicked);
  connect(m_ui->btnConnection, &QPushButton::clicked, this, &MainWindow::btnConnectionClicked);
}

//constructors
MainWindow::MainWindow(std::shared_ptr<GrowingStems::LiveDashboard::AppSettings> appSettings,
                       std::shared_ptr<cheeto::OutputManager> outputManager,
                       QWidget* parent) :
  QMainWindow(parent)
{
  //setup settings
  if (appSettings == nullptr)
  {
    m_settings = std::make_shared<GrowingStems::LiveDashboard::AppSettings>();
  } //end  if (appSettings == nullptr)
  else
  {
    m_settings = appSettings;
  } //end  else

  //setup output manager
  if (outputManager == nullptr)
  {
    m_log = std::make_shared<cheeto::OutputManager>();
    m_log->addOutputLocation("stdout", std::cout, (int)m_settings->verbosity, std::chrono::milliseconds(200), "\n");

    (*m_log)((int)Verbosity::WARNING) << "WARN: no output manager provided. operating in a degraded logging state\n";
  } //end  if (out == nullptr)
  else
  {
    m_log = outputManager;
  } //end  else

  //setup network manager
  auto netMan = std::make_unique<GuiNetworkManager>();

  //setup app
  m_app = std::make_unique<GrowingStems::LiveDashboard::LiveDashboard>(m_settings, std::move(netMan), m_log);

  //setup UI
  m_ui = std::make_unique<Ui_MainWindow>();
  m_ui->setupUi(this);

  //connections
  makeConnections();
}

MainWindow::~MainWindow()
{
}

//public slots
void MainWindow::btnConnectionClicked()
{
}
void MainWindow::btnRefreshClicked()
{
}
void MainWindow::btnSendClicked()
{
}
