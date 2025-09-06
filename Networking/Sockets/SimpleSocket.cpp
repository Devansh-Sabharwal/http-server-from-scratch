#include "SimpleSocket.hpp"

// Constructor
HDE::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long intrface)
{
    // define address structure
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(intrface);

    // establish socket
    sock = socket(domain, service, protocol);
    test_connection(sock);
}
// Implementation to test_connection function
void HDE::SimpleSocket::test_connection(int item_to_test)
{ // confirm that the socket ot connection has been properly established
    if (item_to_test < 0)
    {
        perror("Failed to connect");
        exit(EXIT_FAILURE);
    }
}
// getter for address
struct sockaddr_in HDE::SimpleSocket::get_address()
{
    return address;
}

// getter for socket
int HDE::SimpleSocket::get_sock()
{
    return sock;
}

// getter for connection
int HDE::SimpleSocket::get_connection()
{
    return connection;
}

// setter for connection
void HDE::SimpleSocket::set_connection(int connection)
{
    this->connection = connection;
}