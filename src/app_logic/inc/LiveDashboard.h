#ifndef FTC_LIVE_DASHBOARD_LOGIC_LIVE_DASHBOARD
#define FTC_LIVE_DASHBOARD_LOGIC_LIVE_DASHBOARD

#include <memory>
#include <chrono>
#include <thread>
#include <shared_mutex>
#include <atomic>

#include "AppSettings.h"
#include "NetworkManager.h"
#include "CommonTypes.h"

namespace cheeto
{
  class OutputManager;
}

namespace GrowingStems
{
  namespace LiveDashboard
  {
    class LiveDashboard
    {
    public:
      //type aliases
      using VarCallbackFunc_t = std::function<void(const Variable& var)>;

    private:
      //member data
      std::unique_ptr<AppSettings> m_settings;
      std::unique_ptr<NetworkManager> m_netMan;

      std::unique_ptr<std::thread> m_networkThread;
      std::atomic<bool> m_running;

      std::shared_ptr<cheeto::OutputManager> m_log;

      std::unordered_map<std::string, Variable> m_vars;
      mutable std::shared_mutex m_varMutex;

      //private functions
      /**
        * Function that will run in a thread when the application is connected
        * This thread is responsible for getting variable updates from the robot application
        * as well as sending variable updates to the robot application for the non-read only vars
        */
      void networkFunc();
      /**
        * Start the network thread
        * Calling this function when the thread is already started results in a no-op
        */
      void start();
      /**
        * Stop the network thread
        * Calling this function when the thread is already stopped results in a no-op
        */
      void shutdown();

    public:
      //constructors
      LiveDashboard(std::shared_ptr<AppSettings> appSettings,
                    std::unique_ptr<NetworkManager> netMan,
                    std::shared_ptr<cheeto::OutputManager> outputManager);
      ~LiveDashboard();

      //public functions
      /**
        * connect the live dashboard to the robot application
        * This function is blocking until the application connects
        */
      void connectToApplication(); //infinite wait time, chrono doesn't support negative durations
      /**
        * connect the live dashboard to the robot application
        * @param timeout: number of milliseconds to wait before ceasing connection attempt
        * @return: true if the connection was sucessfull
        */
      bool connectToApplication(std::chrono::milliseconds timeout);
      /**
        * disconnect the live dashboard from the robot application
        */
      void disconnectFromApplication();
      /**
        * Will update a user controllable variable
        * @param var: variable to be updated
        * @return: true if the variable was updated, false otherwise
        */
      bool updateVar(const Variable& var);

      //getters
      std::unordered_map<std::string, Variable> getVarMap() const; //for periodic use cases

      //setters
    };
  }
}

#endif

