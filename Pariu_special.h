//
// Created by Home on 6/20/2023.
//

#ifndef OOP_PARIU_SPECIAL_H
#define OOP_PARIU_SPECIAL_H
#include "Meci.h"
template <typename T>
class PariuSpecial{
    T cotaScorExact, cotaAmbeleMarcheaza;
    int scor1, scor2;
    int suma;
    std :: string bet;
    Meci M;
public:
    PariuSpecial(T cotaScorExact_, T cotaAmbeleMarcheaza_, int scor1_, int scor2_, int suma_, std :: string const &bet_, Meci const &M_) :
            cotaScorExact(cotaScorExact_), cotaAmbeleMarcheaza(cotaAmbeleMarcheaza_), scor1(scor1_), scor2(scor2_), suma(suma_), bet(bet_), M(M_) {}
    T getCastigScorExact() const { return suma * cotaScorExact; }
    T getCastigAmbeleMarcheaza() const { return suma * cotaAmbeleMarcheaza; }
    void AfisPariu(){

        std::cout <<"Meciul dintre " << M.getechip1() << " si "
                  << M.getechip2() << " s-a terminat cu scorul " << M.getscor1() << "-"
                  << M.getscor2() << "\n";
        std::cout << "Ati pariat ca ";
        if(bet == "Ambele")
            std::cout <<"ambele echipe marcheaza\n";
        else if(bet == "ScorExact")
            std::cout <<"scorul final este " << scor1 << "-" << scor2 << "\n";

    };
    T CastigPariu() {
        if(bet[0] - '0' == scor1 && bet[1] - '0' == scor2)
            return getCastigScorExact();
        else if(bet == "Ambele" && scor1 * scor2 > 0)
            return getCastigAmbeleMarcheaza();
        else return 0;
    }

};

#endif //OOP_PARIU_SPECIAL_H