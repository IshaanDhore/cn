#include <iostream>
#include <string>
#include <winsock2.h>

int main() {
    // 0. Start Windows Sockets (Required on Windows)
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    // 1. Create socket
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

    // 2. Connect to localhost (127.0.0.1) on port 8080
    sockaddr_in addr = {AF_INET, htons(8080)};
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    connect(sock, (sockaddr*)&addr, sizeof(addr));
    std::cout << "Connected to Server! (Type 'exit' to quit)\n\n";

    // 3. Chat loop
    std::string msg;
    while (true) {
        std::cout << "You (Client): ";
        std::getline(std::cin, msg);
        send(sock, msg.c_str(), msg.length(), 0);
        if (msg == "exit") break;

        char buffer[1024] = {0};
        recv(sock, buffer, 1024, 0);
        std::cout << "Server: " << buffer << "\n";
        if (std::string(buffer) == "exit") break;
    }

    // 4. Close & Cleanup
    closesocket(sock);
    WSACleanup();
}

// g++ client.cpp -o client -lws2_32
// .\client.exe