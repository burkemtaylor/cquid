
#include <iostream>
#include <cquidNetworking/TCPServer.h>

int main(int argc, char* argv[]) {
    cquid::TCPServer server{cquid::IPV::V4, 8080};

    server.run();
    return 0;
}
