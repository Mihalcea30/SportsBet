//
// Created by Home on 6/17/2023.
//
#include "Pariu_goluri.h"
#include "Pariu.h"

Pariu_Goluri ::Pariu_Goluri(int scor1_, int scor2_, int suma_, std :: string const &bet_, Meci const &M_,
                            float cotaSub4_, float cotaPeste4_, float cotaPrimaSub2_, float cotaPrimaPeste2_) :
                            Pariu(scor1_, scor2_, suma_, bet_, M_), cotaSub4(cotaSub4_), cotaPeste4(cotaPeste4_),
                            cotaPrimaSub2(cotaPrimaSub2_), cotaPrimaPeste2(cotaPrimaPeste2_) {
    //std::cout << "Constructor";
};
std :: string Pariu_Goluri :: getbet() const { return bet; }
Meci Pariu_Goluri :: getM() const { return M; }
float Pariu_Goluri:: getcastigSub4() const { return suma * cotaSub4; }
float Pariu_Goluri:: getcastigPeste4() const { return suma * cotaPeste4; }
float Pariu_Goluri::getcastigPrimaSub2() const { return suma * cotaPrimaSub2; }
float Pariu_Goluri::getcastigPrimaPeste2() const { return suma * cotaPrimaPeste2; }


void Pariu_Goluri ::AfisPariu(){

    std::cout <<"Meciul dintre " << getM().getechip1() << " si "
              << getM().getechip2() << " s-a terminat cu scorul " << getM().getscor1() << "-"
              << getM().getscor2() << "\n";
    std::cout << "Ati pariat ca ";
    if(getbet() == "TMin4")
        std::cout <<"se inscriu cel putin 4 goluri in total\n";
    else if(getbet() == "TMax4")
        std::cout <<"se inscriu cel mult 4 goluri in total\n";
    else if(getbet() == "PMin2")
        std::cout <<"prima echipa inscrie cel putin 2 goluri\n";
    else if(getbet() == "PMax2")
        std::cout <<"prima echipa inscrie cel mult 2 goluri\n";

};
float Pariu_Goluri ::CastigPariu() {
    if(getbet() == "TMin4" && scor1 + scor2 >= 4)
        return getcastigPeste4();
    else if(getbet() == "TMax4" && scor1 + scor2 <= 4)
        return getcastigSub4();
    else if(getbet() == "PMin2" && scor1 >= 2)
        return getcastigPrimaPeste2();
    else if(getbet() == "PMax2" && scor1 <= 2)
        return getcastigPrimaSub2();
    else return 0;
}

