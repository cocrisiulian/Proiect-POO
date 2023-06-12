#include "Serviciu.h"
#include <iostream>
#include <cstring>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
/**<  Client::Client()
{
    //ctor
}

Client::~Client()
{
    //dtor
}
///-------------------------------------------------///
///Metodele pentru setarea datelor clientului       ///
///-------------------------------------------------///
// Metoda pentru setarea numelui clientului
void Client::SetNume( char* nume)
{
    strcpy(this->nume, nume);
}

// Metoda pentru setarea prenumele clientului
void Client::SetPrenume( char* prenume)
{
    strcpy(this->prenume, prenume);
}

// Metoda pentru setarea adresei clientului
void Client::SetAdresa( char* adresa)
{
    strcpy(this->adresa, adresa);
}

void Client::SetAbonament(bool valoareAbonament)
{
    abonament = valoareAbonament;
}

Client::Client(const char* nume, const char* prenume, const char* adresa, bool abonament)
{
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);

    this->prenume = new char[strlen(prenume) + 1];
    strcpy(this->prenume, prenume);

    this->adresa = new char[strlen(adresa) + 1];
    strcpy(this->adresa, adresa);

    this->abonament = abonament;
}


Client::Client()
{
    nume = new char[1];
    nume[0] = '\0';
    prenume = new char[1];
    prenume[0] = '\0';
    adresa = new char[1];
    adresa[0] = '\0';
    abonament = false;
}

Client::Client( char* nume,  char* prenume,  char* adresa, bool abonament)
{
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);

    this->prenume = new char[strlen(prenume) + 1];
    strcpy(this->prenume, prenume);

    this->adresa = new char[strlen(adresa) + 1];
    strcpy(this->adresa, adresa);

    this->abonament = abonament;
}




///--------------------------------------------///
///Metodele pentru preluarea datelor clientului///
///--------------------------------------------///

// Metoda pentru obtinerea numelui clientului
char* Client::GetNume()
{
    return nume;
}

// Metoda pentru obtinerea prenumele clientului
char* Client::GetPrenume()
{
    return prenume;
}

// Metoda pentru obtinerea adresei clientului
char* Client::GetAdresa()
{
    return adresa;
}


bool Client::GetAbonament()
{
    return abonament;
}

///------------------------------------------------------///
///Metodele de citire date de la tastatura ale clientului///
///------------------------------------------------------///

//Metoda pentru citire client de la tastatura
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

//Metoda pentru afisare client citit de la tastatura
void Client::AfiseazaClient(Client* client)
{
    std::cout << "Nume: " << client->GetNume() << std::endl;
    std::cout << "Prenume: " << client->GetPrenume() << std::endl;
    std::cout << "Adresa: " << client->GetAdresa() << std::endl;
    std::cout << "Abonament: " << (client->GetAbonament() ? "Da" : "Nu") << std::endl;
}

//Metoda pentru afisare client citit de la tastatura
void Client::AfiseazaClient()
{
    std::cout << "Nume: " << GetNume() << std::endl;
    std::cout << "Prenume: " << GetPrenume() << std::endl;
    std::cout << "Adresa: " << GetAdresa() << std::endl;
    std::cout << "Abonament: " << (GetAbonament() ? "Da" : "Nu") << std::endl;
}

//Metoda de salvare de clienti in fisier
void Client::SalveazaClienti( std::string& numeFisier,  std::vector<Client>& clienti)
{
    std::ofstream fout(numeFisier, std::ios::trunc);
    if (fout.is_open())
    {
        for ( auto& client : clienti)
        {
            fout << "Nume: " << client.GetNume() << std::endl;
            fout << "Prenume: " << client.GetPrenume() << std::endl;
            fout << "Adresa: " << client.GetAdresa() << std::endl;
            fout << "Abonament: " << (client.GetAbonament() ? "Da" : "Nu") << std::endl;
            fout << std::endl;
        }
        fout.close();
        std::cout << "Clientii au fost salvati cu succes in fisier." << std::endl;
    }
    else
    {
        std::cout << "Eroare la deschiderea fisierului." << std::endl;
    }
}



//Metode de actualizare vectorul de clienti
void Client::IncarcaClientiDinFisier(const std::string& numeFisier, std::vector<Client>& clienti)
{
    ifstream fisier(numeFisier);
    if (fisier)
    {
        clienti.clear(); // Golește vectorul de clienți existent
        string nume, prenume, adresa, abonamentStr;
        bool abonament;

        while (std::getline(fisier, nume))
        {
            getline(fisier, prenume);
            getline(fisier, adresa);
            getline(fisier, abonamentStr);
            fisier.ignore(); // Ignoră linia goală

            // Verifică dacă abonamentul este "Da" sau "Nu" și setează corespunzător
            if (abonamentStr == "Da")
                abonament = true;
            else
                abonament = false;

            std::string numeClient = nume.substr(6);
            char* numePtr = new char[numeClient.length() + 1];
            strcpy(numePtr, numeClient.c_str());

            std::string prenumeClient = prenume.substr(9);
            char* prenumePtr = new char[prenumeClient.length() + 1];
            strcpy(prenumePtr, prenumeClient.c_str());

            std::string adresaClient = adresa.substr(8);
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


//Metoda de afisare de clienti din fisier
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


// Metoda de comparare pentru sortare după nume
bool Client::ComparareNume(Client& client1, Client& client2)
{
    return strcmp(client1.GetNume(), client2.GetNume()) < 0;
}

// Metoda pentru sortarea clientilor după nume
void Client::SorteazaClientiDupaNume(vector<Client>& clienti)
{
    sort(clienti.begin(), clienti.end(), ComparareNume);
}

//Metoda pentru afisare clienti cu abonament
void Client::AfiseazaClientiCuAbonament( std::vector<Client>& clienti)
{
    std::cout << "Clientii care au abonament sunt urmatorii:" << std::endl;
    for (auto& client : clienti)
    {
        if (client.GetAbonament())
        {
            client.AfiseazaClient();
            std::cout << std::endl;
        }
    }
}


std::vector<Client> CautaClientiDupaNume(std::string& numeFisier, std::string& numeCautat)
{
    std::vector<Client> rezultat;

    std::ifstream fisier(numeFisier);
    if (fisier)
    {
        std::string line;
        while (std::getline(fisier, line))
        {
            if (std::strncmp(line.c_str(), "Nume: ", 6) == 0)
            {
                std::string numeClient = line.substr(6);
                std::string prenume, adresa, abonamentStr;

                if (std::getline(fisier, line) && std::strncmp(line.c_str(), "Prenume: ", 9) == 0)
                {
                    prenume = line.substr(9);

                    if (std::getline(fisier, line) && std::strncmp(line.c_str(), "Adresa: ", 8) == 0)
                    {
                        adresa = line.substr(8);

                        if (std::getline(fisier, line) && std::strncmp(line.c_str(), "Abonament: ", 11) == 0)
                        {
                            abonamentStr = line.substr(11);

                            bool abonament = (abonamentStr == "Da");
                            if (numeClient == numeCautat)
                            {
                                rezultat.push_back(Client(numeClient, prenume, adresa, abonament));
                            }
                        }
                    }
                }
            }
        }

        fisier.close();
    }
    else
    {
        std::cout << "Eroare la deschiderea fisierului " << numeFisier << std::endl;
    }

    return rezultat;
}




vector<Client> Client::CautaClientiDupaPrenume(string& prenumeCautat, string& numeFisier) {
    vector<Client> clienti;
    IncarcaClientiDinFisier(numeFisier, clienti);

    vector<Client> rezultat;
    for (auto& client : clienti) {
        if (string(client.GetPrenume()) == "Prenume: " + prenumeCautat) {
            rezultat.push_back(client);
        }
    }

    if (rezultat.empty()) {
        throw runtime_error("Nu s-au gasit clienti cu prenumele specificat.");
    }

    return rezultat;
}

vector<Client> Client::CautaClientiDupaAdresa(string& adresaCautata, string& numeFisier) {
    vector<Client> clienti;
    IncarcaClientiDinFisier(numeFisier, clienti);

    vector<Client> rezultat;
    for (auto& client : clienti) {
        if (string(client.GetAdresa()) == "Adresa: " + adresaCautata) {
            rezultat.push_back(client);
        }
    }

    if (rezultat.empty()) {
        throw runtime_error("Nu s-au gasit clienti cu adresa specificata.");
    }

    return rezultat;
}

***/
