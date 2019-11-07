#ifndef FTC_LIVE_DASHBOARD_LOGIC_COMMON_TYPES_H
#define FTC_LIVE_DASHBOARD_LOGIC_COMMON_TYPES_H

#include <string>

namespace GrowingStems
{
  namespace LiveDashboard
  {
      struct Variable
      {
        std::string name = "Var";
        double val = 0.0;
        bool readOnly = true;
      };
  }
}

#endif
