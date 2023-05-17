
#ifndef OOP_PARIU_H
#define OOP_PARIU_H
#include "Meci.h"

class Pariu{
    std::string bet;
    Meci M;
    float cota1, cota2, cotaegal;
    int suma;
public:
    Pariu(std::string bet_, const Meci &M_, float cota1_, float cota2_, float cotaegal_, int suma_);
    Pariu(const Pariu &other);
    friend std::ostream& operator<<(std::ostream& os, const Pariu& p);
    ~Pariu();
    std::string getbet() const;
    Meci getM() const;
    /*float getcota1() const { return cota1; }
    float getcota2() const { return cota2; }
    float getcotaegal() const { return cotaegal; }
    float getsuma() const { return suma; }*/
    float getcastig1() const;
    float getcastig2() const;
    float getcastigegal() const;
    bool castigat() const;

};
#endif //OOP_PARIU_H
