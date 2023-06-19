
#ifndef OOP_MECI_H
#define OOP_MECI_H


#include <string>
#include <iostream>

class Meci {
private:
    std::string echipa1;
    std::string echipa2;
    int scor1, scor2;
    friend class meci_builder;
public:
    /*void Citire(std::ifstream &f) {
        f >> echipa1 >> echipa2 >> scor1 >> scor2;
    }*/
    Meci() = default;
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
///Builder
class meci_builder{
private:
    Meci M;
public:
    meci_builder() = default;
    meci_builder& echipa1(std::string const& echipa){
        M.echipa1 = echipa;
        return *this;
    }
    meci_builder& echipa2(std::string const& echipa){
        M.echipa2 = echipa;
        return *this;
    }
    meci_builder& scor1(int scor){
        M.scor1 = scor;
        return *this;
    }
    meci_builder& scor2(int scor){
        M.scor2 = scor;
        return *this;
    }
    Meci build(){
        return M;
    }
};


#endif //OOP_MECI_H
