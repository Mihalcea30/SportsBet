#include "Pariu.h"
#include "Meci.h"


std::ostream& operator<<(std::ostream& os, const Pariu& p) {
    os << "Pariu in valoare de " <<  p.suma << " pe meciul dintre " << p.M.getechip1() << " si " << p.M.getechip2() << "\n";
    return os;
}
Pariu ::  ~Pariu() = default;

Pariu * clone(){

}
/*td::string Pariu :: getbet() const { return bet; }
Meci Pariu :: getM() const { return M; }
float Pariu :: getcastig1() const { return suma * cota1; }
float Pariu :: getcastig2() const { return suma * cota2; }
float Pariu :: getcastigegal() const { return suma * cotaegal; }
bool Pariu :: castigat() const {
    return bet == M.Winner();
}*/