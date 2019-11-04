#ifndef FTC_LIVE_DASHBOARD_LOGIC_LIVE_DASHBOARD
#define FTC_LIVE_DASHBOARD_LOGIC_LIVE_DASHBOARD

#include <memory>

#include "AppSettings.h"
#include "OutputManager.h"
#include "NetworkManager.h"

namespace GrowingStems
{
  namespace LiveDashboard
  {
    class LiveDashboard
    {
    private:
      //member data
      std::unique_ptr<AppSettings> m_settings;
      std::shared_ptr<cheeto::OutputManager> m_log;
      std::unique_ptr<NetworkManager> m_netMan;
      std::unordered_map<std::string, double> m_readOnlyVars;
      std::unordered_map<std::string, double> m_writeVars;

      //private functions

    public:
      //constructors
      LiveDashboard(const AppSettings& appSettings, const NetworkManager& netMan,
                    std::shared_ptr<cheeto::OutputManager> outputManager);
      ~LiveDashboard();

      //public functions
      void connectToApplication();
      void disconnectFromApplication();

      //getters

      //setters
    };
  }
}

#endif

