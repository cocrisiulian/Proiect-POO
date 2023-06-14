#include "Programare.h"
#include <iostream>
#include <fstream>

std::vector<Programare> Programare::programari;

Programare::Programare(const std::string& numeComplet, const std::string& programare)
    : numeComplet(numeComplet), programare(programare) {}

void Programare::SetNumeComplet(const std::string& numeComplet) {
    this->numeComplet = numeComplet;
}

void Programare::SetProgramare(const std::string& programare) {
    this->programare = programare;
}

std::string Programare::GetNumeComplet() const {
    return numeComplet;
}

std::string Programare::GetProgramare() const {
    return programare;
}

void Programare::AdaugaProgramare(const std::string& numeComplet, const std::string& programare) {
    Programare programareObiect(numeComplet, programare);
    programari.push_back(programareObiect);
}

void Programare::AfiseazaProgramare() {
    if (programari.empty()) {
        std::cout << "Nu exista programari inregistrate." << std::endl;
        return;
    }

    std::cout << "Programari existente:\n";
    for (const auto& programare : programari) {
        std::cout << "Nume complet: " << programare.GetNumeComplet() << std::endl;
        std::cout << "Programare: " << programare.GetProgramare() << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }
}

void Programare::SalveazaUltimaProgramareInregistrata(const std::string& numeFisier) {
    if (programari.empty()) {
        std::cout << "Nu exista programari inregistrate." << std::endl;
        return;
    }

    const Programare& ultimaProgramare = programari.back();
    std::ofstream fout(numeFisier, std::ios::app);
    if (fout.is_open()) {
        fout << "Nume complet: " << ultimaProgramare.GetNumeComplet() << std::endl;
        fout << "Programare: " << ultimaProgramare.GetProgramare() << std::endl;
        fout << "-----------------------------" << std::endl;
        fout.close();
        std::cout << "Ultima programare inregistrata a fost salvata in fisierul " << numeFisier << std::endl;
    } else {
        std::cout << "Eroare la deschiderea fisierului: " << numeFisier << std::endl;
    }
}

void Programare::AfiseazaProgramariDinFisier(const std::string& numeFisier) {
    std::ifstream fisier(numeFisier);
    if (fisier.is_open()) {
        std::string line;
        while (std::getline(fisier, line)) {
            std::cout << line << std::endl;
        }
        fisier.close();
        std::cout << "Programarile au fost incarcate din fisierul " << numeFisier << std::endl;
    } else {
        std::cout << "Eroare la deschiderea fisierului: " << numeFisier << std::endl;
    }
}

void Programare::StergeUltimaProgramareInregistrata() {
    if (programari.empty()) {
        std::cout << "Nu exista programari inregistrate." << std::endl;
        return;
    }

    programari.pop_back();
    std::cout << "Ultima programare inregistrata a fost stearsa." << std::endl;
}

void Programare::StergeUltimaProgramareDinFisier(const std::string& numeFisier) {
    std::ifstream fisier(numeFisier);
    if (fisier.is_open()) {
        std::vector<std::string> liniiFisier;
        std::string line;
        while (std::getline(fisier, line)) {
            liniiFisier.push_back(line);
        }
        fisier.close();

        if (liniiFisier.empty()) {
            std::cout << "Nu exista programari inregistrate in fisierul " << numeFisier << std::endl;
            return;
        }

        liniiFisier.pop_back();

        std::ofstream fout(numeFisier);
        if (fout.is_open()) {
            for (const auto& linie : liniiFisier) {
                fout << linie << std::endl;
            }
            fout.close();
            std::cout << "Ultima programare inregistrata a fost stearsa din fisierul " << numeFisier << std::endl;
        } else {
            std::cout << "Eroare la deschiderea fisierului: " << numeFisier << std::endl;
        }
    } else {
        std::cout << "Eroare la deschiderea fisierului: " << numeFisier << std::endl;
    }
}
