
#ifndef OOP_MAKEBILET_H
#define OOP_MAKEBILET_H

#include "Pariu.h"
#include "Meci.h"
#include "Pariu_Rezultat.h"
#include <vector>
#include <string>
#include <iostream>
#include "Pariu_Rezultat.h"
class MakeBilet
{
private:
    std::vector<Pariu*> P;
    int Suma;
    std::vector<Meci> Meciuri;
    std::vector<std::string> Teams;
    std::string m;
    int n;
    std::string bet;
public:
    MakeBilet(std::vector<Pariu*> P_, int Suma_, std::vector<Meci> const &Meciuri_, std::vector<std::string> const &Teams_
            , std::string const &m_, int n_, std::string const &bet_);
    static int RandomScore();
    static float RandomCota();
    static bool checkNumber (std::string s);
    void AlcatuireBilet();

};

#endif //OOP_MAKEBILET_H
