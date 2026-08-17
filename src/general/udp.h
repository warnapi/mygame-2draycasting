//
// Created by warnap on 12.08.2026.
//

#ifndef PERSON_GAMES_UDP_H
#define PERSON_GAMES_UDP_H

#include <winsock2.h>
#include <WS2tcpip.h>
#include "iostream"
#include "game_const.h"
#pragma comment(lib, "ws2_32.lib")

class udp {
private:
    WSADATA data;
    sockaddr_in currentSockaddr;
    sockaddr_in targetSockaddr;
    SOCKET currentSocket;
public:
    int getMSG(char* buff);
    void sendMSG(char* targetIp, int targetPort, char* msg, size_t sizeOfMSG);
    udp(int port);
    ~udp();
};


#endif //PERSON_GAMES_UDP_H
