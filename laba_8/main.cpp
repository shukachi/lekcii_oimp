#include <iostream>
#include "common_fractions.h"
#include "fraction_exception.h"

using namespace std;

enum Errors
{
    SUCCESS,
    INVALID_INPUT
};

int main()
{
    #ifdef _WIN32
    system("chcp 65001 > nul");
    #endif

    cout << "--- Тестирование класса дробей ---\n";
    try
    {
        int n, d;
        Common_fractions f1(1, 2);
        Common_fractions f2(3, 4);
        Common_fractions f5;
        f5.setNumerator(n);
        f5.setDenominator(d);
        // cout << "f5 = "; f5.reduce();


        cout << "f1 = "; f1.print();
        cout << "f2 = "; f2.print();

        Common_fractions sum = f1 + f2;
        cout << "f1 + f2 = "; sum.print();

        cout << "\n--- Тестирование исключения (деление на ноль) ---\n";
        Common_fractions f3(5, 6);
        Common_fractions f_zero(0, 1);
        cout << "Попытка деления на нулевую дробь...\n";
        Common_fractions result = f3 / f_zero; // Эта строка должна вызвать ошибку
    }
    catch (const FractionException& e)
    {
        cerr << "Перехвачена ошибка: " << e.what() << endl;
    }
    system("pause");
    return SUCCESS;
}