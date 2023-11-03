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

 // Usuwa element o podanym kluczu z drzewa BST.
    void UsunElement(int klucz) {
        korzen = UsunRekurencyjnie(korzen, klucz);
    }
 
    // Funkcja pomocnicza dla UsunElement do usuwania rekurencyjnie.
    Wezel* UsunRekurencyjnie(Wezel* wezel, int klucz) {
        if (wezel == nullptr) {
            return wezel;
        }
        if (klucz < wezel->klucz) {
            wezel->lewy = UsunRekurencyjnie(wezel->lewy, klucz);
        } else if (klucz > wezel->klucz) {
            wezel->prawy = UsunRekurencyjnie(wezel->prawy, klucz);
        } else {
            if (wezel->lewy == nullptr) {
                Wezel* temp = wezel->prawy;
                delete wezel;
                return temp;
            } else if (wezel->prawy == nullptr) {
                Wezel* temp = wezel->lewy;
                delete wezel;
                return temp;
            }
            Wezel* temp = NajmniejszyWezel(wezel->prawy);
            wezel->klucz = temp->klucz;
            wezel->prawy = UsunRekurencyjnie(wezel->prawy, temp->klucz);
        }
        return wezel;
    }
// Znajduje najmniejszy element w drzewie.
    Wezel* NajmniejszyWezel(Wezel* wezel) {
        Wezel* aktualny = wezel;
        while (aktualny->lewy != nullptr) {
            aktualny = aktualny->lewy;
        }
        return aktualny;
    }
};