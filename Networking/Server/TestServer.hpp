#ifndef TestServer_hpp
#define TestServer_hpp

#include "SimpleServer.hpp"
#include <unistd.h>

namespace HDE
{
    // TestServer:
    // This is a simple example HTTP server built on top of SimpleServer.
    // It waits for a client connection, reads the request, prints it,
    // and then responds with a fixed "Hello from Server" message.
    class TestServer : public SimpleServer
    {
    private:
        // Buffer to store data received from the client.
        // 30,000 bytes is more than enough for a small HTTP request.
        char buffer[30000] = {0};

        // File descriptor (Linux/macOS) or SOCKET handle (Windows)
        // returned by accept(). This represents the client connection.
        int new_socket;

        // Accept a new client connection (blocks until a client connects).
        void accepter();

        // Handle the request data (currently just prints the buffer).
        void handler();

        // Send a fixed HTTP response back to the client.
        void responder();

    public:
        // Constructor: sets up the server socket and immediately starts it.
        TestServer();

        // Launch the main server loop:
        // - wait for a client
        // - read their request
        // - send back a response
        // - repeat forever
        void launch();
    };
}

#endif
