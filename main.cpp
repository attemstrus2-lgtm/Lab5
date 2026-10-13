#include <iostream>
#include <clocale>
#include "../Лаб 5/MoneyLib.h" // Підключаємо заголовок бібліотеки

using namespace std;
using namespace MoneyFuncs;

int main()
{
    setlocale(LC_ALL, "uk_UA.UTF-8");

    MyMoney m1, m2;

    cout << "--- Введення першої суми ---\n";
    m1.Read();

    cout << "--- Введення другої суми ---\n";
    m2.Read();

    cout << "\nПерша сума: "; m1.Display();
    cout << "Друга сума: "; m2.Display();

    // Тестування операцій з бібліотеки
    cout << "\n--- Результати роботи бібліотеки ---" << endl;

    cout << "Результат додавання: ";
    m1.Add(m2).Display();

    cout << "Результат віднімання: ";
    m1.Sub(m2).Display();

    cout << "Результат ділення сум: " << m1.Div(m2) << endl;

    double factor = 2.0;
    cout << "Множення першої суми на " << factor << ": ";
    m1.MulNum(factor).Display();

    cout << "Ділення першої суми на " << factor << ": ";
    m1.DivNum(factor).Display();

    int cmp = m1.Compare(m2);
    if (cmp > 0) cout << "Перша сума більша.\n";
    else if (cmp < 0) cout << "Перша сума менша.\n";
    else cout << "Суми рівні.\n";

    return 0;
}
