
#ifndef OOP_MAKEBILET_H
#define OOP_MAKEBILET_H

#include "Pariu.h"
#include "Meci.h"
#include <vector>
#include <string>
#include <iostream>

class MakeBilet
{
private:
    std::vector<Pariu> P;
    int Suma;
    std::vector<Meci> Meciuri;
    std::vector<std::string> Teams;
    std::string m;
    int n;
    std::string bet;
public:
    MakeBilet(std::vector<Pariu> const &P_, int Suma_, std::vector<Meci> const &Meciuri_, std::vector<std::string> const &Teams_
            ,std::string const &m_, int n_, std::string const &bet_);
    int RandomScore();
    float RandomCota();
    bool checkNumber (std::string s);
    void AlcatuireBilet();

};

#endif //OOP_MAKEBILET_H
