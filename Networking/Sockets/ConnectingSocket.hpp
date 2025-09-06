/*
This class implements a call to the connect function
of sockets as a definition to the connect_to_network virtual function
from Simple Socket.
*/
#ifndef ConnectingSocket_hpp
#define ConnectingSocket_hpp

#include <stdio.h>
#include "SimpleSocket.hpp"
#endif
namespace HDE
{
    class ConnectingSocket : public SimpleSocket
    {
    public:
        ConnectingSocket(int domain, int service, int protocol, int port, u_long intrface);

        int connect_to_network(int sock, struct sockaddr_in address);
    };
}