#include "snclientudp.h"
#include "main.cpp"
#include <winsock2.h>

SNClientUDP::SNClientUDP()
{
    WSADATA wsaData;
    int iResult;
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if(iResult != 0)
    {
     cout << "Echec lors de l'initialisation de la DLL Winsock2." << endl;
     etat = -2;
    }


    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
}

SNClientUDP::~SNClientUDP()
{

}
