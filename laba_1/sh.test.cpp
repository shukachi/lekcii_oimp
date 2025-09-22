#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <limits>
#include <windows.h>
using namespace std;

void getEnter()	{
cout << "\n\nНажмите Enter для завершения...";
cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
cin.clear();
cin.get(); 
}

enum ExitCode {
	SUCCESS,
	SPECIAL_CASE_ZERO,
	INVALID_INPUT 
};

int main()
{
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL,"Russian");
	double x, epsilon, term, s = 0;
	unsigned int k = 1;
	cout << "Input x = ";
	cin >> x;
	if (cin.fail()) {
		cout << "Неверный х!" << endl;
		getEnter();
		return INVALID_INPUT;
	}

	if(x == 0) {
		cout << "sh(x) = 0";
  		getEnter();		
		return SPECIAL_CASE_ZERO;
	}
	cout << "Input epsilon = ";
	cin >> epsilon;

	if (cin.fail() || epsilon <= 0) {
		cout << "Неверный Эпсилон!" << endl;
   		getEnter();
		return INVALID_INPUT;
	}

	term = x;
	while (fabs(term) >= epsilon) {
		s += term;
		term = (term * x * x) / (2 * k * (2 * k + 1));
		k++;
	}
	cout << "Результат,полученный с помощью стандартных функций " << (pow(M_E, x) - pow(M_E,-x)) / 2  
			<< "\nРезультат,полученный с помощью ряда Тейлора " << s;

	getEnter(); 
	return SUCCESS;
}