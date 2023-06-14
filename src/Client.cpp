#include "Client.h"
#include <iostream>
#include <ostream>
#include <cstring>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
void Client::SetNume( char* nume)
{
    strcpy(this->nume, nume);
}

void Client::SetPrenume( char* prenume)
{
    strcpy(this->prenume, prenume);
}

void Client::SetAdresa( char* adresa)
{
    strcpy(this->adresa, adresa);
}

void Client::SetAbonament(bool valoareAbonament)
{
    abonament = valoareAbonament;
}

char* Client::GetNume()
{
    return nume;
}

char* Client::GetPrenume()
{
    return prenume;
}

char* Client::GetAdresa()
{
    return adresa;
}

bool Client::GetAbonament()
{
    return abonament;
}

Client::Client()
{
    nume = nullptr;
    prenume = nullptr;
    adresa = nullptr;
    abonament = false;
}

Client::Client(char* nume, char* prenume, char* adresa, bool abonament)
{
    this->nume = nume;
    this->prenume = prenume;
    this->adresa = adresa;
    this->abonament = abonament;
}

istream& operator>>(istream& is, Client& client)
{
    char buffer[100]; // Ajustează dimensiunea buffer-ului după nevoile tale

    cout << "Nume: ";
    is >> buffer;
    client.SetNume(buffer);

    cout << "Prenume: ";
    is >> buffer;
    client.SetPrenume(buffer);

    cout << "Adresa: ";
    is >> buffer;
    client.SetAdresa(buffer);

    cout << "Abonament (Da/Nu): ";
    is >> buffer;
    client.SetAbonament(strcmp(buffer, "Da") == 0);

    return is;
}


std::ostream& operator<<(std::ostream& out,  Client& client)
{
    out << "Nume: " << client.GetNume() << std::endl;
    out << "Prenume: " << client.GetPrenume() << std::endl;
    out << "Adresa: " << client.GetAdresa() << std::endl;
    out << "Abonament: " << (client.GetAbonament() ? "Da" : "Nu") << std::endl;
    out << "-----------------------------" << std::endl;
    return out;
}


void Client::CitesteClient(Client* client)
{
    cin.ignore();
    cout << "Introduceti numele clientului: " << endl;
    string inputNume;
    getline(cin, inputNume);
    if (client->nume != nullptr)
    {
        delete[] client->nume;
    }
    client->nume = new char[inputNume.length() + 1];
    strcpy(client->nume, inputNume.c_str());
    cout << endl;

    cout << "Introduceti prenumele clientului: " << endl;
    string inputPrenume;
    getline(cin, inputPrenume);
    if (client->prenume != nullptr)
    {
        delete[] client->prenume;
    }
    client->prenume = new char[inputPrenume.length() + 1];
    strcpy(client->prenume, inputPrenume.c_str());
    cout << endl;

    cout << "Introduceti adresa clientului: " << endl;
    string inputAdresa;
    getline(cin, inputAdresa);
    if (client->adresa != nullptr)
    {
        delete[] client->adresa;
    }
    client->adresa = new char[inputAdresa.length() + 1];
    strcpy(client->adresa, inputAdresa.c_str());
    cout << endl;

    cout << "Are clientul un abonament (0 - Nu, 1 - Da)? ";
    int valoareAbonament;
    cin >> valoareAbonament;
    cout << endl;
    client->SetAbonament(valoareAbonament != 0);
}

void Client::AfiseazaClient()
{
    cout << "Nume: " << nume << endl;
    cout << "Prenume: " << prenume << endl;
    cout << "Adresa: " << adresa << endl;
    cout << "Abonament: " << (abonament ? "Da" : "Nu") << endl;
}

void Client::AfiseazaClient(Client* client)
{
    cout << "Nume: " << client->GetNume() << endl;
    cout << "Prenume: " << client->GetPrenume() << endl;
    cout << "Adresa: " << client->GetAdresa() << endl;
    cout << "Abonament: " << (client->GetAbonament() ? "Da" : "Nu") << endl;
}

void Client::SalveazaClienti(const std::string& numeFisier, Client* client)
{
    std::ofstream fout(numeFisier, std::ios::app);
    if (fout.is_open())
    {
        fout << "Nume: " << client->GetNume() << std::endl;
        fout << "Prenume: " << client->GetPrenume() << std::endl;
        fout << "Adresa: " << client->GetAdresa() << std::endl;
        fout << "Abonament: " << (client->GetAbonament() ? "Da" : "Nu") << std::endl;
        fout << "-----------------------------" << std::endl;

        fout.close();
        std::cout << "Clientul a fost salvat cu succes in fisier." << std::endl;
    }
    else
    {
        std::cout << "Eroare la deschiderea fisierului." << std::endl;
    }
}


