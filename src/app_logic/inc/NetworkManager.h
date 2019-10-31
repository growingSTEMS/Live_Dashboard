#ifndef FTC_LIVE_DASHBOARD_LOGIC_NETWORK_MANAGER_H
#define FTC_LIVE_DASHBOARD_LOGIC_NETWORK_MANAGER_H

#include <functional>
#include <memory>

namespace GrowingStems
{
  namespace LiveDashboard
  {
    namespace Packets
    {
      struct Header
      {
        enum PacketType
        {
          CONNECTION_UPDATE,
          VAR_INFORMATION,
          END_OF_OP
        };

        PacketType packetType;
      };
      struct ConnectionUpdate
      {
        enum ConnectionStatus
        {
          Connect,
          Disconnect
        };

        Header header;
        ConnectionStatus oldStatus;
        ConnectionStatus newStatus;
      };
      struct VarInformation
      {
        Header header;
        std::string varName;
        double value;
      };
      struct EndOfOp
      {
        enum Operations
        {
          CONNECT,
          VAR_GATHERING,
        };

        Header header;
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
      virtual void sendConnectionUpdate(const Packets::ConnectionUpdate& conUpdate) = 0;
      virtual void sendVarInfo(const Packets::VarInformation& varInfo) = 0;
      virtual void sendEndOfOp(const Packets::EndOfOp& endOfOp) = 0;

      //receive data functions
      virtual Packets::ConnectionUpdate receivedConnectionUpdate() = 0;
      virtual Packets::VarInformation receivedVarInfo() = 0;
      virtual Packets::EndOfOp receivedEndOfOp() = 0;
    };
  }
}

#endif
