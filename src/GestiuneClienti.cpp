#include "GestiuneClienti.h"
#include <iostream>
#include <vector>

void GestiuneClienti::AdaugaClient(const Client& client) {
    clienti.push_back(client);
    cout << "Clientul a fost adaugat cu succes." << endl;
}

void GestiuneClienti::StergeUltimulClient() {
    if (!clienti.empty()) {
        clienti.pop_back();
        cout << "Ultimul client a fost sters cu succes." << endl;
    } else {
        cout << "Nu exista clienti inregistrati." << endl;
    }
}

void GestiuneClienti::StergeClientDupaNume(const string& nume) {
    bool gasit = false;
    for (auto it = clienti.begin(); it != clienti.end(); ++it) {
        if (it->GetNume() == nume) {
            clienti.erase(it);
            gasit = true;
            cout << "Clientul cu numele " << nume << " a fost sters cu succes." << endl;
            break;
        }
    }

    if (!gasit) {
        cout << "Nu s-a gasit un client cu numele " << nume << "." << endl;
    }
}
