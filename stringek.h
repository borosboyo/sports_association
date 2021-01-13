//
// Created by borosboyo on 2020. 04. 19..
//

#ifndef STRINGEK_H
#define STRINGEK_H
#include <iostream>

// AZ EGÉSZ STRING OSZTÁLY A JPORTÁN BEADOTT SAJÁT 5. LABOR ALAPJÁN ELKÉSZÍTVE OPERATOR OVERLOADINGAL

class String {
    char *pData;
    size_t len;
public:
    size_t size() const { return len; }
    String() :pData(0), len(0) {}
    const char* c_str() const { if (pData) return pData; else return "";}
    String(char ch);
    String(const char *p);
    String(const String& s1);
    void createString(const char *p);
    char *getpData() {  return pData; }
    ~String() { delete[] pData; }
    void printDbg(const char *txt = "") const {
        std::cout << txt << "[" << len << "], "
                  << (pData ? pData : "(NULL)") << std::endl;
    }
    String& operator=(const String& rhs_s);
    String& operator+=(const String& rhs_s) {
        *this = *this + rhs_s;
        return *this;
    }
    String operator+(const String& rhs_s) const ;
    String operator+(char rhs_c) const { return *this + String(rhs_c);}
    char& operator[](unsigned int idx);
    const char& operator[](unsigned int idx) const;
};

std::ostream& operator<<(std::ostream& os, const String& s0);
std::istream& operator>>(std::istream& is, String& s0);
inline String operator+(char ch, const String& str) { return String(ch) + str; }

#endif //STRINGEK_H
