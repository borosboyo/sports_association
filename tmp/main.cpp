#include <iostream>
#include "sportegyesulet.h"
#include "tesztek.h"
#include "memtrace.h"
//Main függvényben egyelőre csak tesztek találhatóak
//Az egyes modulokban nincsenek elhelyezve teljesen kommentek továbbá
//rendetlenül vannak deklarálva és definiálva a függvények.
//Végleges leadásban ezek javításra kerülnek.
//A tesztfüggvények egyelőre ebbe a modulban kerülnek
using namespace std;

int main(){
    bool kilepes = false;
    int valasz;
    Sportegyesulet Fitt;
    Fitt.adatbazisFelepit();
    while(!kilepes){
        cout << "Menüpontok:" << endl;
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