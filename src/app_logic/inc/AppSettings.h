#ifndef FTC_LIVE_DASHBOARD_LOGIC_APP_SETTINGS_H
#define FTC_LIVE_DASHBOARD_LOGIC_APP_SETTINGS_H

#include <string>
#include <ostream>

namespace GrowingStems
{
  namespace LiveDashboard
  {
    enum class Verbosity
    {
      NO_INFO,
      ERROR,
      WARNING,
      INFO,
      VERBOSE_INFO,
      DEBUG_INFO,
      FUNCTION_NAME,
      ALL_INFO
    };
    class AppSettings
    {
    public:
      static Verbosity verbosity;
      static std::string logPath;
      static bool verboseLog;
    };
  }
}

std::ostream& operator<<(std::ostream& out, const GrowingStems::LiveDashboard::Verbosity& toPrint);

#endif

