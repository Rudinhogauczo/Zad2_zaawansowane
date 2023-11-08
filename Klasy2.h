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

private:
    static void ZapiszDrzewoDoPliku(DrzewoBST::Wezel* wezel, std::ostream& strumien) {
        if (wezel == nullptr) {
            return;
        }
        strumien.write(reinterpret_cast<const char*>(&wezel->klucz), sizeof(wezel->klucz));
        ZapiszDrzewoDoPliku(wezel->lewy, strumien);
        ZapiszDrzewoDoPliku(wezel->prawy, strumien);
    }

};

#endif