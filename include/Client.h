#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
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
    void SalveazaClienti( string& numeFisier,  vector<Client>& clienti);
    void IncarcaClientiDinFisier(const string& numeFisier, vector<Client>& clienti);
    void AfiseazaClienti(const string& numeFisier);
    void StergeClient( string& numeClient, vector<Client>& clienti);
    static bool ComparareNume(Client& client1, Client& client2);
    void SorteazaClientiDupaNume(vector<Client>& clienti);
    void AfiseazaClientiCuAbonament( vector<Client>& clienti);
    vector<Client> CautaClientiDupaPrenume(string prenumeCautat, string numeFisier);


private:
    char* nume;
    char* prenume;
    char* adresa;
    bool abonament;
};

#endif // CLIENT_H
