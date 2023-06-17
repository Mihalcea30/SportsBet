
#ifndef OOP_PARIU_H
#define OOP_PARIU_H
#include "Meci.h"

class Pariu{
protected:
    int scor1, scor2;
    int suma;
    std :: string bet;
    Meci M;
public:
    Pariu(int scor1_, int scor2_, int suma_, std :: string const &bet_, Meci const &M_);
    friend std::ostream& operator<<(std::ostream& os, const Pariu& p);
    virtual ~Pariu();
    ///virtual void getCastig() const = 0;
    /*Meci getM() const;
    float getcastig1() const;
    float getcastig2() const;
    float getcastigegal() const;
    bool castigat() const;*/
    virtual void AfisPariu();
    virtual float CastigPariu();

};
#endif //OOP_PARIU_H
