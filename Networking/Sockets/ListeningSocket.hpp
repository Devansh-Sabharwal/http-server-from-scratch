#ifndef ListeningSocket_hpp
#define ListeningSocket_hpp
#include <stdio.h>
#include "BindingSocket.hpp"
#endif
namespace HDE
{
    class ListeningSocket : public BindingSocket
    {
    private:
        int backlog;
        int listening;

    public:
        ListeningSocket(int domain, int service, int protocol, int port, u_long intrface, int backlog);
        void start_listening();
    };
}