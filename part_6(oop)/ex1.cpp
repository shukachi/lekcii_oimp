
#include <iostream>
#include <cmath>
using namespace std;

class Int
{
    private:
    int num;

    public:
    Int() : num(0) {}
    Int(int n) : num(n) {}
    void setint()
    {
        cin >> num;
        cout << endl;
    }
    int getint() const { return num; } 
    void display() const 
    {
        cout << num;
    }
    Int operator+ (Int);
};
    Int Int :: operator+ (Int nn)
    {
        Int a;
        a.num = this->num + nn.num;
        return a; 
    }
int main()
{
    Int n1, n2, n3, n4;
    n1.setint();
    n3.setint();
    n4.display();
    cout << endl;
    n2 = n1 + n3;
    n2.display();
    cout << endl;
    system("pause");
    return 0;
}    