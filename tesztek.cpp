//
// Created by borosboyo on 2020. 05. 15..
//
#include "sportegyesulet.h"
#include "stringek.h"
using namespace std;

//Új csapat funkcióját teszteli, amely mindhárom sportág esetében ugyanaz
void tesztUjCsapat(Sportegyesulet &s) {
    s.funkcioUjCsapat();
}

//Egy adott sportág csapatainak listázását teszteli
void tesztSportagListaz(Sportegyesulet &s){
    s.funkcioListazas();
}

//A Sportegyesület összes csapatának listázását teszteli
void tesztOsszesListaz(Sportegyesulet &s){
    s.funkcioListazas();
}

//Egy megadott nevű és sportágú csapatot töröl tesztje
void tesztAdottCsapatTorol(Sportegyesulet &s) {
    s.funkcioTorol();
}

//Kitörli a Sportegyesület összes csapatát
void tesztOsszesCsapatTorol(Sportegyesulet &s){
    s.funkcioTorol();
}

//Maga a tesztprogram gerince
bool tesztVezerles (Sportegyesulet &s){
    int valasz;
    cout << "Adja meg a teszteset sorszama: ";
    cin >> valasz;
    switch(valasz){
        case 0:
            return true;
        case 1:
            tesztUjCsapat(s);
            break;
        case 2:
            tesztSportagListaz(s);
            break;
        case 3:
            tesztOsszesListaz(s);
            break;
        case 4:
            tesztAdottCsapatTorol(s);
            break;
        case 5:
            tesztOsszesCsapatTorol(s);
            break;
        default:
            cout << "Hibas bemenet" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            return false;
    }
}
