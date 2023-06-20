#include "Pariu.h"
#include "Meci.h"

Pariu ::Pariu(int scor1_, int scor2_, int suma_, std :: string const  &bet_, Meci const &M_) :
                                    scor1(scor1_), scor2(scor2_), suma(suma_), bet(bet_), M(M_) {};
std::ostream& operator<<(std::ostream& os, const Pariu& p) {
    os << "Pariu in valoare de " <<  p.suma << " pe meciul dintre " << p.M.getechip1() << " si " << p.M.getechip2() << "\n";
    return os;
}
Pariu ::  ~Pariu() = default;
