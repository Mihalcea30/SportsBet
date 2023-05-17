#include "Bilet.h"

Bilet :: Bilet(std::vector<Pariu> P_, int nr_) : P{std::move(P_)}, nr{nr_} {
///std::cout << "bilet";
}
Bilet :: Bilet(const Bilet &other) : P{other.P}, nr{other.nr}{
    ///std::cout << "Constr de copiere\n";
}
Bilet :: ~Bilet() {
    ///std::cout << "destructor";
}
std::ostream &operator<<(std::ostream &os, const Bilet &b) {
    os << "Biletul are " << b.nr << " pariuri\n";
    for (int i = 0; i < b.nr; i++)
        os << b.P[i];
    return os;
}
float Bilet :: getcastig() const {

    bool ok = true;
    float castig = 0;
    for (int i = 0; i < nr; i++) {
        if (P[i].castigat())
        {
            if(P[i].getbet() == "1")
                castig += P[i].getcastig1();
            else if(P[i].getbet() == "2")
                castig += P[i].getcastig2();
            else
                castig += P[i].getcastigegal();
        }
        else
            ok = false;
    }
    if (ok)
        return castig;
    return 0;
}
void Bilet :: afisare() const {
    for (int i = 0; i < nr; i++)
        std::cout << i + 1 << "." << "Meciul dintre " << P[i].getM().getechip1() << " si "
                  << P[i].getM().getechip2() << " s-a terminat cu scorul " << P[i].getM().getscor1() << "-" << P[i].getM().getscor2() << "\n" << "Pariul a fost pe " << P[i].getbet() << "\n";
    if(getcastig() != 0)
        std::cout << "Corect!" << "\n";
    else
        std::cout << "Incorect!\n";

};
