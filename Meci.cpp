#include "Meci.h"

Meci :: Meci(std::string echipa1_, std::string echipa2_, int scor1_, int scor2_) :
    echipa1{std::move(echipa1_)}, echipa2{std::move(echipa2_)}, scor1{scor1_}, scor2{scor2_} {
///std::cout << "meci";
}
Meci :: Meci(const Meci &other) : echipa1{other.echipa1}, echipa2{other.echipa2}, scor1{other.scor1}, scor2{other.scor2}{
    ///std::cout << "Constr de copiere\n";
}
std::ostream& operator<<(std::ostream& os, const Meci& m) {
    os << "Meciul dintre " << m.echipa1 << " si " << m.echipa2 << " are scorul " << m.scor1 << " - " << m.scor2 << "\n";
    return os;
}
Meci :: ~Meci() {
    ///std::cout << "destructor";
}
std::string Meci :: getechip1() const { return echipa1; }
std::string Meci :: getechip2() const { return echipa2; }
int Meci :: getscor1()  const { return scor1; }
int Meci :: getscor2()  const { return scor2; }
std::string Meci :: Winner() const
{
    if(scor1 > scor2)
        return "1";
    else if(scor2 > scor1)
        return "2";
    else
        return "x";
}