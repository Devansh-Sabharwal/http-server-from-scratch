# HTTP Server in C

A simple HTTP server built in C using sockets. This project demonstrates basic networking concepts like socket creation, binding, listening, accepting client connections, and sending responses. It works on Windows (with Winsock2) and Linux.

This server is built incrementally—starting from a simple socket, then adding binding, listening, and connecting capabilities—demonstrating step-by-step abstraction of network programming concepts

## Project Structure

```
Http-Server-in-C/
├── Networking/
│ ├── Sockets/
│ │ ├── SimpleSocket.cpp/hpp
│ │ ├── BindingSocket.cpp/hpp
│ │ ├── ListeningSocket.cpp/hpp
│ │ └── ConnectingSocket.cpp/hpp
| ├── Server/
│ | ├── SimpleServer.cpp/hpp
│ | ├── TestServer.cpp/hpp
│ | └── test.cpp
| └── hdelibc-networking.hpp
├── hdelibc.hpp
├── ReadMe.md
```

- **Sockets**: Contains base classes for socket creation and management:
  - `SimpleSocket`: Basic socket wrapper.
  - `BindingSocket`: Extends SimpleSocket, binds to a port.
  - `ListeningSocket`: Extends BindingSocket, starts listening for clients.
  - `ConnectingSocket`: For client connections to a server.
- **Server**: Contains server logic:
  - `SimpleServer`: Base server class.
  - `TestServer`: Example HTTP server that responds with "Hello from Server".
- **hdelibc.hpp**: Main header including networking utilities.

---

## Features

- TCP-based HTTP server.
- Handles multiple connections sequentially.
- Prints received HTTP requests to console.
- Sends a simple text response (`Hello from Server`).
- Windows and Linux compatible (requires minor adjustments for `recv/send` vs `read/write`).

---

## Prerequisites

- **Windows**: MinGW or Visual Studio, link with `-lws2_32`.
- **Linux/macOS**: g++, standard networking libraries.

---

## Compilation

```bash
g++ Networking/Sockets/*.cpp Networking/Server/*.cpp -o test.exe -lws2_32
```

## Running the Server

- **Windows**

```
./test.exe
```

- **Linux**

```
./test
```

## Testing the Server

**You can test the server using:**

- Browser: Open http://localhost:8080/

- Curl:

```
curl http://localhost:8080/
```

You should see:

```
Hello from Server
```

### Notes

- The server handles requests sequentially (not multi-threaded).

- Buffer size is set to 30,000 bytes, enough for small HTTP requests.

- On Windows, recv/send and closesocket are used instead of read/write and close.

- This is a learning project to understand sockets and HTTP basics in C.
