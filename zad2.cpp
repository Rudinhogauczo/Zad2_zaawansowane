#include <iostream>
 
class DrzewoBST {
public:
    struct Wezel {
        int klucz;
        Wezel* lewy;
        Wezel* prawy;
        Wezel(int k) : klucz(k), lewy(nullptr), prawy(nullptr) {}
    };
};