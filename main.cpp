#include <iostream>
#include <string>
#include <vector>
#include <fstream>
class Meci {
private:
    std::string echipa1;
    std::string echipa2;
    int scor1, scor2;
public:
    Meci(std::string const &echipa1_, std::string const &echipa2_, int scor1_, int scor2_) : echipa1{echipa1_}, echipa2{echipa2_},
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
        std::cout << "operator= copiere";
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& os, const Meci& m) {
        os << "Meciul dintre " << m.echipa1 << " și " << m.echipa2 << " are scorul " << m.scor1 << " - " << m.scor2 << "\n";
        return os;
    }
    ~Meci() {
        ///std::cout << "destructor";
    }
    std::string getechip1() const { return echipa1; }
    std::string getechip2() const { return echipa2; }
    int getscor1() const { return scor1; }
    int getscor2() const { return scor2; }
    std::string Winner (int scor1_, int scor2_) const
    {
        if(scor1_ > scor2_)
            return "1";
        else if(scor2_ > scor1_)
            return "2";
        else
            return "x";
    }
};
class Pariu{
    std::string bet;
    Meci M;
    int cota;
    float suma;
public:
    Pariu(std::string const &bet_, const Meci &M_, int cota_, float suma_) : bet{bet_}, M{M_}, cota{cota_}, suma{suma_} {
        ///std::cout << "pariu";
    }
    Pariu(const Pariu &other) : bet{other.bet}, M{other.M}, cota{other.cota}, suma{other.suma}{
        ///std::cout << "Constr de copiere\n";
    }
    Pariu& operator=(const Pariu& other) {
        bet = other.bet;
        M = other.M;
        cota = other.cota;
        suma = other.suma;
        std::cout << "operator= copiere";
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& os, const Pariu& p) {
        os << "Pariu in valoare de " <<  p.cota << " pe meciul dintre " << p.M.getechip1() << " și " << p.M.getechip2() << "care are cota " << p.cota << "\n";
        return os;
    }
    ~Pariu() {
        ///std::cout << "destructor";
    }
    std::string getbet() const { return bet; }
    Meci getM() const { return M; }
    float getcota() const { return cota; }
    float getsuma() const { return suma; }
    float getcastig() const { return suma * cota; }
    bool castigat() const {
        if(bet == M.Winner(M.getscor1(), M.getscor2()))
            return true;
        else
            return false;
    }

};
class Bilet {
private:
    std::vector<Pariu> P;
    int nr;
public:
    Bilet(std::vector<Pariu> const& P_, int nr_) : P{P_}, nr{nr_} {
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
                castig += P[i].getcastig();
            else
                ok = false;
        }
        if (ok)
            return castig;
        return 0;
    }
    void afisare() const {
        for (int i = 0; i < nr; i++)
            std::cout << P[i].getbet() << " " << P[i].getM().getechip1() << " " << P[i].getM().getechip2() << " "
                      << P[i].getM().getscor1() << " "
                      << P[i].getM().getscor2() << " " << P[i].getcota() << " " << P[i].getsuma() << " "
                      << P[i].getcastig() << " " << P[i].castigat() << " ";

    };
};
int main() {
    Meci M{"meims", "asda", 1, 2};
    std::ifstream fin("tastatura.txt");
    Pariu P{"1", M, 2, 3};
    Bilet B{std::vector<Pariu>{P}, 1};
    Pariu S{"2", M, 2, 3};
    S = P;
    B.afisare();
    std::cout << B.getcastig();
    return 0;
}
