#include "Echipa.h"
#include <iostream>
#include  <vector>
#include <fstream>

Echipa::Echipa(int len_, char sir_[NMAX], std::vector<std::string>Lista_) : len{len_}, s{sir_[NMAX]}, ListaEchipe{std::move(Lista_)} {
    ///std::cout << "echipa";
}
///constructor de copiere

void Echipa :: Echipe()
{
    std::fstream f = nullptr;
    f.open("echipe.txt", std::ios::in);
    for(int i = 0; i < len; i++)
    {
        f.getline(s, len);
        ListaEchipe.push_back(s);
    }
    f.close();
}
std::string Echipa :: RandomTeam(int index)
{
    int x = rand() % len;
    if(index == 0 && x % 2 == 1)

        x = x-1;
    else if(index == 1 && x % 2 == 0)
        x = x+1;
    return ListaEchipe[x];
}
