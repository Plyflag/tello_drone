#include <iostream>
#include "snclientudp.h"

using namespace std;

int main()
{
    SNClientUDP client;
    char commande;
    cout << "Menu interactif de controle du drone" << endl;
    cout << "Veuillez faire un choix (" << endl;
    cout << "1 = decoller" << endl;
    cout << "2 = aller a gauche" << endl;
    cout << "3 = avancer" << endl;
    cout << "4 = aller a droite" << endl;
    cout << "5 = reculer" << endl;
    cout << "0 = ARRET URGENCE" << endl;
    client.EnvoyerMessage("command",7);
    while (true)
    {
        cin >> commande;
        switch (commande)
        {
            case 1 : 
                client.EnvoyerMessage("takeoff",7);
                break;
            case 2 : 
                client.EnvoyerMessage("left 5",6);
                break;
            case 3 : 
                client.EnvoyerMessage("forward 5",9);
                break;
            case 4 : 
                client.EnvoyerMessage("right 5",7);
                break;
            case 5 : 
                client.EnvoyerMessage("back 5",6);
                break;  
            case 0 : 
                client.EnvoyerMessage("emergency",9);
                break;
        }
    }
    
    client.RecevoirMessage();
    cout << "POK" << endl;
    return 0;
}

