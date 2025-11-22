#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;
struct TStack 
{ 
    int n; 
    int* items; 
    int top; 
};
TStack stack; 
void createStack(TStack &stack, int count) 
{
    stack.items = new int[count];
    stack.top = 0;
    stack.n = count;
}
void deleteStack(TStack &stack) 
{
    delete[] stack.items;
    stack.items = nullptr;
}
void push(TStack &stack, const int &k) 
{
    if (stack.top > stack.n - 1) 
    {
        throw "Stack is full!";
    }
    stack.items[stack.top++] = k;
}
int pop(TStack &stack) 
{ 
    if (stack.top == 0) 
    {
        throw "Stack is empty!";
    }
    int k = stack.items[--stack.top];
    return k;
}
bool isEmpty(TStack stack) 
{ 
    return (stack.top == 0);
}
int main() 
{
    #ifdef _WIN32
    system("chcp 65001 > nul");
    #endif
    int value;
    createStack(stack, 40);
    try 
    {
        cout << "Введите числа (для завершения введите букву):" << endl;
        while (cin >> value) 
        {
            push(stack, value);
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nВывод стека:" << endl;
        do 
        {
            cout << pop(stack) << endl;
        } 
        while (!isEmpty(stack));
        cout << endl;
    }
    catch (...) 
    {
        cout << "Ошибка работы со стеком" << endl;
    }
    deleteStack(stack);
    system("pause");
    return 0;
}
