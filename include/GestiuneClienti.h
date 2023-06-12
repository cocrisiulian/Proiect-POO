#ifndef GESTIUNECLIENTI_H
#define GESTIUNECLIENTI_H
#include <iostream>
#include <vector>
#include "Client.h"
class GestiuneClienti
{
    public:
    void AdaugaClient(const Client& client);
    void StergeUltimulClient();
    void StergeClientDupaNume(const std::string& nume);

private:
    std::vector<Client> clienti;
};

#endif // GESTIUNECLIENTI_H
