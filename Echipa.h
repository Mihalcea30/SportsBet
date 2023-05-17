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
#endif // OOP_ECHIPA_H