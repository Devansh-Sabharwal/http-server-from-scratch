#include "ConnectingSocket.hpp"
// Construtor
HDE::ConnectingSocket::ConnectingSocket(int domain, int service, int protocol, int port, u_long intrface) : SimpleSocket(domain, service, protocol, port, intrface)
{
    set_connection(connect_to_network(get_sock(), get_address()));
    test_connection(get_connection());
}
// Definiton of the connect_to_network virtual function

int HDE::ConnectingSocket::connect_to_network(int sock, struct sockaddr_in address)
{
    return connect(sock, (struct sockaddr *)&address, sizeof(address));
}