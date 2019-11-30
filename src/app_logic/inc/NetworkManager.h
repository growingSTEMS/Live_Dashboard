#ifndef FTC_LIVE_DASHBOARD_LOGIC_NETWORK_MANAGER_H
#define FTC_LIVE_DASHBOARD_LOGIC_NETWORK_MANAGER_H

#include <functional>
#include <memory>
#include <queue>

#include "CommonTypes.h"

namespace GrowingStems
{
  namespace LiveDashboard
  {
    class NetworkManager
    {
    public:
      enum NetworkState
      {
        DISCONNECTED,
        CONNECTED,
        SENDING,
        RECEIVING
      };

    private:
      NetworkManager();

    protected:
      //member data
      NetworkState m_state;

      //functions not part of the public interface but that need implemented to satisfy the comms protocal
      virtual void disconnectRequested() = 0;

    public:
      //constructors
      virtual ~NetworkManager();

      //general network functions
      virtual bool attemptConnect(const std::string ip, std::uint16_t port) = 0;
      virtual void disconnect() = 0;

      //send data functions
      virtual void sendVariable(const Variable& var) = 0;
      virtual void sendVars(const std::unordered_map<std::string, Variable> vars) = 0;

      //receive data functions
      virtual std::unordered_map<std::string, Variable> getNewestVarStates() = 0;
      virtual std::queue<Variable> getAllVarUpdates() = 0;

      //getters
      NetworkState getState() { return m_state; }
    };
  }
}

#endif
