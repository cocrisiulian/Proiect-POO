#include <iostream>
#include <cstring>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <vector>
#include "Serviciu.h"
#include "GestiuneClienti.h"
#include "Client.h"
#include <windows.h>
#include <algorithm>
using namespace std;

char afisare_meniu()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf("\tMeniu\n");
    printf("\nA- Adaugare Client");
    printf("\nS- Afisare Client");
    printf("\nD- Salvare Client in fisier");
    printf("\nF- Afisare Clienti din fisier");
    printf("\nG- Sortare Clienti dupa nume");
    printf("\nH- Afisare Clienti cu abonament");
    printf("\nQ- Cautare client dupa nume");
    printf("\nW- Cautare client dupa prenume");
    printf("\nQ- Cautare client dupa adresa");
    printf("\nI- Info autor program");
    printf("\nX- Exit");
    printf("\nIntroduceti optiunea dorita:\t");
    return toupper(getchar());
}
void info_autor()
{
    printf("\nAplicatie realizata de Cocris Iulian, grupa 3122A, anul II, Calculatoare");
}
int main()
{
    Client client;
    vector<Client> clienti;
    string NumeFisierClienti = "Clienti";
    vector<Client> clientiCuAbonament ;
    vector<Client> clientiFaraAbonament ;
    client.IncarcaClientiDinFisier(NumeFisierClienti, clienti);

    do
    {
        //cin.ignore();
        system("cls");
        switch(afisare_meniu())
        {
        case 'A':
            client.CitesteClient(&client);
            clienti.push_back(client);
            getch();
            break;
        case 'S':
            client.AfiseazaClient(&client);
            getch();
            break;
        case 'D':
            client.SalveazaClienti(NumeFisierClienti,clienti);
            getch();
            break;
        case 'F':
            client.AfiseazaClienti(NumeFisierClienti);
            getch();
            break;
        case 'G':
            client.SorteazaClientiDupaNume(clienti);  // Sortare dupa nume
            client.SalveazaClienti(NumeFisierClienti,clienti);
            client.AfiseazaClienti(NumeFisierClienti);  // Afișare clienți sortati
            getch();
            break;
        case 'H':
            client.AfiseazaClientiCuAbonament(clienti);
            cout<<endl<<"SFARSIT DE AFISARE"<<endl;
            getch();
            break;

        case 'W':
        {
            string prenumeCautat;
            cout << "Introduceti prenumele pentru cautare: ";
            getline(cin, prenumeCautat);
            vector<Client> rezultat = client.CautaClientiDupaPrenume(prenumeCautat.c_str(), NumeFisierClienti);
            cout << "Rezultatul cautarii dupa prenume: " << endl;
            for (auto& client : rezultat)
            {
                client.AfiseazaClient();
                cout << endl;
            }
            cout << endl;
            getch();
            break;
        }

        case 'I':
            info_autor();
            getch();
            break;
        case 'X':
            exit(1);
            getch();
            break;
        default:
            cout<<"Ati introdus un alt caracter decat cel din lista afisata.\n";
        }
    }
    while(1);
    return 0;
}
