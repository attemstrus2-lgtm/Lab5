#pragma once
#include <string>

namespace MoneyFuncs
{
    class MyMoney
    {
    private:
        long hryvnia;
        unsigned char kopeck;

    public:
        // Конструктори з Лаби 3
        MyMoney();
        MyMoney(long h, int k);
        MyMoney(const MyMoney& other);
        ~MyMoney();

        // Методи
        bool Init(long h, int k);
        void Read();
        std::string toString() const;
        void Display() const;

        // Операції з умови завдання
        MyMoney Add(const MyMoney& other) const;
        MyMoney Sub(const MyMoney& other) const;
        double Div(const MyMoney& other) const;
        MyMoney DivNum(double factor) const;
        MyMoney MulNum(double factor) const;
        int Compare(const MyMoney& other) const;
    };
}
