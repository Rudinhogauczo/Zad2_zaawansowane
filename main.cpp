#include <iostream>
#include <fstream>
#include "Klasy1.h"
int main() {
    DrzewoBST drzewo;
    int opcja;
    int klucz;
 
    while (true) {
        std::cout << std::endl;
 
        std::cout << "Menu Drzewa BST:" << std::endl;
        std::cout << "1. Dodaj element" << std::endl;
        std::cout << "2. Usun element" << std::endl;
        std::cout << "0. Wyjscie" << std::endl;
        std::cout << "Wybierz opcje: ";
        std::cin >> opcja;
        std::cout << std::endl;
 
        switch (opcja) {
            case 1:
                std::cout << "Podaj klucz elementu do dodania: ";
                std::cin >> klucz;
                drzewo.DodajElement(klucz);
                break;
            case 2:
                std::cout << "Podaj klucz elementu do usuniecia: ";
                std::cin >> klucz;
                drzewo.UsunElement(klucz);
                break;
            case 0:
                std::cout << "Wyjscie z programu." << std::endl;
                return 0; 
            default:
                std::cout << "Nieprawidlowa opcja. Sprobuj ponownie." << std::endl;
        }
    }
 
    return 0;
}