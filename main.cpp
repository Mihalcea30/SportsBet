#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
const int NMAX = 100;

class Echipa{
private:
    int len;
    char s[NMAX];
    std::vector<std :: string>ListaEchipe;
public:
     Echipa(int len_, char sir_[NMAX], std::vector<std::string>Lista_) : len{len_}, s{sir_[NMAX]}, ListaEchipe{std::move(Lista_)} {
          ///std::cout << "echipa";
     }
     ///constructor de copiere

    void Echipe()
    {
        std::fstream f;
        f.open("echipe.txt", std::ios::in);
        for(int i = 0; i < len; i++)
        {
            f.getline(s, len);
            ListaEchipe.push_back(s);
        }
        f.close();
    }
    std::string RandomTeam(int index)
    {
        int x = rand() % len;
        if(index == 0 && x % 2 == 1)

            x = x-1;
        else if(index == 1 && x % 2 == 0)
            x = x+1;
        return ListaEchipe[x];
    }
};
class Meci {
private:
    std::string echipa1;
    std::string echipa2;
    int scor1, scor2;
public:
    /*void Citire(std::ifstream &f) {
        f >> echipa1 >> echipa2 >> scor1 >> scor2;
    }*/
    Meci(std::string echipa1_, std::string echipa2_, int scor1_, int scor2_) : echipa1{std::move(echipa1_)}, echipa2{std::move(echipa2_)},
                                                                               scor1{scor1_}, scor2{scor2_} {
        ///std::cout << "meci";
    }

    Meci(const Meci &other) : echipa1{other.echipa1}, echipa2{other.echipa2}, scor1{other.scor1}, scor2{other.scor2}{
    ///std::cout << "Constr de copiere\n";
    }
    Meci& operator=(const Meci& other) {
        echipa1 = other.echipa1;
        echipa2 = other.echipa2;
        scor1 = other.scor1;
        scor2 = other.scor2;
        ///std::cout << "operator= copiere";
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& os, const Meci& m) {
        os << "Meciul dintre " << m.echipa1 << " si " << m.echipa2 << " are scorul " << m.scor1 << " - " << m.scor2 << "\n";
        return os;
    }
    ~Meci() {
        ///std::cout << "destructor";
    }
    std::string getechip1() const { return echipa1; }
    std::string getechip2() const { return echipa2; }
    int getscor1() const { return scor1; }
    int getscor2() const { return scor2; }
    std::string Winner() const
    {
        if(scor1 > scor2)
            return "1";
        else if(scor2 > scor1)
            return "2";
        else
            return "x";
    }
};
class Pariu{
    std::string bet;
    Meci M;
    float cota1, cota2, cotaegal;
    int suma;
public:
    Pariu(std::string bet_, const Meci &M_, float cota1_, float cota2_, float cotaegal_, int suma_) : bet{std::move(bet_)}, M{M_}, cota1{cota1_}, cota2{cota2_}, cotaegal{cotaegal_}, suma{suma_} {
        ///std::cout << "pariu";
    }
    Pariu(const Pariu &other) : bet{other.bet}, M{other.M}, cota1{other.cota1}, cota2{other.cota2}, cotaegal{other.cotaegal}, suma{other.suma}{
        ///std::cout << "Constr de copiere\n";
    }
    Pariu& operator=(const Pariu& other) {
        bet = other.bet;
        M = other.M;
        cota1 = other.cota1;
        cota2 = other.cota2;
        cotaegal = other.cotaegal;
        suma = other.suma;
        ///std::cout << "operator= copiere";
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& os, const Pariu& p) {
        os << "Pariu in valoare de " <<  p.suma << " pe meciul dintre " << p.M.getechip1() << " si " << p.M.getechip2() << "\n";
        return os;
    }
    ~Pariu() {
        ///std::cout << "destructor";
    }
    std::string getbet() const { return bet; }
    Meci getM() const { return M; }
    /*float getcota1() const { return cota1; }
    float getcota2() const { return cota2; }
    float getcotaegal() const { return cotaegal; }
    float getsuma() const { return suma; }*/
    float getcastig1() const { return suma * cota1; }
    float getcastig2() const { return suma * cota2; }
    float getcastigegal() const { return suma * cotaegal; }
    bool castigat() const {
        return bet == M.Winner();
    }

};
class Bilet {
private:
    std::vector<Pariu> P;
    int nr;
public:
    Bilet(std::vector<Pariu> P_, int nr_) : P{std::move(P_)}, nr{nr_} {
        ///std::cout << "bilet";
    }
    Bilet(const Bilet &other) : P{other.P}, nr{other.nr}{
        ///std::cout << "Constr de copiere\n";
    }
    Bilet &operator=(const Bilet &other) {
        P = other.P;
        nr = other.nr;
        std::cout << "operator=";
        return *this;
    }
    ~Bilet() {
        ///std::cout << "destructor";
    }
    friend std::ostream &operator<<(std::ostream &os, const Bilet &b) {
        os << "Biletul are " << b.nr << " pariuri\n";
        for (int i = 0; i < b.nr; i++)
            os << b.P[i];
        return os;
    }
    float getcastig() const {

        bool ok = true;
        float castig = 0;
        for (int i = 0; i < nr; i++) {
            if (P[i].castigat())
            {
                if(P[i].getbet() == "1")
                    castig += P[i].getcastig1();
                else if(P[i].getbet() == "2")
                    castig += P[i].getcastig2();
                else
                    castig += P[i].getcastigegal();
            }
            else
                ok = false;
        }
        if (ok)
            return castig;
        return 0;
    }
    void afisare() const {
        for (int i = 0; i < nr; i++)
            std::cout << i + 1 << "." << "Meciul dintre " << P[i].getM().getechip1() << " si "
            << P[i].getM().getechip2() << " s-a terminat cu scorul " << P[i].getM().getscor1() << "-" << P[i].getM().getscor2() << "\n" << "Pariul a fost pe " << P[i].getbet() << "\n";
        if(getcastig() != 0)
            std::cout << "Corect!" << "\n";
        else
            std::cout << "Incorect!\n";

    };
};


