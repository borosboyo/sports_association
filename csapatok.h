
#ifndef CSAPATOK_H
#define CSAPATOK_H

#include "stringek.h"
#include <iostream>
#include <fstream>

//Csapat osztály, melyből más sportágakat is származtathatunk
class Csapat {
    String nev;
    unsigned int alapletszam;

public:
    Csapat() {}
    Csapat(String ujnev, unsigned int ujletszam) : nev(ujnev), alapletszam(ujletszam){ }
    const String getNev() const { return nev; }
    const unsigned int getAlapletszam() const { return alapletszam; }
    virtual ~Csapat() { }
};

class Labdarugas : public Csapat {
    unsigned int edzok = 2;
public:
    Labdarugas(String ujnev, unsigned int ujletszam, unsigned int ujedzok, std::fstream &adatbazis)
    : Csapat(ujnev, ujletszam), edzok(ujedzok) {}
    Labdarugas(String ujnev, unsigned int ujletszam, unsigned int ujedzok) : Csapat(ujnev, ujletszam), edzok(ujedzok) {
        std::ofstream adatbazis;
        adatbazis.open("adatbazis.txt", std::ios_base::app);
        adatbazis << "Labdarugas " << getNev() << " " << getAlapletszam() << " "  << edzok << std::endl;
        adatbazis.close();
    }
    //Csapat* clone() { return new Labdarugas(*this); }
    ~Labdarugas() {}
};


class Kezilabda : public Csapat {
    unsigned int tamogatas;
public:
    Kezilabda(String knev, unsigned int ujletszam, unsigned int ujtam, std::fstream &adatbazis)
    : Csapat(knev, ujletszam), tamogatas(ujtam) {}
    Kezilabda(String knev, unsigned int ujletszam, unsigned int ujtam) : Csapat(knev, ujletszam), tamogatas(ujtam) {
        std::ofstream adatbazis;
        adatbazis.open("adatbazis.txt", std::ios_base::app);
        adatbazis << "Kezilabda " << getNev() << " " << getAlapletszam() << " "  << tamogatas << std::endl;
        adatbazis.close();
    }
    //Csapat* clone() { return new Kezilabda(*this); }
    ~Kezilabda() {}
};

class Kosarlabda : public Csapat {
    unsigned int pompom;
public:
    Kosarlabda(String ujnev, unsigned int ujletszam, unsigned int ujpp, std::fstream &adatbazis)
    : Csapat(ujnev, ujletszam), pompom(ujpp) {}
    Kosarlabda(String ujnev, unsigned int ujletszam, unsigned int ujpp) : Csapat(ujnev, ujletszam), pompom(ujpp) {
        std::ofstream adatbazis;
        adatbazis.open("adatbazis.txt", std::ios_base::app);
        adatbazis << "Kosarlabda " << getNev() << " " << getAlapletszam() << " "  << pompom << std::endl;
        adatbazis.close();
    }
    //Csapat* clone() { return new Kosarlabda(*this); }
    ~Kosarlabda() {}
};



#endif // CSAPATOK_H
