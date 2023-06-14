#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Client
{
public:
    void SetNume( char* nume);
    void SetPrenume( char* prenume);
    void SetAdresa( char* adresa);
    void SetAbonament( bool abonament);

    char* GetNume() ;
    char* GetPrenume() ;
    char* GetAdresa() ;
    bool GetAbonament() ;
    Client();
    Client( char* nume,  char* prenume,  char* adresa, bool abonament);

    void CitesteClient(Client* client);
    void AfiseazaClient( Client* client);
    void AfiseazaClient();
    friend std::istream& operator>>(std::istream& in, Client& client);
    friend std::ostream& operator<<(std::ostream& out,  Client& client);
    static void SalveazaClienti(const std::string& numeFisier, Client* client);
    void IncarcaClientiDinFisier(const string& numeFisier, vector<Client>& clienti);
    void AfiseazaClienti(const string& numeFisier);
    void StergeClient( const string& numeClient, const string& numeFisier);
    void SorteazaClientiDupaNume(std::vector<Client>& clienti);
    void AfiseazaClientiCuAbonament( vector<Client>& clienti);
    Client* CautaClientDupaNume(const std::string& numeCautat, std::vector<Client>& clienti);

private:
    char* nume;
    char* prenume;
    char* adresa;
    bool abonament;
};

#endif // CLIENT_H
