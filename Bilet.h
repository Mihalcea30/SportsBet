
#ifndef OOP_BILET_H
#define OOP_BILET_H
#include "Pariu_Rezultat.h"
#include <vector>

class Bilet {
private:
    std::vector<Pariu*> P;
    int nr;
public:
    Bilet(std::vector<Pariu*> P_, int nr_);
    Bilet(const Bilet &other);
    ~Bilet();
    friend std::ostream &operator<<(std::ostream &os, const Bilet &b);
    float getcastig() const;
    void afisare() const;
};


#endif //OOP_BILET_H
