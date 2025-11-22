#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum Errors
{
    SUCCESS,
    EMPTY_FILE,
    ERROR_INPUT
};

int main()
{   
    #ifdef _WIN32
    system("chcp 65001 > nul");
    #endif

    string targetWord1, targerWord2;
    ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        cerr << "Ошибка: не удалось открыть файл input.txt" << endl;
        return 1; 
    }

    if (!(inputFile >> targetWord1 >> targerWord2))
    {
        cout << "В файле input.txt или нет слов для поиска или файл пуст." << endl;
        inputFile.close();
        return EMPTY_FILE;
    }
    

    inputFile.close();
    system("pause");
    return SUCCESS;
}