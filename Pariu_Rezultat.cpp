#include "Pariu_Rezultat.h"
#include "Pariu.h"

Pariu_Rezultat ::Pariu_Rezultat(std::string const  &bet_, Meci const &M_, float cota1_, float cota2_, float cotaegal_, int Suma_) :
bet{bet_}, M{M_}, cota1{cota1_}, cota2{cota2_}, cotaegal{cotaegal_}, suma{Suma_} {
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