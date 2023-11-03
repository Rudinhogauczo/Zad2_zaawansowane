#include <iostream>
 
class DrzewoBST {
public:
    struct Wezel {
        int klucz;
        Wezel* lewy;
        Wezel* prawy;
        Wezel(int k) : klucz(k), lewy(nullptr), prawy(nullptr) {}
    };
Wezel* korzen;
    DrzewoBST() : korzen(nullptr) {}
 
    // Dodaje element o podanym kluczu do drzewa BST.
    void DodajElement(int klucz) {
        korzen = DodajRekurencyjnie(korzen, klucz);
    }
// Funkcja pomocnicza dla DodajElement do dodawania rekurencyjnie.
    Wezel* DodajRekurencyjnie(Wezel* wezel, int klucz) {
        if (wezel == nullptr) {
            return new Wezel(klucz);
        }
        if (klucz < wezel->klucz) {
            wezel->lewy = DodajRekurencyjnie(wezel->lewy, klucz);
        } else if (klucz > wezel->klucz) {
            wezel->prawy = DodajRekurencyjnie(wezel->prawy, klucz);
        }
        return wezel;
    }

};