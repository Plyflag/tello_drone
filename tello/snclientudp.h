#ifndef SNCLIENTUDP_H
#define SNCLIENTUDP_H
#include <winsock2.h>

class SNClientUDP {
private :
    SOCKET sock;
    int etat;
    unsigned short portServeur;
    char adresseIPServeur[16];


public :
    SNClientUDP();
    ~SNClientUDP();
    inline void ModifierPortServeur() { portServeur = 8889;}
    inline void ModifierAdresseIPServeur() {adresseIPServeur = "192.168.10.1";}
    bool EnvoyerMessage(char * message);
    int RecevoirMessage(char * message, int taille);
};





#endif // SNCLIENTUDP_H
