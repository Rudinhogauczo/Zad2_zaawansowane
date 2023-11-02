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
};