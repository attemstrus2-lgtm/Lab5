#include "MoneyLib.h"
#include <iostream>
#include <cmath>

namespace MoneyFuncs
{
    MyMoney::MyMoney() {
        hryvnia = 0;
        kopeck = 0;
    }

    MyMoney::MyMoney(long h, int k) {
        if (!Init(h, k)) {
            hryvnia = 0;
            kopeck = 0;
        }
    }

    MyMoney::MyMoney(const MyMoney& other) {
        hryvnia = other.hryvnia;
        kopeck = other.kopeck;
    }

    MyMoney::~MyMoney() {}

    bool MyMoney::Init(long h, int k) {
        if (k >= 0 && k < 100 && h >= 0) {
            hryvnia = h;
            kopeck = static_cast<unsigned char>(k);
            return true;
        }
        return false;
    }

    void MyMoney::Read() {
        long h;
        int k;
        do {
            std::cout << "Введіть гривні: ";
            std::cin >> h;
            std::cout << "Введіть копійки (0-99): ";
            std::cin >> k;
            if (Init(h, k)) break;
            std::cout << "Помилка введення! Спробуйте ще раз.\n";
        } while (true);
    }

    std::string MyMoney::toString() const {
        std::string kopStr = std::to_string(static_cast<int>(kopeck));
        if (kopStr.length() == 1) kopStr = "0" + kopStr;
        return std::to_string(hryvnia) + "," + kopStr;
    }

    void MyMoney::Display() const {
        std::cout << toString() << " грн" << std::endl;
    }

    MyMoney MyMoney::Add(const MyMoney& other) const {
        long totalKop = (hryvnia + other.hryvnia) * 100 + static_cast<int>(kopeck) + static_cast<int>(other.kopeck);
        return MyMoney(totalKop / 100, totalKop % 100);
    }

    MyMoney MyMoney::Sub(const MyMoney& other) const {
        long long kop1 = hryvnia * 100 + static_cast<int>(kopeck);
        long long kop2 = other.hryvnia * 100 + static_cast<int>(other.kopeck);
        long long diff = kop1 - kop2;
        if (diff < 0) {
            std::cout << "Помилка: результат віднімання від'ємний!\n";
            return MyMoney(0, 0);
        }
        return MyMoney(diff / 100, diff % 100);
    }

    double MyMoney::Div(const MyMoney& other) const {
        double kop1 = hryvnia * 100.0 + static_cast<int>(kopeck);
        double kop2 = other.hryvnia * 100.0 + static_cast<int>(other.kopeck);
        if (kop2 == 0) return 0.0;
        return kop1 / kop2;
    }

    MyMoney MyMoney::DivNum(double factor) const {
        if (factor == 0) return MyMoney(0, 0);
        double totalKop = (hryvnia * 100.0 + static_cast<int>(kopeck)) / factor;
        long roundedKop = std::round(totalKop);
        return MyMoney(roundedKop / 100, roundedKop % 100);
    }

    MyMoney MyMoney::MulNum(double factor) const {
        double totalKop = (hryvnia * 100.0 + static_cast<int>(kopeck)) * factor;
        long roundedKop = std::round(totalKop);
        return MyMoney(roundedKop / 100, roundedKop % 100);
    }

    int MyMoney::Compare(const MyMoney& other) const {
        long kop1 = hryvnia * 100 + static_cast<int>(kopeck);
        long kop2 = other.hryvnia * 100 + static_cast<int>(other.kopeck);
        if (kop1 > kop2) return 1;
        if (kop1 < kop2) return -1;
        return 0;
    }
}
