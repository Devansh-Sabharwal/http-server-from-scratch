#include "ListeningSocket.hpp"

HDE::ListeningSocket::ListeningSocket(int domain, int service, int protocol, int port, u_long intrface, int backlog) : BindingSocket(domain, service, protocol, port, intrface)
{
    this->backlog = backlog;

    start_listening();
    test_connection(listening);
}
void HDE::ListeningSocket::start_listening()
{
    listening = listen(get_sock(), backlog);
}