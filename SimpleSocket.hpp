/*
In this file we are using Sockets from C++ that lets us to create connection between client and server

This header defines the base class `SimpleSocket` which acts as an abstraction layer over the low-level C socket API. It provides the common functionality
required to set up and manage sockets in both client and server applications.

Key responsibilities of this class:
  - manage socket file descriptor, connection status, and address info.
  - Encapsulate the setup of IPv4 socket addresses (using `sockaddr_in`).
  - Provide a test_connection function to check connection
  - Expose getters for socket, connection, and address.
  - Declare a pure virtual function `connect_to_network`, making this class an
    abstract base class. It will be derived later
*/
#ifndef SimpleSocket_hpp
#define SimpleSocket_hpp

#include <stdio.h>
#include <iostream>
#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif

namespace HDE
{
    class SimpleSocket
    {
    private:
        int sock;                   // Q why its of type int ? A- When you say sock = socket(...), you’re not holding the socket itself — you’re holding an ID number that the kernel uses to find the socket object inside its own internal tables.
        struct sockaddr_in address; // more info about sockaddr_in on line 74
        int connection;

    public:
        SimpleSocket(int domain, int service, int protocol, int port, u_long intrface);
        /*
        domain is basically what kind of addresses your socket can communicate with
        example values: AF_INET -> IPv4 , AF_INTET6 for IPv6

        serice / Type defines the communication style i.e TCP or UDP
        example: SOCK_qSTREAM for TCP and SOCK_DGRAM for UDP.

        Protocol
        Normally you set this to 0 so the system picks the default protocol for the given type.
        For SOCK_STREAM + AF_INET → that default is TCP.
        For SOCK_DGRAM + AF_INET → that default is UDP.

        Port
        the port on which we are listening
        */
        // virtual function to connect to a network
        // A virtual function lets you call the correct version of a function based on the actual object type at runtime
        virtual int connect_to_network(int sock, struct sockaddr_in address) = 0;

        // function to test sockets and connection
        void test_connection(int item_to_test);

        // getter function
        struct sockaddr_in get_address();
        int get_sock();
        int get_connection();
    };
}

#endif

/*
what actually sockaddr_in is
sockaddr_in is a structure defined in <netinet/in.h> (Linux/macOS) or <winsock2.h> (Windows).
It is specifically designed to hold an IPv4 socket address (IP + port).

Here’s its typical definition (simplified):

struct sockaddr_in {
    short            sin_family;   // Address family (AF_INET for IPv4)
    unsigned short   sin_port;     // Port number (in network byte order)
    struct in_addr   sin_addr;     // IPv4 address (binary form)
    char             sin_zero[8];  // Padding (not used, just for alignment)
};
*/