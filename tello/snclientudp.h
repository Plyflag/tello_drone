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
    void ModifierPortServeur(unsigned short port);
    void ModifierAdresseIPServeur(const char adresse[16]);
    bool EnvoyerMessage(const char * message, int taille);
    int RecevoirMessage(char * message, int taille);
};



#endif // SNCLIENTUDP_H
