#include <unordered_set>

#include "LiveDashboard.h"
#include "OutputManager.h"

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
          if (!var.second.readOnly)
          {
          } //end  if (!var.second.readOnly)
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
    LiveDashboard::LiveDashboard(std::shared_ptr<AppSettings> appSettings,
                                 std::unique_ptr<NetworkManager> netMan,
                                 std::shared_ptr<cheeto::OutputManager> outputManager) :
      m_settings(std::make_unique<AppSettings>(appSettings)),
      m_netMan(std::move(netMan)),
      m_running(false)
    {
      shutdown();

      if (outputManager == nullptr)
      {
        m_log = std::make_shared<cheeto::OutputManager>();
        m_log->addOutputLocation("stdout", std::cout, (int)Verbosity::INFO, std::chrono::milliseconds(20), "\n");
        (*m_log)((int)Verbosity::WARNING) << "WARNING: LiveDashboard: no output manager provided. operating in degraded logging state";
      } //end  if (outputManager == nullptr)
      else
      {
        m_log = outputManager;
      } //end  else
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
      while (!connected && std::chrono::duration_cast<std::chrono::milliseconds>(elapsedTime) > timeout)
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
    bool LiveDashboard::updateVar(const Variable& var)
    {
      if (m_vars.count(var.name))
      {
        m_vars[var.name].val = var.val;
        return true;
      } //end  if (m_vars.count(var.name))
      return false;
    }

    //getters
    std::unordered_map<std::string, Variable> LiveDashboard::getVarMap() const
    {
      std::shared_lock<decltype(m_varMutex)> varLock(m_varMutex);
      return m_vars;
    }
  }
}

