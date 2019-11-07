#include <unordered_set>

#include "LiveDashboard.h"

namespace GrowingStems
{
  namespace LiveDashboard
  {
    //private functions
    void LiveDashboard::networkFunc()
    {
      while (m_running)
      {
        //ensure everything is still valid
        if (m_netMan == nullptr)
        {
          shutdown();
        } //end  if (m_netMan == nullptr)

        //pull new vars sent from the app
        auto newVars = m_netMan->getNewestVarStates();
        for (const auto& var : newVars)
        {
          if (var.second.readOnly)
          {
            m_vars[var.first] = var.second;
          } //end  if (var.second.readOnly)
        } //end  for (const auto& var : newVars)

        //send variables that changed
        for (const auto& var : newVars)
        {
        } //end  for (const auto& var : newVars)
      } //end  while (m_running)
    }
    void LiveDashboard::start()
    {
      if (m_networkThread != nullptr)
      {
        m_running = true;
        m_networkThread = std::make_unique<std::thread>(&LiveDashboard::networkFunc, this);
      } //end  if (m_networkThread != nullptr)
    }
    void LiveDashboard::shutdown()
    {
      if (m_networkThread != nullptr)
      {
        m_running = false;
        m_networkThread->join();
        m_networkThread.reset();
      } //end  if (m_networkThread != nullptr)
    }

    //constructors
    LiveDashboard::LiveDashboard(const AppSettings& appSettings, const NetworkManager& netMan,
                  std::shared_ptr<cheeto::OutputManager> outputManager)
    {
      shutdown();

      m_settings = std::make_unique<AppSettings>(appSettings);
      m_netMan = std::make_unique<NetworkManager>(netMan);

      m_log = outputManager;
    }
    LiveDashboard::~LiveDashboard()
    {
      shutdown();
    }

    //public functions
    void LiveDashboard::connectToApplication()
    {
      //TODO code to connect

      start();
    }
    bool LiveDashboard::connectToApplication(std::chrono::milliseconds timeout)
    {
      auto connected = false;
      auto startConnectTime = std::chrono::steady_clock::now();
      auto elapsedTime = startConnectTime - startConnectTime;
      while (!connected && std::chrono::duration<std::chrono::milliseconds>(elapsedTime).count() > timeout)
      {
        //TODO connection attempt code

        elapsedTime = std::chrono::steady_clock::now() - startConnectTime;
      } //end  while (!connected && std::chrono::duration<std::chrono::milliseconds>(elapsedTime).count() > timeout)

      //if connection was sucessfull, start network thread
      if (connected)
      {
        start();
      } //end  if (connected)
      return connected;
    }
    void LiveDashboard::disconnectFromApplication()
    {
      //TODO code to disconnect

      shutdown();
    }

    //getters
    std::unordered_map<std::string, Variable> LiveDashboard::getVarMap() const
    {
      std::shared_lock<decltype(m_varMutex)> varLock(m_varMutex);
      return m_vars;
    }
  }
}

