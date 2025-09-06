/*
Imagine sockets are like telephones:

SimpleSocket: buys you a new phone, but doesn’t give it a number yet.
BindingSocket: goes to the telephone company and says "assign me number 8080 so people can call me".
*/

#include "BindingSocket.hpp"
// Constructor
HDE::BindingSocket::BindingSocket(int domain, int service, int protocol, int port, u_long intrface) : SimpleSocket(domain, service, protocol, port, intrface) // Constructor forwarding: So when you create a BindingSocket, it first runs the SimpleSocket constructor with the given arguments.
{
    int connection = connect_to_network(get_sock(), get_address());
    set_connection(connection);
    test_connection(connection);
}

// Implementation to connect_to_network function
int HDE::BindingSocket::connect_to_network(int sock, struct sockaddr_in address)
/*
First argument = socket file descriptor (integer ID) returned by the socket() call (refer SimpleSocket Class)
Second argument = pointer to the address you want to bind.
Third argument = size of that address struct.
*/
{
    // Note*
    // bind() expects its second parameter to be a pointer to struct sockaddr, not sockaddr_in.
    // sockaddr_in is a specialized version of sockaddr so we are explicitly casting sockaddr_in to sockaddr
    return bind(sock, (struct sockaddr *)&address, sizeof(address));
}