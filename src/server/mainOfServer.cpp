#include <stdio.h>
#include <iostream>
#include <winsock2.h>
#include <WS2tcpip.h>
#include <thread>

#pragma comment(lib, "ws2_32.lib")

void output(SOCKET socket1, sockaddr_in server);
void input(SOCKET socket1);

int main() {
    WSADATA data;
    WSAStartup(MAKEWORD(2,2), &data);
    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.S_un.S_addr = ADDR_ANY;
    server.sin_port = htons(7777);

    SOCKET socket1 = socket(AF_INET, SOCK_DGRAM, 0);
    bind(socket1, (sockaddr*)&server, sizeof(server));
    std::thread out(output, socket1, server);
    std::thread in(input, socket1);
    out.join();
    in.join();
    closesocket(socket1);
    WSACleanup();
}

void output(SOCKET socket1, sockaddr_in server) {
    server.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);
    while (true) {
        std::string str;
        std::cin >> str;
        sendto(socket1, str.c_str(), str.size(), 0, (sockaddr*)&server, sizeof(server));
    }
}

void input(SOCKET socket1) {
    sockaddr_in client;
    int clientLen = sizeof(client);

    char buff[1024];


    while (true) {
        ZeroMemory(&client, sizeof(client));
        ZeroMemory(buff, sizeof(buff));

        recvfrom(socket1, buff, sizeof(buff), 0, (sockaddr*)&client, &clientLen);
        char clientIp[256];
        inet_ntop(AF_INET, &client.sin_addr, clientIp, sizeof(clientIp));

        printf("from ip = %s , from port = %d \n%s\n", clientIp, client.sin_port, buff);
    }
}