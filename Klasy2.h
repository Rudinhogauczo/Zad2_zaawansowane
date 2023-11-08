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

    static DrzewoBST OdczytajZPliku(const std::string& nazwaPliku) {
        DrzewoBST drzewo;
        std::ifstream plik(nazwaPliku, std::ios::binary);
        if (plik.is_open()) {
            drzewo.UstawKorzen(OdczytajDrzewoZPliku(plik));
            plik.close();
            std::cout << "Drzewo zostało odczytane z pliku '" << nazwaPliku << "'." << std::endl;
        } else {
            std::cerr << "Błąd podczas otwierania pliku do odczytu." << std::endl;
        }
        return drzewo;
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

    static DrzewoBST::Wezel* OdczytajDrzewoZPliku(std::istream& strumien) {
        int klucz;
        strumien.read(reinterpret_cast<char*>(&klucz), sizeof(klucz));
        if (strumien.eof()) {
            return nullptr;
        }
        DrzewoBST::Wezel* wezel = new DrzewoBST::Wezel(klucz);
        wezel->lewy = OdczytajDrzewoZPliku(strumien);
        wezel->prawy = OdczytajDrzewoZPliku(strumien);
        return wezel;
    }

};

#endif