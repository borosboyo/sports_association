#include <iostream>
#include <cstring>
#include "sportegyesulet.h"
#include "stringek.h"
using namespace std;

Sportegyesulet &Sportegyesulet::operator=(const Sportegyesulet &s) {
    if( this != &s){
        delete [] nyilvantartas;
        csapatokSzama = s.csapatokSzama;
        nyilvantartas = new Csapat[csapatokSzama];
        for(unsigned int ii = 0; ii < csapatokSzama; ii++)
            nyilvantartas[ii] = s.nyilvantartas[ii];
    }
    return *this;
}

/* Esetleges konstruktor ha szükség lenne rá.
Sportegyesulet::Sportegyesulet(const Sportegyesulet &s) {
    csapatokSzama = 0;
    *this = s;
}
*/
Csapat& Sportegyesulet::operator[](unsigned int ii) {
    if(ii >= csapatokSzama || ii < 0){
        throw "Index hiba";
    }
    return nyilvantartas[ii];
}

const Csapat Sportegyesulet::operator[](unsigned int ii) const {
    if(ii >= csapatokSzama || ii < 0){
        throw "Index hiba";
    }
    return nyilvantartas[ii];
}

void Sportegyesulet::csapatOsszesTorol() {
    delete [] nyilvantartas;
    csapatokSzama = 0;
}
//Wipeolja a txt-t
void Sportegyesulet::csapatFajlbolOsszesTorol() {
    std::ofstream adatbazis;
    adatbazis.open("adatbazis.txt",std::ofstream::trunc);
    adatbazis.close();
}

//A nyilvantartas tömb végéhez ad egy elemet
void Sportegyesulet::csapatHozzafuz(const Csapat &cs) {
    Csapat *tmp = new Csapat[csapatokSzama+1];
    for(int ii = 0; ii < this->csapatokSzama; ii++){
        tmp[ii] = nyilvantartas[ii];
    }
    csapatokSzama++;
    delete [] nyilvantartas;
    nyilvantartas = tmp;
    nyilvantartas[csapatokSzama-1] = cs;
}

//Sportágat lehet vele választani név alapján
int Sportegyesulet::sportagAzonosit(String &sportag){
    int valasz = 0;
    if(strcmp(sportag.getpData(),"Labdarugas") == 0){
        valasz = 1;
    }
    else if(strcmp(sportag.getpData(),"Kezilabda") == 0){
        valasz = 2;
    }
    else if(strcmp(sportag.getpData(),"Kosarlabda") == 0){
        valasz = 3;
    }
    return valasz;
}

// beolvassa és felépíti a Sportegyesulet nyilvantartas tömbjét a txtből. Legfőbb függvénye a programnak
void Sportegyesulet::adatbazisFelepit(){
    fstream adatbazis("adatbazis.txt",  ios::in|ios:: out);
    String sportag, nev;
    int valasz;
    unsigned int letszam, kulonleges;
    if(adatbazis.is_open()){
        while(!adatbazis.eof()){
            adatbazis >> sportag >> nev >> letszam >> kulonleges;
            valasz = sportagAzonosit(sportag);
            switch(valasz) {
                case 1:
                    csapatHozzafuz(Labdarugas(nev,letszam,kulonleges,adatbazis));
                    break;
                case 2:
                    csapatHozzafuz(Kezilabda(nev,letszam,kulonleges,adatbazis));
                    break;
                case 3:
                    csapatHozzafuz(Kosarlabda(nev,letszam,kulonleges,adatbazis));
                    break;
                default:
                    return;
            }
        }
        adatbazis.close();
    }
    else{
        cout << "A fajl megnyitasa nem sikerult";
    }
}

//A txtben található csapatokat írja ki
void csapatFajlbolKiir() {
    ifstream adatbazis("adatbazis.txt");
    String sportag, nev;
    unsigned int letszam, kulonleges;
    if(adatbazis.is_open()){
        while(adatbazis >> sportag >> nev >> letszam >> kulonleges){
            cout << sportag << " " << nev << " " << letszam << " " << kulonleges << endl;
        }
        adatbazis.close();
    }
    else{
        cout << "A fajl megnyitasa nem sikerult";
    }
}


