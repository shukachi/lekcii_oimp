#include <iostream>
using namespace std;

enum Errors
{
    SUCCESS,
    ERROR_INPUT
};

int set_n();
int set_m();
void clearMatrix(int m, int** mtrx);
bool is_mtrx_square(int& m, int& n);

int main()
{
    int m, n;
    do
    {
        m = set_m();
        n = set_n();
    } 
    while (!(is_mtrx_square(m, n)));
    
    int m = set_m();
    int n = set_n();
    int** mtrx = new int*[m];

    for (int i = 0; i < m; i++)
    {
        mtrx[i] = new int[n];
    }


    
    clearMatrix(m, mtrx);
    return SUCCESS;
}

int set_m()
{
    int m, n;
    cout << "enter m-lines: ";
    cin >> m;
    return m;
}

int set_n()
{
    int m, n;
    cout << "enter n-columns: ";
    cin >> n;
    return n;
}
void clearMatrix(int m, int** mtrx)
{
    for(int i = 0; i < m; i++)
    {
    delete [] mtrx[i];
    delete [] mtrx;
    }
}
bool is_mtrx_square(int& m, int& n)
{
    if(m == n)
    {
        return true;
    }
    else
    {
        return false;
    }
}