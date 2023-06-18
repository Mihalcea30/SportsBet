//
// Created by Home on 6/18/2023.
//

#ifndef OOP_EXCEPTII_H
#define OOP_EXCEPTII_H
#include <stdexcept>
class app_error : public std::runtime_error{
    using std::runtime_error::runtime_error;
};
class noteams_error : public app_error{
public:
    explicit noteams_error(std::string s);
};
class wrongteam_error : public app_error{
public:
    explicit wrongteam_error(int lenght);
};
#endif //OOP_EXCEPTII_H
