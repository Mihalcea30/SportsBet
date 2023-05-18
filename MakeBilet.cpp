#include "MakeBilet.h"
#include "Pariu.h"
#include "Meci.h"
#include "Echipa.h"
#include "Bilet.h"
#include <iostream>
#include <string>
#include <cstdlib>


int MakeBilet :: RandomScore()
{
    int x = rand() % 5;
    return x;
}
float MakeBilet :: RandomCota()
{
    float x = rand() % 20 + 11;
    x = x / 10;
    return x;
}
bool MakeBilet :: checkNumber (std::string s)
{
    int n = s.length();
    for (int i = 0; i < n; i++)
        if (isdigit(s[i]) == false)
            return false;
    return true;
}
void MakeBilet :: AlcatuireBilet()
{
    std::cout << "Introduceti suma pe care doriti sa o pariati:";
    std::string SumaC;
    std::cin >> SumaC;
    if(checkNumber(SumaC))
        Suma = std::stoi(SumaC);
    while(Suma < 0 || !checkNumber(SumaC))
    {
        std::cout << "Suma trebuie sa fie un numar intreg pozitiv:";
        std::cin >> SumaC;
        if(checkNumber(SumaC))
            Suma = std::stoi(SumaC);
    }
    std::cout << "Meciurile de azi:\n";
    for(int i = 1;i <= 10;i++)
    {
        char s[] = "";
        Echipa E(NMAX,s, Teams);
        E.Echipe();
        std::string echipa1 = E.RandomTeam(0);
        std::string echipa2 = E.RandomTeam(1);
        int scor1 = RandomScore();
        int scor2 = RandomScore();
        Meci M{echipa1, echipa2, scor1, scor2};
        Meciuri.push_back(M);
        std::cout << i << "." << echipa1 << "-" << echipa2 <<"\n";
    }
    std::cout << "Introduceti numarul de pariuri de pe bilet:";
    std::cin >> m;
    if(checkNumber(m))
        n = std::stoi(m);
    while(n < 0 || n > 10 || !checkNumber(m))
    {
        std::cout << "Numarul de pariuri trebuie sa fie un numar natural intre 1 si 10:";
        std::cin >> m;
        if(checkNumber(m))
            n = std::stoi(m);
    }
    int f[100] = {0};
    std::cout << "Introduceti meciurile alese:\n";
    for(int i = 0; i < n; i++)
    {
        int x = 0;
        std::string y;
        std::cout << "Indice meci:";
        std::cin >> y;
        if(checkNumber(y))
            x = std::stoi(y);
        while(x < 1 || x > 10 || !checkNumber(y))
        {
            std::cout << "Indicele meciului trebuie sa fie un numar natural intre 1 si 10:";
            std::cin >> y;
            if(checkNumber(y))
                x = std::stoi(y);
        }
        while(f[x] == 1)
        {
            std::cout << "Meciul a fost deja introdus:";
            std::cin >> y;
            if(checkNumber(y))
                x = std::stoi(y);
        }
        f[x] = 1;
        x--;
        std::string echipa1 = Meciuri[x].getechip1();
        std::string echipa2 = Meciuri[x].getechip2();
        int scor1 = Meciuri[x].getscor1();
        int scor2 = Meciuri[x].getscor2();

        float cota1 = RandomCota();
        float cota2 = RandomCota() + cota1;
        float cotaegal = cota1 + cota2 + RandomCota();
        std::cout << "Cotele pentru meciul " << echipa1 << " - " << echipa2 << " sunt: " << "\n";
        std::cout << "1: " << cota1 << " " << "2: " << cota2 << " " << "x: " << cotaegal << "\n";
        std::cout << "Introduceti rezultatul preconizat(1 = Prima echipa castiga, 2 = A doua echipa castiga, x = Egalitate):";
        std::cin >> bet;
        while(bet != "1" && bet != "2" && bet != "x")
        {
            std::cout << "Pariul trebuie sa fie 1, 2 sau x:";
            std::cin >> bet;
        }
        Meci M{echipa1, echipa2, scor1, scor2};
        Pariu P1{bet, M, cota1, cota2, cotaegal,Suma};
        P.push_back(P1);
    }
    Bilet B{P, n};
    B.afisare();
    std::cout << "Castigul este: " << B.getcastig() << "\n";
}
