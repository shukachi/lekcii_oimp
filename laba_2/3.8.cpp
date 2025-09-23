#include <iostream>
#include <cmath>
#include <windows.h>
#include <limits>
using namespace std;

bool horoshoechislo(int n) {
    int term,chislo;
    chislo = n;
    if (n == 0) {
        return false;
    } else if (n / 10 == 0) {
        return true;
    }
        do {
            term = n % 10;
            if (term == 0) {
                return false;    
            } else if (chislo % term == 0) {
                n = (n - term) / 10;
            } else {
                return false;
            }
    }
    while(n != 0);
    return true;
}


enum ExitCode {    
SUCCESS,
INVALID_INPUT 
};

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

    unsigned int a,b;
    cout << "Введите интервал [a,b] через пробел: ";
    cin >> a >> b;
    if (cin.fail() || a > b) {
        cout << "Неверный интервал!" << endl;
        getEnter();
        return INVALID_INPUT;
    }
    for (unsigned int i = a; i <= b; i++) {
        if (horoshoechislo(i)) {
        cout << i << endl;
        }
    }
getEnter();
return SUCCESS;
}
