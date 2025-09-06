/*
Imagine sockets are like telephones:

SimpleSocket: buys you a new phone, but doesn’t give it a number yet.

BindingSocket: goes to the telephone company and says "assign me number 8080 so people can call me".
*/

#include "BindingSocket.hpp"

int HDE::BindingSocket::connect_to_network(int sock, struct sockaddr_in address)
{
    return bind(sock, (struct sockaddr *)&address, sizeof(address));
}