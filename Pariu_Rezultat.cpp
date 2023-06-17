#include "Pariu_Rezultat.h"
#include "Pariu.h"

Pariu_Rezultat ::Pariu_Rezultat(int scor1_, int scor2_, int suma_, std :: string const &bet_, Meci const &M_, float cota1_, float cota2_, float cotaegal_) :
        Pariu(scor1_, scor2_, suma_, bet_, M_),  cota1{cota1_}, cota2{cota2_}, cotaegal{cotaegal_} {
    //std::cout << "Constructor";
};
std::string Pariu_Rezultat :: getbet() const { return bet; }
Meci Pariu_Rezultat :: getM() const { return M; }
float Pariu_Rezultat:: getcastig1() const { return suma * cota1; }
float Pariu_Rezultat:: getcastig2() const { return suma * cota2; }
float Pariu_Rezultat::getcastigegal() const { return suma * cotaegal; }
bool Pariu_Rezultat::castigat() const {
    return bet == M.Winner();
}
void Pariu_Rezultat ::AfisPariu(){

        std::cout <<"Meciul dintre " << getM().getechip1() << " si "
                  << getM().getechip2() << " s-a terminat cu scorul " << getM().getscor1() << "-"
                  << getM().getscor2() << "\n" << "Pariul a fost pe " << getbet() << "\n";
    };
float Pariu_Rezultat ::CastigPariu() {
    if (castigat())
    {
        if(getbet() == "1")
            return getcastig1();
        else if(getbet() == "2")
            return getcastig2();
        else
            return getcastigegal();
    }
    else return 0;
}

