#include "Bilet.h"

#include <utility>

Bilet :: Bilet(std::vector<Pariu*> P_, int nr_) : P{std::move(P_)}, nr{nr_} {
///std::cout << "bilet";
}
Bilet :: Bilet(const Bilet &other) {
    P = other.P;
    nr = other.nr;
}
Bilet :: ~Bilet() {
    ///std::cout << "destructor";
}
Bilet &Bilet :: operator=(const Bilet &other) {
    if (this != &other) {
        P = other.P;
        nr = other.nr;
    }
    return *this;
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
       ///auto *Pp = dynamic_cast<Pariu_Rezultat *>(P[i]);
        if (P[i]->CastigPariu() != 0)
            castig += P[i]->CastigPariu();
        else
            ok = false;
    }
    if (ok)
        return castig;
    return 0;
}
void Bilet :: afisare() const {
    for (int i = 0; i < nr; i++){
        ///auto *Pp = dynamic_cast<Pariu_Rezultat *>(P[i]);
        std::cout << i + 1 << ".";
        P[i]->AfisPariu();
    }

    if(getcastig() != 0)
        std::cout << "Corect!" << "\n";
    else
        std::cout << "Incorect!\n";

};
