#include "snclientudp.h"
#include "main.cpp"
#include <winsock2.h>
using namespace std;

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
    sockaddr_in SenderAddr;

    SenderAddr.sin_family = AF_INET;
    SenderAddr.sin_addr.s_addr = inet_addr("192.168.10.1");
    SenderAddr.sin_port = htons(8889);

    int iResult;

    iResult = sendto(sock, message, taille, 0, (SOCKADDR *) & SenderAddr, sizeof (SenderAddr));

    if (iResult == SOCKET_ERROR) {
            cout <<"sendto failed with error: %d\n" << endl;
            closesocket(sock);
            etat = -4;
            return false;
    }


    return true;
}

string SNClientUDP::RecevoirMessage()
{
    sockaddr_in RecvAddr;
    int RecvAddrSize = sizeof (RecvAddr);
    char RecvBuf[1024];

    int iResult2 = recvfrom(sock,RecvBuf, sizeof(RecvBuf), 0, (SOCKADDR *) & RecvAddr, &RecvAddrSize);
        if (iResult2 == SOCKET_ERROR) {
            cout <<"sendto failed with error: %d\n" << endl;
        }
    else {
        cout << "Erreur reception" << endl;
        cout << iResult2 << endl;
        cout << RecvBuf << endl;
    }
    string str(RecvBuf);
    return str;
}
