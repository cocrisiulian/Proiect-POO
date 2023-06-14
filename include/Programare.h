#ifndef PROGRAMARE_H
#define PROGRAMARE_H
#include "Client.h"
#include <string>
#include <vector>
#include <iostream>


class Programare {
private:
    std::string numeComplet;
    std::string programare;
    static std::vector<Programare> programari;

public:
    Programare(const std::string& numeComplet = "", const std::string& programare = "");
    void SetNumeComplet(const std::string& numeComplet);
    void SetProgramare(const std::string& programare);
    std::string GetNumeComplet() const;
    std::string GetProgramare() const;
    void AdaugaProgramare(const std::string& numeComplet, const std::string& programare);
    void AfiseazaProgramare();
    void SalveazaUltimaProgramareInregistrata(const std::string& numeFisier);
    static void AfiseazaProgramariDinFisier(const std::string& numeFisier);
    void StergeUltimaProgramareInregistrata();
    void StergeUltimaProgramareDinFisier(const std::string & numeFisier);
};

#endif