//Kiírja a txtben található összes csapatot
void csapatAdottSportagKiir(String &keres) {
    ifstream adatbazis("adatbazis.txt");
    String sportag, nev;
    unsigned int letszam, kulonleges;
    if(adatbazis.is_open()){
        while(!adatbazis.eof()){
            if(adatbazis >> sportag >> nev >> letszam >> kulonleges && (strcmp(keres.getpData(),sportag.getpData()) == 0))
                cout << nev << " " << letszam << " " << kulonleges << endl;
        }
        adatbazis.close();
    }
    else{
        cout << "A fajl megnyitasa nem sikerult";
    }
}

//Meghatározza mit választott a felhasználó
void Sportegyesulet::funkcioValasztas(int &valasz){
    switch(valasz){
        case 1:
            funkcioUjCsapat();
            break;
        case 2:
            funkcioTorol();
            break;
        case 3:
            funkcioListazas();
            break;
        default:
            return;
    }
}

bool csapatEgyezes(String &knev, const char* ksportag){
    String nev, sportag;
    ifstream adatbazis("adatbazis.txt");
    if(adatbazis.is_open()){
        while(!adatbazis.eof()){
            adatbazis >> sportag >> nev;
            if(strcmp(sportag.getpData(),ksportag) == 0 & strcmp(knev.getpData(),nev.getpData()) == 0){
                cout << "Mar letezik ilyen nevu csapat az adott sportagban!" << endl;
                return true;
            }
        }
        adatbazis.close();
    }
    else{
        cout << "A fajl megnyitasa nem sikerult";
    }
    return false;
}

void Sportegyesulet::csapatSatiroz(String &knev, const char* ksportag){
    ifstream adatbazis("adatbazis.txt");
    ofstream tmp("tmp.txt", std::ios_base::app);
    String sportag, nev;
    unsigned int letszam, kulonleges;
    if(adatbazis.is_open() && tmp.is_open()){
        while(adatbazis >> sportag >> nev >> letszam >> kulonleges){
            if(strcmp(sportag.getpData(),ksportag) == 0 & strcmp(knev.getpData(),nev.getpData()) == 0){
            }
            else{
                tmp << sportag << " " << nev << " " << letszam << " "<< kulonleges << endl;
            }
        }
        adatbazis.close();
        tmp.close();
    }
    else{
        cout << "A fajl megnyitasa nem sikerult";
    }
    remove("adatbazis.txt");
    rename("tmp.txt","adatbazis.txt");
}

//Csapat felvétele funkció
void Sportegyesulet::funkcioUjCsapat() {
    int valasz;
    cout << "Menupontok:" << endl;
    cout << "(1) Labdarugas csapat felvetele" << endl;
    cout << "(2) Kezilabda csapat felvetele" << endl;
    cout << "(3) Kosarlabda csapat felvetele" << endl;
    cout << "(4) Vissza a fomenube " << endl;
    cout << "Valasztas: ";
    cin >> valasz;
    funkcioEllenoriz(valasz);
    return;
}

void Sportegyesulet::funkcioEllenoriz(int& valasz){
    String csapatnev;
    unsigned int letszam;
    if (valasz >= 1 && valasz <= 3) {
        cout << "Csapat neve: ";
        cin >> csapatnev;
        cout << "Csapat letszama: ";
        cin >> letszam;
        switch (valasz) {
            case 1:
                if(!csapatEgyezes(csapatnev, "Labdarugas")) {
                    labdarugasFelvesz(csapatnev, letszam);
                    return;
                }else
                    return;
            case 2:
                if(!csapatEgyezes(csapatnev, "Kezilabda")){
                    kezilabdaFelvesz(csapatnev, letszam);
                    return;
                }else
                    return;
            case 3:
                if(!csapatEgyezes(csapatnev, "Kosarlabda")) {
                    kosarlabdaFelvesz(csapatnev, letszam);
                    return;
                }else
                    return;
        }
    } else if (valasz == 4)
        return;
    else {
        cout << "Hibas bemenet" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }
}

const char* sportagKivalasztSatiroz(){
    int valasz;
    cout << "Menupontok:" << endl;
    cout << "(1) Labdarugas csapat torlese" << endl;
    cout << "(2) Kezilabda csapat torlese" << endl;
    cout << "(3) Kosarlabda csapat torlese" << endl;
    cout << "(4) Vissza a fomenube " << endl;
    cout << "Valasztas: ";
    cin >> valasz;
    switch(valasz){
        case 1:
            return "Labdarugas";
        case 2:
            return "Kezilabda";
        case 3:
            return "Kosarlabda";
        case 4:
            break;
        default:
            cout << "Hibas bemenet" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            break;
    }
}

