#include "AppSettings.h"

std::ostream& operator<<(std::ostream& out, const GrowingStems::LiveDashboard::Verbosity& toPrint)
{
  switch (toPrint)
  {
    case GrowingStems::LiveDashboard::Verbosity::ALL_INFO:
      out << "ALL_INFO";
      break;
    case GrowingStems::LiveDashboard::Verbosity::DEBUG_INFO:
      out << "DEBUG_INFO";
      break;
    case GrowingStems::LiveDashboard::Verbosity::ERROR:
      out << "ERROR";
      break;
    case GrowingStems::LiveDashboard::Verbosity::FUNCTION_NAME:
      out << "FUNCTION_NAME";
      break;
    case GrowingStems::LiveDashboard::Verbosity::INFO:
      out << "INFO";
      break;
    case GrowingStems::LiveDashboard::Verbosity::NO_INFO:
      out << "NO_INFO";
      break;
    case GrowingStems::LiveDashboard::Verbosity::VERBOSE_INFO:
      out << "VERBOSE_INFO";
      break;
    case GrowingStems::LiveDashboard::Verbosity::WARNING:
      out << "WARNING";
      break;
  }
  return out;
}

