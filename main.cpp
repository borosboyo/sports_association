#include <iostream>
#include "sportegyesulet.h"
#include "tesztek.h"
#include "memtrace.h"
using namespace std;

int main(){
    /*
    /// Jporta std in szimuláció
#ifdef JPORTA_INPUT_SIM
    // Ha definiált, akkor a standard_input.txt nevű fájlból veszi az inputot.
    // Ez az a fájl, amit a Jporta rendszerbe a minta feladatban feltöltünk mint std. in.
    std::ifstream in("standard_input.txt");
    std::cin.rdbuf(in.rdbuf());     // cin mostantól az in-ből olvas
#endif // JPORTASIM
    */

    bool kilepes = false;
    int valasz;
    Sportegyesulet Fitt;
    Fitt.adatbazisFelepit(); //A korábbi csapatokat beolvassa a txtből, hogy azok is kezelhetőek legyenek
    while(!kilepes){
        cout << "Menupontok:" << endl;
        cout << "(1) Tesztprogram" << endl;
        cout << "(2) Sajat vezerles" << endl;
        cout << "(3) Kilepes" << endl;
        cout << "Valasz: ";
        cin >> valasz;
        switch(valasz){
            case 1:
                if(tesztVezerles(Fitt) == true)
                    kilepes = true;
                break;
            case 2:
                if(Fitt.inic() == true)
                    kilepes = true;
                break;
            case 3:
                kilepes = true;
                break;
        }
    }
    return 0;
}