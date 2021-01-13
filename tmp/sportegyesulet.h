
#ifndef SPORTEGYESULET_H
#define SPORTEGYESULET_H

#include "csapatok.h"
//Kicsit sok egyelőre a felesleges függvény, melyek valószínűleg a végleges programban nem lesznek benne,
//de elkészítettem őket, mert lehet lesz valamelyikre szükség.

class Sportegyesulet  {
    unsigned int csapatokSzama;
    Csapat* nyilvantartas;
public:
    Sportegyesulet(unsigned int csapatokSzama = 0) : csapatokSzama(csapatokSzama), nyilvantartas( new Csapat[csapatokSzama] ) { }
    //Sportegyesulet(const Sportegyesulet&s);
    ~Sportegyesulet() { csapatokSzama = 0; delete [] nyilvantartas; }

    Sportegyesulet& operator=(const Sportegyesulet &s);
    Csapat &operator[](unsigned int ii);
    const Csapat operator[](unsigned int ii) const;

    int sportagAzonosit(String &sportag);
    void adatbazisFelepit();

    void csapatHozzafuz(const Csapat &cs);
    void csapatOsszesTorol();
    void csapatFajlbolOsszesTorol();

    void funkcioEllenoriz(int& valasz);
    void csapatSatiroz(String &knev, const char* ksportag);
    void labdarugasFelvesz(String& csapatnev, unsigned int letszam);
    void kezilabdaFelvesz(String& csapatnev, unsigned int letszam);
    void kosarlabdaFelvesz(String& csapatnev, unsigned int letszam);
    void funkcioValasztas(int &valasz);
    void funkcioUjCsapat();
    void funkcioTorol();
    void funkcioListazas();
    bool inic();
};

bool csapatEgyezes(String &knev, const char* ksportag);
void csapatFajlbolKiir();
void csapatAdottSportagKiir(String &keres);
const char* sportagKivalasztSatiroz();
#endif // SPORTEGYESULET_H