void Client::IncarcaClientiDinFisier(const std::string& numeFisier, std::vector<Client>& clienti)
{
    std::ifstream fisier(numeFisier);
    if (fisier.is_open())
    {
        std::string linie;
        while (std::getline(fisier, linie))
        {
            if (linie.find("Nume: ") != std::string::npos)
            {
                std::string nume = linie.substr(6);
                std::string prenume, adresa, abonamentStr;

                std::getline(fisier, prenume);
                std::getline(fisier, adresa);
                std::getline(fisier, abonamentStr);

                bool abonament = (abonamentStr == "Da");

                char* numePtr = new char[nume.length() + 1];
                std::strcpy(numePtr, nume.c_str());

                char* prenumePtr = new char[prenume.length() + 1];
                std::strcpy(prenumePtr, prenume.c_str());

                char* adresaPtr = new char[adresa.length() + 1];
                std::strcpy(adresaPtr, adresa.c_str());

                clienti.emplace_back(numePtr, prenumePtr, adresaPtr, abonament);

                delete[] numePtr;
                delete[] prenumePtr;
                delete[] adresaPtr;
            }
        }

        fisier.close();
        std::cout << "Clientii au fost incarcati din fisier " << numeFisier << std::endl;
    }
    else
    {
        std::cout << "Eroare la deschiderea fisierului " << numeFisier << std::endl;
    }
}



void Client::AfiseazaClienti(const ::string& numeFisier)
{
    ifstream fin(numeFisier);
    if (fin.is_open())
    {
        std::string line;
        while (std::getline(fin, line))
        {
            std::cout << line << std::endl;
        }
        fin.close();
    }
    else
    {
        std::cout << "Eroare la deschiderea fisierului." << std::endl;
    }
}

void Client::StergeClient(const string& numeClient, const string& numeFisier)
{
    // Deschide fisierul pentru citire
    ifstream fin(numeFisier);
    if (!fin.is_open()) {
        cout << "Eroare la deschiderea fisierului." << endl;
        return;
    }

    // Creeaza un fisier temporar pentru a stoca datele fara clientul sters
    string numeTempFisier = "temp.txt";
    ofstream fout(numeTempFisier);
    if (!fout.is_open()) {
        cout << "Eroare la deschiderea fisierului temporar." << endl;
        fin.close();
        return;
    }

    string line;
    bool gasit = false;
    bool stergeLinie = false;

    // Parcurge fiecare linie din fisier
    while (getline(fin, line)) {
        // Verifica daca linia incepe cu "Nume: "
        if (line.substr(0, 6) == "Nume: ") {
            // Extrage numele clientului din restul liniei
            string numeLinie = line.substr(6);

            // Verifica daca numele clientului corespunde cu cel cautat
            if (numeLinie == numeClient) {
                gasit = true;
                stergeLinie = true; // Marcheaza ca trebuie stearsa linia care contine numele clientului
            }
        }

        // Verifica daca trebuie sa stearga linia curenta
        if (stergeLinie) {
            // Verifica daca linia contine separatorul "-------------"
            if (line == "-----------------------------") {
                stergeLinie = false; // Opreste stergerea, deoarece a ajuns la sfarsitul informatiilor despre client
                continue; // Ignora linia care contine separatorul
            }
            continue; // Ignora linia curenta, deoarece trebuie sa o stearga
        }

        // Adauga linia in fisierul temporar
        fout << line << endl;
    }

    // Inchide fisierele
    fin.close();
    fout.close();

    // Sterge fisierul original
    remove(numeFisier.c_str());

    // Redenumește fisierul temporar
    rename(numeTempFisier.c_str(), numeFisier.c_str());

    if (gasit) {
        cout << "Clientul " << numeClient << " a fost sters." << endl;
    } else {
        cout << "Clientul " << numeClient << " nu a fost gasit." << endl;
    }
}



bool ComparareNume( Client& client1,  Client& client2)
{
    return strcmp(client1.GetNume(), client2.GetNume()) < 0;
}

void Client::SorteazaClientiDupaNume(std::vector<Client>& clienti)
{
    std::sort(clienti.begin(), clienti.end(), ComparareNume);

    for ( auto& client : clienti)
    {
        client.AfiseazaClient();
    }
}


void Client::AfiseazaClientiCuAbonament(vector<Client>& clienti)
{
    for (auto& client : clienti)
    {
        if (client.GetAbonament())
        {
            client.AfiseazaClient();
        }
    }
}

Client* Client::CautaClientDupaNume(const std::string& numeCautat, std::vector<Client>& clienti)
{
    for (auto& client : clienti)
    {
        if (client.GetNume() == numeCautat)
        {
            return &client;
        }
    }

    return nullptr; // Returneaza nullptr daca nu s-a gasit un client cu numele specificat
}
