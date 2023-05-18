
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
    int RandomScore();
    float RandomCota();
    bool checkNumber (std::string s);
    void AlcatuireBilet();

};

#endif //OOP_MAKEBILET_H
