#include "Pariu.h"
#include "Meci.h"

Pariu :: Pariu(std::string bet_, const Meci &M_, float cota1_, float cota2_, float cotaegal_, int suma_) : bet{std::move(bet_)}, M{M_}, cota1{cota1_}, cota2{cota2_}, cotaegal{cotaegal_}, suma{suma_} {
///std::cout << "pariu";
}
Pariu :: Pariu(const Pariu &other) : bet{other.bet}, M{other.M}, cota1{other.cota1}, cota2{other.cota2}, cotaegal{other.cotaegal}, suma{other.suma}{
    ///std::cout << "Constr de copiere\n";
}
std::ostream& operator<<(std::ostream& os, const Pariu& p) {
    os << "Pariu in valoare de " <<  p.suma << " pe meciul dintre " << p.M.getechip1() << " si " << p.M.getechip2() << "\n";
    return os;
}
Pariu :: ~Pariu() {
    ///std::cout << "destructor";
}
std::string Pariu :: getbet() const { return bet; }
Meci Pariu :: getM() const { return M; }
float Pariu :: getcastig1() const { return suma * cota1; }
float Pariu :: getcastig2() const { return suma * cota2; }
float Pariu :: getcastigegal() const { return suma * cotaegal; }
bool Pariu :: castigat() const {
    return bet == M.Winner();
}