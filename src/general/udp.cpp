//
// Created by warnap on 12.08.2026.
//

#include "udp.h"

udp::udp(int port) {
    WSAStartup(MAKEWORD(2,2), &data);
    currentSockaddr.sin_family = AF_INET;
    currentSockaddr.sin_addr.S_un.S_addr = ADDR_ANY;
    currentSockaddr.sin_port = htons(port); //init of winsock

    targetSockaddr.sin_family = AF_INET;

    currentSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (bind(currentSocket, (sockaddr*)&currentSockaddr, sizeof(currentSockaddr)) == SOCKET_ERROR)
    {
        std::cout << "Can't bind socket! " << WSAGetLastError() << std::endl;
        return;
    }
}

udp::~udp() {
    closesocket(currentSocket);
    WSACleanup();
}

void udp::sendMSG(char* targetIp, int targetPort, char* msg, size_t sizeOfMSG) {
    targetSockaddr.sin_port = htons(targetPort);
    inet_pton(AF_INET, targetIp, &targetSockaddr.sin_addr);
    sendto(currentSocket, msg, sizeOfMSG, 0, (sockaddr*)&targetSockaddr, sizeof(targetSockaddr));
}

int udp::getMSG(char *buff) {
    ZeroMemory(buff, sizeof(buff));
    int TargetSockaddrLen = sizeof(targetSockaddr);
    ZeroMemory(&targetSockaddr, TargetSockaddrLen);
    return recvfrom(currentSocket, buff, SIZEOFBUFFEROFMSG, 0, (sockaddr*)&targetSockaddr, &TargetSockaddrLen);
}

