#include "snclientudp.h"
#include "main.cpp"
#include <winsock2.h>

SNClientUDP::SNClientUDP()
{
    WSADATA wsaData;

    hostent* localHost;
    char* localIP;
    int iResult;
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if(iResult != 0)
    {
     cout << "Echec lors de l'initialisation de la DLL Winsock2." << endl;
     etat = -2;
    }
    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(sock == INVALID_SOCKET)
    {
        etat = -2;
        cout << "SOCKET ERROR" << WSAGetLastError() << endl;
    }
    else
        cout << "SOCKET OK" << endl;
}

SNClientUDP::~SNClientUDP()
{

}


bool SNClientUDP::EnvoyerMessage(const char *message, int taille)
{
    sockaddr_in RecvAddr;

    RecvAddr.sin_family = AF_INET;
    RecvAddr.sin_addr.s_addr = inet_addr("192.168.10.1");
    RecvAddr.sin_port = htons(8889);

    int iResult;

    iResult = sendto(sock, message, taille, 0, (SOCKADDR *) & RecvAddr, sizeof (RecvAddr));

    if (iResult == SOCKET_ERROR) {
            cout <<"sendto failed with error: %d\n" << endl;
            closesocket(sock);
            etat = -4;
            return false;
    }


    return true;
}

int SNClientUDP::RecevoirMessage()
{
    sockaddr_in SenderAddr;
    int SenderAddrSize = sizeof (SenderAddr);
    int iResult;
    char RecvBuf[1024];

    iResult = recvfrom(sock,RecvBuf, 1024, 0, (SOCKADDR *) & SenderAddr, &SenderAddrSize);
    cout << iResult << endl;
    cout << RecvBuf << endl;
        if (iResult == SOCKET_ERROR) {
            cout <<"sendto failed with error: %d\n" << endl;
        }
}
