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
            int klucz;
            while (plik.read(reinterpret_cast<char*>(&klucz), sizeof(klucz))) {
                drzewo.DodajElement(klucz);
            }
            plik.close();
            std::cout << "Drzewo zostało odczytane z pliku '" << nazwaPliku << "'." << std::endl;
        } else {
            std::cerr << "Błąd podczas otwierania pliku do odczytu." << std::endl;
        }
        return drzewo;
    }

    static void WczytajPlikTekstowy(const std::string& nazwaPliku, DrzewoBST& drzewo) {
        std::ifstream plik(nazwaPliku);
        if (plik.is_open()) {
            int liczba;
            while (plik >> liczba) {
                drzewo.DodajElement(liczba);
            }
            plik.close();
            std::cout << "Liczby zostały wczytane z pliku tekstowego '" << nazwaPliku << "'." << std::endl;
        } else {
            std::cerr << "Błąd podczas otwierania pliku tekstowego do odczytu." << std::endl;
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