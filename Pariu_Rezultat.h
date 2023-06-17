//
// Created by Home on 5/20/2023.
//

#ifndef OOP_PARIU_REZULTAT_H
#define OOP_PARIU_REZULTAT_H
#include "Pariu.h"

class Pariu_Rezultat : public Pariu{
private:
    float cota1, cota2, cotaegal;
public:

    Pariu_Rezultat(int scor1_, int scor2_, int suma_, std :: string const &bet_, Meci const&M_, float cota1_, float cota2_, float cotaegal_);
    ///void getCastig() const override;
    std::string getbet() const;
    Meci getM() const;
    float getcastig1() const;
    float getcastig2() const;
    float getcastigegal() const;
    bool castigat() const;
    void AfisPariu() override;
    float CastigPariu() override;
};
#endif //OOP_PARIU_REZULTAT_H
