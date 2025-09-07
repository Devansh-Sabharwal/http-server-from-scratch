/*

Your ConnectingSocket is useful when you want to build a C++ program that talks to servers. For example:

Writing a custom HTTP client (instead of using curl).

Talking to your own TestServer from another program.

Connecting to any external TCP server (e.g., APIs, chat servers, databases).

**You don’t have to use ConnectingSocket just to test the server. The browser works fine because it’s also a client.
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