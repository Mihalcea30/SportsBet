//
// Created by Home on 5/20/2023.
//

#ifndef OOP_PARIU_REZULTAT_H
#define OOP_PARIU_REZULTAT_H
#include "Pariu.h"

class Pariu_Rezultat : public Pariu{
private:
    int scor1, scor2;
    float cota1, cota2, cotaegal;
    int suma;
    std :: string bet;
    Meci M;
public:

    Pariu_Rezultat(std::string const  &bet_, Meci const &M_, float cota1_, float cota2_, float cotaegal_, int Suma_);
    Pariu* clone() const override;
    void getCastig() const override;
    std::string getbet() const;
    Meci getM() const;
    float getcastig1() const;
    float getcastig2() const;
    float getcastigegal() const;
    bool castigat() const;
};
#endif //OOP_PARIU_REZULTAT_H
