#include <iostream>
#include "snclientudp.h"

using namespace std;

int main()
{
    SNClientUDP client;
    client.EnvoyerMessage("command",7);
    client.EnvoyerMessage("land",7);
    client.RecevoirMessage();
    cout << "POK" << endl;
    return 0;
}

