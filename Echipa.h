#ifndef OOP_ECHIPA_H
#define OOP_ECHIPA_H

#include <iostream>
#include  <vector>
#include <fstream>
const int NMAX = 100;
class Echipa{
private:
    int len;
    char s[NMAX];
    std::vector<std :: string>ListaEchipe;
public:
    Echipa(int len_, char sir_[NMAX], std::vector<std::string>Lista_) ;
    ///constructor de copiere
    void Echipe();
    std::string RandomTeam(int index);

};
class Echipa_factory{
public:
    static Echipa LaLiga() {
        char s[] = "";
        return Echipa(100, s, {"Real Madrid", "Barcelona", "Atletico Madrid", "Sevilla", "Villareal", "Real Sociedad", "Real Betis", "Athletic Bilbao", "Granada", "Celta Vigo", "Osasuna", "Cadiz", "Valencia", "Levante", "Getafe", "Alaves", "Elche", "Valladolid", "Huesca", "Eibar"});
    }
};
#endif // OOP_ECHIPA_H