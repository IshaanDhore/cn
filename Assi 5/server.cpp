#include <iostream>
#include <string>
#include <winsock2.h>

int main() {
    // 0. Start Windows Sockets (Required on Windows)
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    // 1. Create socket
    SOCKET server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // 2. Bind to port 8080
    sockaddr_in addr = {AF_INET, htons(8080)};
    addr.sin_addr.s_addr = INADDR_ANY;
    bind(server_fd, (sockaddr*)&addr, sizeof(addr));

    // 3. Listen & Accept
    listen(server_fd, 1);
    std::cout << "Waiting for client...\n";
    SOCKET client_fd = accept(server_fd, nullptr, nullptr);
    std::cout << "Client connected! (Type 'exit' to quit)\n\n";

    // 4. Chat loop
    std::string msg;
    while (true) {
        char buffer[1024] = {0};
        recv(client_fd, buffer, 1024, 0);
        std::cout << "Client: " << buffer << "\n";
        if (std::string(buffer) == "exit") break;

        std::cout << "You (Server): ";
        std::getline(std::cin, msg);
        send(client_fd, msg.c_str(), msg.length(), 0);
        if (msg == "exit") break;
    }

    // 5. Close & Cleanup
    closesocket(client_fd);
    closesocket(server_fd);
    WSACleanup();
}

//g++ server.cpp -o server -lws2_32
//.\server.exe