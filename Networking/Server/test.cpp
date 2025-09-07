#include "TestServer.hpp"
int main()
{
    // specifically for windows
    // basically tells machine that this machine is ready for socket programming
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0)
    {
        std::cerr << "WSAStartup failed: " << iResult << std::endl;
        exit(EXIT_FAILURE);
    }
    HDE::TestServer t;
}
// command to srart server
// 1. g++ Sockets/SimpleSocket.cpp Sockets/BindingSocket.cpp Sockets/ListeningSocket.cpp Server/SimpleServer.cpp Server/TestServer.cpp Server/test.cpp -o test.exe -lws2_32
// 2. ./test.exe