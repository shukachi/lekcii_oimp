#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() 
{
    
    #ifdef _WIN32
    system("chcp 65001 > nul");
    #endif

    ifstream inputFile("input.txt");

    if (!inputFile.is_open()) 
    {
        cerr << "Ошибка: не удалось открыть файл input.txt" << endl;
        system("pause");
        return 1; 
    }

    string targetWord;
    if (!(inputFile >> targetWord))
    {
        cerr << "Ошибка: файл пуст или не удалось прочитать искомое слово." << endl;
        inputFile.close();
        return 1;
    }

    int count = 0;
    string currentWord;

    while (inputFile >> currentWord) 
    {
        if (currentWord == targetWord) 
        {
            count++; 
        }
    }

    inputFile.close();

    cout << "Слово '" << targetWord << "' встречается в тексте " << count << " раз(а)." << endl;
    system("pause");
    return 0; 
}
