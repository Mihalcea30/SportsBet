//
// Created by Home on 6/17/2023.
//

#ifndef OOP_PARIU_GOLURI_H
#define OOP_PARIU_GOLURI_H

#include "Pariu.h"

class Pariu_Goluri : public Pariu{
private:
    float cotaSub4, cotaPeste4, cotaPrimaSub2, cotaPrimaPeste2;
public:

    Pariu_Goluri(int scor1_, int scor2_, int suma_, std :: string bet_, Meci M_,
                 float cotaSub4_, float cotaPeste4_, float cotaPrimaSub2_, float cotaPrimaPeste2_);
    ///void getCastig() const override;
    std::string getbet() const;
    Meci getM() const;
    float getcastigSub4() const;
    float getcastigPeste4() const;
    float getcastigPrimaSub2() const;
    float getcastigPrimaPeste2() const;
    bool castigat() const;
    void AfisPariu() override;
    float CastigPariu() override;
};
#endif //OOP_PARIU_GOLURI_H
