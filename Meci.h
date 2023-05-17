
#ifndef OOP_MECI_H
#define OOP_MECI_H


#include <string>
#include <iostream>

class Meci {
private:
    std::string echipa1;
    std::string echipa2;
    int scor1, scor2;
public:
    /*void Citire(std::ifstream &f) {
        f >> echipa1 >> echipa2 >> scor1 >> scor2;
    }*/
    Meci(std::string echipa1_, std::string echipa2_, int scor1_, int scor2_);
    Meci(const Meci &other);
    //Meci& operator=(const Meci& other);
    friend std::ostream& operator<<(std::ostream& os, const Meci& m);
    ~Meci();
    std::string getechip1() const;
    std::string getechip2() const;
    int getscor1() const;
    int getscor2() const;
    std::string Winner() const;
};


#endif //OOP_MECI_H
