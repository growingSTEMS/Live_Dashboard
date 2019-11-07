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
    namespace Packets
    {
      struct BasePacket
      {
        enum PacketType
        {
          CONNECTION_UPDATE,
          VAR_INFORMATION,
          END_OF_OP
        };

        PacketType packetType;
      };
      struct ConnectionUpdate : public BasePacket
      {
        enum ConnectionStatus
        {
          Connect,
          Disconnect
        };

        ConnectionStatus oldStatus;
        ConnectionStatus newStatus;
      };
      struct VarInformation : public BasePacket
      {
        std::string varName;
        double value;
      };
      struct EndOfOp : public BasePacket
      {
        enum Operations
        {
          CONNECT,
          VAR_GATHERING,
        };

        Operations op;
      };
    }

    class NetworkManager
    {
    private:
      NetworkManager();

    public:
      //constructors
      virtual ~NetworkManager();

      //send data functions
      virtual void sendVariable(const Variable& var) = 0;
      virtual void sendVars(const std::unordered_map<std::string, Variable> vars) = 0;

      //receive data functions
      virtual std::unordered_map<std::string, Variable> getNewestVarStates() = 0;
      virtual std::queue<Variable> getAllVarUpdates() = 0;
    };
  }
}

#endif
