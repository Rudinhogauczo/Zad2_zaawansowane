#include "Klasy1.h"
#ifndef Klasy2
#define Klasy2
class ZapisOdczytDrzewa {
public:
 
    static void ZapiszDoPliku(DrzewoBST& drzewo, const std::string& nazwaPliku) {
        std::ofstream plik(nazwaPliku, std::ios::binary);
        if (plik.is_open()) {
            ZapiszDrzewoDoPliku(drzewo.PobierzKorzen(), plik);
            plik.close();
            std::cout << "Drzewo zostało zapisane do pliku '" << nazwaPliku << "'." << std::endl;
        } else {
            std::cerr << "Błąd podczas otwierania pliku do zapisu." << std::endl;
        }
    }

};

#endif