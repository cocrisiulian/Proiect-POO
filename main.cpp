#include <iostream>
#include <vector>
#include <conio.h>
#include "Client.h"
#include "Programare.h"
using namespace std;

char afisare_meniu_principal()
{

    printf("\n");
    printf("\tMeniu\n");
    printf("\n%c A- Adaugare Client",201);
    printf("\n%c S- Afisare Client",204);
    printf("\n%c D- Salvare ultimul Client introdus in fisier",204);
    printf("\n%c F- Afisare Clienti din fisier",204);
    printf("\n%c G- Sortare Clienti dupa nume",204);
    printf("\n%c H- Afisare Clienti cu abonament",204);
    printf("\n%c E- Sterge Client",204);
    printf("\n%c Q- Cautare client dupa nume",204);
    printf("\n%c P- Intrare meniu Programari",204);
    printf("\n%c I- Info autor program",204);
    printf("\n%c X- Exit", 200);
    printf("\nIntroduceti optiunea dorita:\t");
    return toupper(getchar());
}

char afisare_meniu_programari()
{
    printf("\n");
    printf("\tMeniu Programari\n");
    printf("\n%c A- Adaugare Programare",201);
    printf("\n%c S- Afisare Programare",204);
    printf("\n%c D- Salvare ultima Programare introdusa in fisier",204);
    printf("\n%c F- Afisare Programari",204);
    printf("\n%c G- Afisare Programare din fisier",204);
    printf("\n%c E- Sterge ultima Programare inregistrata",204);
    printf("\n%c R- Sterge ultima Programare inregistrata in fisier",204);
    printf("\n%c Q- Cautare Programare dupa nume complet",204);
    printf("\n%c X- Exit", 200);
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
    std::string NumeFisierClienti = "Clienti";
    std::string NumeFisierProgramari = "Programari";
    vector<Client> clientiCuAbonament ;
    client.IncarcaClientiDinFisier(NumeFisierClienti, clienti);
    Programare program;
    vector<Programare> programari;

    do
    {
        system("cls");
        switch(afisare_meniu_principal())
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
            client.SalveazaClienti(NumeFisierClienti, &client);
            getch();
            break;
        case 'F':
            client.AfiseazaClienti(NumeFisierClienti);
            getch();
            break;
        case 'G':
        {
            client.SorteazaClientiDupaNume(clienti);
            getch();
            break;
        }
        case 'H':
            client.AfiseazaClientiCuAbonament(clienti);
            cout<<endl<<"SFARSIT DE AFISARE"<<endl;
            getch();
            break;

        case 'Q':
        {
            std::string numeCautat;
            std::cout << "Introduceti numele clientului cautat: ";
            std::cin >> numeCautat;

            Client* clientGasit = client.CautaClientDupaNume(numeCautat, clienti);

            if (clientGasit != nullptr)
            {
                std::cout << "Clientul a fost gasit!" << std::endl;
                client.AfiseazaClient();
            }
            else
            {
                std::cout << "Clientul nu a fost gasit." << std::endl;
            }
            getch();
            break;
        }
        case 'E':
        {
            string numeClient;
            cout << "Introduceti numele clientului cautat pentru stergere: ";
            cin >> numeClient;
            client.StergeClient(numeClient, NumeFisierClienti);
            getch();
            break;
        }
        case 'P':
        {
            bool meniuProgramari = true;
            while (meniuProgramari)
            {

                system("cls");
                switch (afisare_meniu_programari())
                {
                case 'A':
                {
                    std::string numeComplet, numeprogramare;
                    std::cout << "Introduceti numele complet: ";
                    std::cin.ignore();
                    std::getline(std::cin, numeComplet);
                    std::cout << "Introduceti programarea: ";
                    std::getline(std::cin, numeprogramare);
                    program.AdaugaProgramare(numeComplet, numeprogramare);
                    std::cout << "Programarea a fost adaugata cu succes!\n";
                    getch();
                    break;
                }
                case 'S':
                    program.AfiseazaProgramare();
                    getch();
                    break;
                case 'D':
                    program.SalveazaUltimaProgramareInregistrata(NumeFisierProgramari);
                    getch();
                    break;
                case 'F':
                    program.AfiseazaProgramare();
                    getch();
                    break;
                case 'G':
                    program.AfiseazaProgramariDinFisier(NumeFisierProgramari);
                    getch();
                    break;
                case 'E':
                {
                    program.StergeUltimaProgramareInregistrata();
                    break;
                }
                case 'Q':
                {
                    program.StergeUltimaProgramareDinFisier(NumeFisierProgramari);
                    break;
                }
                case 'X':
                    meniuProgramari = false; // Iesire din meniul programarilor si revenire la meniul principal
                    printf("\nIesire programari!\nApasati orice tasta pentru a reveni la meniul principal");
                    getch();
                    break;
                default:
                    cout << "Ati introdus un alt caracter decat cel din lista afisata.\n";
                    getch();
                }

            }

            getch();
            break;
        }
        case 'I':
            info_autor();
            getch();
            break;
        case 'X':
            printf("\nIesire Meniu!");
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

