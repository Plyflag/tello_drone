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

    saServer.sin_family = AF_INET;
    saServer.sin_addr.s_addr = inet_addr(adresseIPServeur);
    saServer.sin_port = htons(portServeur);

}

SNClientUDP::~SNClientUDP()
{

}


bool SNClientUDP::EnvoyerMessage( char * message[])
{
    int iResult;
    iResult = sendto(SendSocket, SendBuf, sizeof(message), 0, (SOCKADDR *) & saServer, sizeof (saServer));
    if (iResult == SOCKET_ERROR) {
            wprintf(L"sendto failed with error: %d\n", WSAGetLastError());
            closesocket(SendSocket);
            WSACleanup();
            return 1;
    }
}
