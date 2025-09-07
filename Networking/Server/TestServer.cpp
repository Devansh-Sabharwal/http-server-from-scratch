#include "TestServer.hpp"

// Constructor: calls the base SimpleServer constructor to set up a socket,
// and then immediately launches the server loop.
HDE::TestServer::TestServer()
    : SimpleServer(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY, 10)
{
    launch();
}

// Accept a new client connection
void HDE::TestServer::accepter()
{
    // Dont confuse here
    // get_socket is server socket address (ListnerSocket we created)
    struct sockaddr_in address = get_socket()->get_address();
    socklen_t addrlen = sizeof(address);

    // Get the file descriptor (Linux) or SOCKET handle (Windows) from SimpleServer.
    int listen_fd = get_socket()->get_sock();
    if (listen_fd < 0)
    {
        std::cerr << "Invalid listening socket!" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Wait for a client to connect.
    // accept() blocks until a connection arrives.
    new_socket = accept(listen_fd, (struct sockaddr *)&address, &addrlen);
    if (new_socket < 0)
    {
        perror("accept failed");
        return;
    }

    // Receive data from the client into buffer.
    // recv() is the Winsock equivalent of read() on Linux.
    int valread = recv(new_socket, buffer, sizeof(buffer) - 1, 0);
    if (valread == SOCKET_ERROR) // Windows-specific constant
    {
        perror("recv failed");
        return;
    }

    // Null-terminate the string so we can safely print it.
    buffer[valread] = '\0';
}

//"handler" just prints the contents of buffer.
// In a real server, you’d parse the HTTP request here.
void HDE::TestServer::handler()
{
    std::cout << buffer << std::endl;
}

// Send a fixed HTTP response back to the client.
void HDE::TestServer::responder()
{
    const char *hello =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/plain\r\n"
        "\r\n"
        "Hello from Server";

    // send() is the Winsock equivalent of write().
    send(new_socket, hello, strlen(hello), 0);

    // Close the client socket (Windows requires closesocket()).
    closesocket(new_socket);
}

// Main server loop.
// Keeps waiting for new clients, handling their requests,
// and responding, one after the other.
void HDE::TestServer::launch()
{
    // Basically its a single threaded server so it can serve multiple clients simultaneoulsy, 10 clients (backlog value) can be in queue waiting to get served
    while (true)
    {
        std::cout << "=========WAITING=========" << std::endl;

        accepter();  // wait for a client connection
        handler();   // process the request
        responder(); // send response and close client socket

        std::cout << "=========DONE=========" << std::endl;
    }
}
