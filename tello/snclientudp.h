#ifndef SNCLIENTUDP_H
#define SNCLIENTUDP_H
#include <winsock2.h>
using namespace std;

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
    string RecevoirMessage();
};





#endif // SNCLIENTUDP_H
