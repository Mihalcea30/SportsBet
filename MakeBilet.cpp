#include "MakeBilet.h"
#include "Pariu.h"
#include "Meci.h"
#include "Echipa.h"
#include "Bilet.h"
#include "Pariu_Rezultat.h"
#include "Pariu_goluri.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <utility>

MakeBilet ::MakeBilet(std::vector<Pariu*> P_, int Suma_, std::vector<Meci> const &Meciuri_, std::vector<std::string> const &Teams_
, std::string const &m_, int n_, std::string const &bet_) : P{std::move(P_)}, Suma{Suma_}, Meciuri{Meciuri_}, Teams{Teams_}, m{m_}, n{n_}, bet{bet_} {
    ///std::cout << "makebilet";
}
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
    int len = s.length();
    for (int i = 0; i < len; i++)
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
        try {
            E.Echipe();
        }
        catch (std::runtime_error& err) {
            std::cout << err.what() << "\n";
        }
        std::string echipa1, echipa2;
        try {
            echipa1 = E.RandomTeam(0);
            echipa2 = E.RandomTeam(1);
        }
        catch (std::runtime_error& err) {
            std::cout << err.what() << "\n";
        }
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
        std :: cout << "Alege tipul de pariu pentru acest meci(RezultatFinal, Goluri, Special):";
        std::string tipPariu;
        std :: cin >> tipPariu;
        Meci M{echipa1, echipa2, scor1, scor2};
        if(tipPariu == "RezultatFinal"){
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
            Pariu *P1 = new Pariu_Rezultat{scor1, scor2, Suma, bet, M, cota1, cota2, cotaegal};
            P.push_back(P1);
        }
        else if(tipPariu == "Goluri"){
            float cotaSub4 = RandomCota();
            float cotaPeste4 = RandomCota() + cotaSub4;
            float cotaSub2 = RandomCota();
            float cotaPeste2 = RandomCota() + cotaSub2;
            std::cout << "Cotele pentru meciul " << echipa1 << " - " << echipa2 << " sunt: " << "\n";
            std::cout << "TMin4: " << cotaPeste4 << " " << "TMax4: " << cotaSub4 << " "
            << "PMin2: " << cotaPeste2 << " " << "PMax2 " <<  cotaSub2 << "\n";
            std::cout << "Introduceti rezultatul preconizat: \nTMin4 = se marcheaza cel putin 4 goluri in total\n"
                         << "TMax4 = se marcheaza cel mult 4 goluri in total\n"
                         << "PMin2 = Prima echipa marcheaza cel putin 2 goluri\n"
                         << "PMax2 = Prima echipa marcheaza cel mult 2 goluri\n";
            std::cin >> bet;
            while(bet != "TMin4" && bet != "TMax4" && bet != "PMax2" && bet != "PMin2")
            {
                std::cin >> bet;
            }
            Pariu *P1 = new Pariu_Goluri{scor1, scor2, Suma, bet, M, cotaSub4, cotaPeste4, cotaSub2, cotaPeste2};
            P.push_back(P1);
        }
    }
    Bilet B{P, n};
    B.afisare();
    std::cout << "Castigul este: " << B.getcastig() << "lei\n";
    for(auto x : P)
        delete x;
}
