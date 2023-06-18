//
// Created by Home on 6/18/2023.
//
#include <stdexcept>
#include <cstring>
#include "Exceptii.h"

noteams_error :: noteams_error(std::string const &s): app_error(s) {};
wrongteam_error :: wrongteam_error(std::string const &s): app_error("Lungimea sirului trebuie sa fie mai mica sau egala cu ") {};
