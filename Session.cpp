#include "Session.h"
#include <iostream>

void Session ::MakeSession(){
    srand(time(nullptr));
    std::cout << "Bun venit!\n";
    bool ok = true;
    while (ok) {
        MakeBilet S;
        S.AlcatuireBilet();
        std::string x;
        std::cout << "Doriti sa pariati din nou?(Da sau Nu)?\n";
        std::cin >> x;
        while (x != "Da" && x != "Nu") {
            std::cout << "Comanda invalida!\n";
            std::cout << "Doriti sa pariati din nou?(Da sau Nu)?\n";
            std::cin >> x;
        }
        if (x == "Nu")
            ok = false;
    }
    std::cout << "La revedere!\n";
}