int RandomScore()
{
    int x = rand() % 5;
    return x;
}
float RandomCota()
{
    float x = rand() % 20 + 11;
    x = x / 10;
    return x;
}
bool checkNumber (std::string s)
{
    int n = s.length();
    for (int i = 0; i < n; i++)
        if (isdigit(s[i]) == false)
            return false;
    return true;
}
int Stoi(std::string s)
{
    int n = s.length();
    int nr = 0;
    for(int i = 0;i < n;i++)
    {
        nr = nr * 10 + (s[i] - '0');
    }
    return nr;
}
void AlcatuireBilet()
{
    std::vector<Pariu> P;
    std::cout << "Introduceti suma pe care doriti sa o pariati:";
    std::string SumaC;
    std::cin >> SumaC;
    int Suma = 0;
    if(checkNumber(SumaC))
        Suma = Stoi(SumaC);
    while(Suma < 0 || !checkNumber(SumaC))
    {
        std::cout << "Suma trebuie sa fie un numar intreg pozitiv:";
        std::cin >> SumaC;
        if(checkNumber(SumaC))
            Suma = Stoi(SumaC);
    }
    std::cout << "Meciurile de azi:\n";
    std::vector<Meci> Meciuri;
    for(int i = 1;i <= 10;i++)
    {
        char s[NMAX];
        std::vector<std::string> Teams;
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
    std::string m;
    std::cout << "Introduceti numarul de pariuri de pe bilet:";
    std::cin >> m;
    int n = 0;
    if(checkNumber(m))
        n = Stoi(m);
    while(n < 0 || n > 10 || !checkNumber(m))
    {
        std::cout << "Numarul de pariuri trebuie sa fie un numar natural intre 1 si 10:";
        std::cin >> m;
        if(checkNumber(m))
            n = Stoi(m);
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
            x = Stoi(y);
        while(x < 1 || x > 10 || !checkNumber(y))
        {
            std::cout << "Indicele meciului trebuie sa fie un numar natural intre 1 si 10:";
            std::cin >> y;
            if(checkNumber(y))
                x = Stoi(y);
        }
        while(f[x] == 1)
        {
            std::cout << "Meciul a fost deja introdus:";
            std::cin >> y;
            if(checkNumber(y))
                x = Stoi(y);
        }
        f[x] = 1;
        x--;
        std::string bet;
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

int main() {
    /*Meci M{"Bayern MunicK", "Man City", 1, 2};
    Meci N(M);
    Pariu P{"1", M, 2, 3};
    Bilet B{std::vector<Pariu>{P}, 1};
    Pariu S{"2", M, 2, 3};
    S = P;*/
    srand(time(nullptr));
    ///B.afisare();
    ///std::cout << B.getcastig();
    std :: cout << "Bun venit!\n";
    bool ok = true;
    while(ok)
    {
        AlcatuireBilet();
        std::string x;
        std::cout << "Doriti sa pariati din nou?(Da sau Nu)?\n";
        std::cin >> x;
        while(x != "Da" && x != "Nu")
        {
            std::cout << "Comanda invalida!\n";
            std::cout << "Doriti sa pariati din nou?(Da sau Nu)?\n";
            std::cin >> x;
        }
        if(x == "Nu")
            ok = false;
    }
    return 0;
}
