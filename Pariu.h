
#ifndef OOP_PARIU_H
#define OOP_PARIU_H
#include "Meci.h"

class Pariu{
protected:
    explicit Pariu();

    std::string bet;
    Meci M;
    int suma;
public:
    virtual  Pariu* clone() const = 0;
    friend std::ostream& operator<<(std::ostream& os, const Pariu& p);
    virtual ~Pariu();
    virtual void getCastig() const = 0;
    /*Meci getM() const;
    float getcastig1() const;
    float getcastig2() const;
    float getcastigegal() const;
    bool castigat() const;*/

};
#endif //OOP_PARIU_H
