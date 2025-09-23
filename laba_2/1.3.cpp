#include <iostream>
#include <cmath>
#include <windows.h>
#include <limits>
using namespace std;

enum ExitCode 
{
SUCCESS,
INVALID_INPUT 
};

bool allDigitsSame(int n) {
    int lastDigit = n % 10;
    while (n > 0) {
        if (n % 10 != lastDigit) {
            return false;
        }
        n /= 10;
    }
    return true;
}

	void getEnter()	{
	cout << "\n\nНажмите Enter для завершения...";
    cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
	cin.get(); 
	}
int main()
{
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL,"Russian");    

    unsigned int n, term, max = 0;
    cout << "Введите число N: ";
    cin >> n;

    if (cin.fail() || n < 1) {
        cout << "Неверный n!" << endl;
        getEnter();
        return INVALID_INPUT;
    }
    if (n / 10 == 0) {
        cout << n << " - однозначное число" << endl;
        getEnter();
        return SUCCESS;
    }
    if (allDigitsSame(n)) {
        cout << "0; число состоит из одинаковых цифр";
        getEnter();
        return SUCCESS;
    }

    unsigned int original_n = n; 
    do {
        term = n % 10;
        if (max < term) {
            max = term;
        }
        n /= 10;
    }
    while(n > 0);

    n = original_n;
    unsigned int divisor = 1;
    while (divisor <= n / 10) {
        divisor *= 10;
    }

    cout << "Результат: ";
    while (divisor > 0) {
        term = n / divisor; 
        if (term != max) {
            cout << term;
        }
        n %= divisor;       
        divisor /= 10;      
    }

getEnter();
return SUCCESS;
}