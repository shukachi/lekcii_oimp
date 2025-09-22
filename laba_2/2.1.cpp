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

bool isprime(int num){
    if (num < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
	void getEnter()	{
	cout << "\n\nНажмите Enter для завершения...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
	cin.clear();
	cin.get(); 
	}
int main()
{
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL,"Russian");

    unsigned int n;
    cout << "Введите число N: ";
    cin >> n;
    if (cin.fail() || n < 1) {
        cout << "Неверный n!" << endl;
        getEnter();
        return INVALID_INPUT;
    }
    cout << "Простые числа до " << n << ":\t";
    for (int i = 2; i < n; i++)
    {
        if (isprime(i)){
            cout << i << " ";
        }

    }
getEnter();
return SUCCESS;
}