//Törlés funkció
void Sportegyesulet::funkcioTorol() {
    if (csapatokSzama == 0){
        cout << "Nincsenek csapatok!" << endl;
        return;
    }
    else{
        int valasz;
        cout << "Menupontok:" << endl;
        cout << "(1) Egy csapat torlese" << endl;
        cout << "(2) Osszes csapat torlese" << endl;
        cout << "(3) Vissza a fomenube " << endl;
        cout << "Valasztas:";
        cin >> valasz;
        String torlendo;
        switch(valasz){
            case 1:
                cout << "Torlendo csapat neve: ";
                cin >> torlendo;
                csapatSatiroz(torlendo,sportagKivalasztSatiroz());
                adatbazisFelepit();
                cout << "Csapat törölve!" << endl;
                break;
            case 2:
                csapatOsszesTorol();
                csapatFajlbolOsszesTorol();
                cout << "Osszes csapat torolve!" << endl;
                break;
            case 3:
                return;
            default:
                cout << "Hibas bemenet" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                return;
        }
    }
}


void Sportegyesulet::labdarugasFelvesz(String &csapatnev, unsigned int letszam){
    cout << "Edzok szama: 2" << endl;
    this->csapatHozzafuz(Labdarugas(csapatnev,letszam,2));
    cout << "Csapat letrehozva!" << endl;
    cout << "Nev: " << csapatnev << " " << "Letszam: " << letszam << " " << "Edzok: " << 2 << endl;
}

void Sportegyesulet::kezilabdaFelvesz(String &csapatnev, unsigned int letszam){
    unsigned int tamogatas;
    cout << "Tamogatas osszege: ";
    cin >> tamogatas;
    this->csapatHozzafuz(Kezilabda(csapatnev,letszam,tamogatas));
    cout << "Csapat letrehozva!" << endl;
    cout << "Nev: " << csapatnev << " " << "Letszam: " << letszam << " " << "Tamogatas: " << tamogatas << endl;
}

void Sportegyesulet::kosarlabdaFelvesz(String &csapatnev, unsigned int letszam){
    unsigned int pompom;
    cout << "Pompom lányok: ";
    cin >> pompom;
    this->csapatHozzafuz(Kosarlabda(csapatnev,letszam,pompom));
    cout << "Csapat letrehozva!" << endl;
    cout << "Nev: " << csapatnev << " " << "Letszam: " << letszam << " " << "Pompom lanyok: " << pompom << endl;
}

//A listázás funkció mindenféle kezelésére
void Sportegyesulet::funkcioListazas(){
    int valasz;
    String keres;
    cout << "Menupontok:" << endl;
    cout << "(1) Labdarugas csapatok listazasa" << endl;
    cout << "(2) Kezilabda csapatok listazasa" << endl;
    cout << "(3) Kosarlabda csapatok listazasa" << endl;
    cout << "(4) Osszes csapat listazasa" << endl;
    cout << "(5) Vissza a fomenube " << endl;
    cout << "Valasztas: ";
    cin >> valasz;
    switch(valasz){
        case 1:
            keres = "Labdarugas";
            csapatAdottSportagKiir(keres);
            break;
        case 2:
            keres = "Kezilabda";
            csapatAdottSportagKiir(keres);
            break;
        case 3:
            keres = "Kosarlabda";
            csapatAdottSportagKiir(keres);
            break;
        case 4:
            csapatFajlbolKiir();
            break;
        case 5:
            return;
        default:
            cout << "Hibas bemenet" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            return;
    }
}

//Az inicializálás kezelésére szolgál
bool Sportegyesulet::inic(){
    int valasz;
    cout << "Menupontok:" << endl;
    cout << "(1) Uj csapat felvetele" << endl;
    cout << "(2) Csapat torlese" << endl;
    cout << "(3) Listazas" << endl;
    cout << "(4) Kilepes" << endl;
    cout << "Valasztas: ";
    cin >> valasz;

    if (valasz >= 1 && valasz <= 3){
        funkcioValasztas(valasz);
    }
    else if(valasz == 4){
        cout << "A program kilep.";
        return true;
    }
    else{
        cout << "Hibas bemenet" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return false;
    }
}





