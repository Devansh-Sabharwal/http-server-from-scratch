/*
In this headerfile we will derive the SimpleSocket class and implement Binding part of our server

Q What “binding” means in networking

On the server side, you must bind your socket to a specific IP address and port.
Example: "I want to listen on 127.0.0.1:8080".

Binding is done with the system call:

bind(sock, (struct sockaddr*)&address, sizeof(address));


Without binding, the OS doesn’t know which port your socket should listen on.


🔹 Why we need BindingSocket

The base class SimpleSocket is general — it creates a socket and leaves a placeholder function (connect_to_network) for “how to attach this socket to the network”.
*/
#ifndef BindingSocket_hpp
#define BinfingSocket_hpp
#include <stdio.h>
#include "SimpleSocket.hpp"
namespace HDE
{
    class BindingSocket : public SimpleSocket
    {
    public:
        BindingSocket(int domain, int service, int protocol, int port, u_long intrface)
            : SimpleSocket(domain, service, protocol, port, intrface) {} // Constructor forwarding: So when you create a BindingSocket, it first runs the SimpleSocket constructor with the given arguments.

        int connect_to_network(int sock, struct sockaddr_in address);
    };
}
#endif