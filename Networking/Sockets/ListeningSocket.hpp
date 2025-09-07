#ifndef ListeningSocket_hpp
#define ListeningSocket_hpp

#include <stdio.h>
#include "BindingSocket.hpp"

namespace HDE
{
    // ListeningSocket:
    // This class extends BindingSocket.
    // After a socket is created and bound to an address/port,
    // a ListeningSocket marks it as a "listening" socket that
    // can accept incoming connections (like a server).
    class ListeningSocket : public BindingSocket
    {
    private:
        // backlog: the maximum number of pending connections
        // the system should queue before refusing new ones.
        int backlog;

        // listening: status flag to indicate if the socket
        // has successfully started listening.
        int listening;

    public:
        // Constructor:
        // - domain: address family (AF_INET for IPv4, AF_INET6 for IPv6)
        // - service: socket type (SOCK_STREAM for TCP, SOCK_DGRAM for UDP)
        // - protocol: usually 0 (auto-selects correct protocol for type)
        // - port: port number to listen on
        // - intrface: interface to bind to (INADDR_ANY for all interfaces)
        // - backlog: max number of queued connections
        ListeningSocket(int domain, int service, int protocol,
                        int port, u_long intrface, int backlog);

        // Call listen() on the socket to start accepting connections.
        void start_listening();
    };
}

#endif // ListeningSocket_hpp
