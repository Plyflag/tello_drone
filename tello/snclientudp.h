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
    inline void ModifierPortServeur() ;
    inline void ModifierAdresseIPServeur() ;
    bool EnvoyerMessage(const char * message, int taille);
    int RecevoirMessage();
};





#endif // SNCLIENTUDP_H
