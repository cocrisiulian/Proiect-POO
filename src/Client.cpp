#include "Client.h"
#include <iostream>
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

void Client::SalveazaClienti(std::string& numeFisier, std::vector<Client>& clienti)
{
    std::ofstream fout(numeFisier, std::ios::app); // Modificare aici, folosind std::ios::app
    if (fout.is_open())
    {
        for (auto& client : clienti)
        {
            fout << "Nume: " << client.GetNume() << std::endl;
            fout << "Prenume: " << client.GetPrenume() << std::endl;
            fout << "Adresa: " << client.GetAdresa() << std::endl;
            fout << "Abonament: " << (client.GetAbonament() ? "Da" : "Nu") << std::endl;
            fout << "-----------------------------" << std::endl;
        }
        fout.close();
        std::cout << "Clientii au fost salvati cu succes in fisier." << std::endl;
    }
    else
    {
        std::cout << "Eroare la deschiderea fisierului." << std::endl;
    }
}


void Client::IncarcaClientiDinFisier(const std::string& numeFisier, std::vector<Client>& clienti)
{
    ifstream fisier(numeFisier);
    if (fisier)
    {
       // clienti.clear(); // Golește vectorul de clienți existent
        string nume, prenume, adresa, abonamentStr;
        bool abonament;

        while (std::getline(fisier, nume))
        {
            getline(fisier, prenume);
            getline(fisier, adresa);
            getline(fisier, abonamentStr);


            // Verifică dacă abonamentul este "Da" sau "Nu" și setează corespunzător
            if (abonamentStr == "Da")
                abonament = true;
            else
                abonament = false;

            std::string numeClient = nume.substr(5);
            char* numePtr = new char[numeClient.length() + 1];
            strcpy(numePtr, numeClient.c_str());

            std::string prenumeClient = prenume.substr(8);
            char* prenumePtr = new char[prenumeClient.length() + 1];
            strcpy(prenumePtr, prenumeClient.c_str());

            std::string adresaClient = adresa.substr(7);
            char* adresaPtr = new char[adresaClient.length() + 1];
            strcpy(adresaPtr, adresaClient.c_str());

            clienti.push_back(Client(numePtr, prenumePtr, adresaPtr, abonament));

            delete[] numePtr;
            delete[] prenumePtr;
            delete[] adresaPtr;

        }

        fisier.close();
        cout << "Clientii au fost incarcati din fisier " << numeFisier << endl;
    }
    else
    {
        cout << "Eroare la deschiderea fisierului " << numeFisier << endl;
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



void Client::StergeClient(string& numeClient, vector<Client>& clienti)
{
    bool gasit = false;

    for (size_t i = 0; i < clienti.size(); ++i)
    {
        if (strcmp(clienti[i].GetNume(), numeClient.c_str()) == 0)
        {
            /// Stergem clientul din vector prin functia erase
            ///Funcția erase este o funcție membru a clasei std::vector și este utilizată pentru a șterge un element din vector
            clienti.erase(clienti.begin() + i);
            gasit = true;
            break;
        }
    }

    if (gasit)
    {
        cout << "Clientul " << numeClient << " a fost sters." << endl;
    }
    else
    {
        cout << "Clientul " << numeClient << " nu a fost gasit." << endl;
    }
}




bool Client::ComparareNume(Client& client1, Client& client2)
{
    std::string nume1 = client1.GetNume();
    std::string nume2 = client2.GetNume();

    // Utilizăm operatorul de comparare pentru a verifica ordinea lexicografică a numelor
    return nume1 < nume2;
}


void Client::SorteazaClientiDupaNume(vector<Client>& clienti)
{
    std::sort(clienti.begin(), clienti.end(), ComparareNume);
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





vector<Client> Client::CautaClientiDupaPrenume(string prenumeCautat, string numeFisier)
{
    vector<Client> rezultat;

    ifstream fin(numeFisier);
    if (fin.is_open())
    {
        string line;
        while (getline(fin, line))
        {
            // Cauta linia care contine prenumele cautat
            if (line.find("Prenume: " + prenumeCautat) != string::npos)
            {
                char* nume;
                char* prenume;
                char* adresa;
                bool abonament;

                // Citeste numele, prenumele, adresa si abonamentul
                getline(fin, line); // Nume: ...
                nume = const_cast<char*>(line.substr(6).c_str());
                getline(fin, line); // Prenume: ...
                prenume = const_cast<char*>(line.substr(9).c_str());
                getline(fin, line); // Adresa: ...
                adresa = const_cast<char*>(line.substr(7).c_str());
                getline(fin, line); // Abonament: ...
                abonament = (line.substr(12) == "Da");

                // Creeaza un obiect de tip Client si adauga-l in vectorul rezultat
                Client client(nume, prenume, adresa, abonament);
                rezultat.push_back(client);
            }
        }

        fin.close();
    }
    else
    {
        cout << "Eroare la deschiderea fisierului." << endl;
    }

    return rezultat;
}



