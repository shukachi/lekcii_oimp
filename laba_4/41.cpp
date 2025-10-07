#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>
using namespace std;
enum ExitCode
{
    SUCCESS,
    INVALID_INPUT
};

void clear_input();
bool aproove();
void interMatrix(int& m, int& n);
void clearMatrix(int m, int** mtrx);
void choose(int m, int n, int** mtrx);
void random(int m, int n, int** mtrx);
void custom(int m, int n, int** mtrx);
void sortMatrix(int m, int n, int** mtrx, int** mtrx_temp);
void findMin(int m, int n, int** mtrx_temp);

int main()
{
    int m, n;
    interMatrix(m, n); 
    int** mtrx = new int* [m];
    for (int i = 0; i < m; i++)
    {
        mtrx[i] = new int [n];
    }

    int** mtrx_temp = new int* [m];
    for (int i = 0; i < m; i++)
    {
        mtrx_temp[i] = new int [n];
    }
    
    choose(m,n,mtrx);
    sortMatrix(m,n,mtrx,mtrx_temp);
    findMin(m,n,mtrx_temp);

    clearMatrix(m, mtrx);
    clearMatrix(m, mtrx_temp);
    system("pause");
    return SUCCESS;
}
inline void clear_input()
{
    cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
}
bool aproove()
{
    char answer;
    cout << "\nDo you want to continue? (y/n): ";
    //clear_input();
    cin >> answer;
    cout << endl;
    switch (answer)
    {
    case 'y':
    return true;
        break;
    case 'n':
    return false;
        break;
    default:
        cout << "Invalid input. Please enter 'y' or 'n'." << endl;
        clear_input();
        return aproove(); 
    }
}
void interMatrix(int& m, int& n) 
{
    cout << "Enter square matrix" << endl;
    cout << "Enter m-lines: ";
    cin >> m;
    cout << "And n-columns: ";
    cin >> n;
    if(cin.fail() || n < 1 || m < 1)
    {
        cout << "\nInvalid input. Please enter only positive integer values." << "\n" << endl;
        clear_input();
        if(aproove())
        {
            interMatrix(m, n); 
        } 
        else
        {
            exit(INVALID_INPUT);
        }
    }
    else if(m != n)
    {
        cout << "Matrix isn't square!" << endl;
        interMatrix(m, n);
    }
}
void clearMatrix(int m, int** mtrx)
{
    for(int i = 0; i < m; i++)
    delete [] mtrx[i];
    delete [] mtrx;
}
void choose(int m, int n, int** mtrx)
{
    char num;
    //showSeparator(elem);
    cout << endl;
    cout << "How do you want to fill the matrix?" << endl;
    cout << "Choose an option:" << endl;
    cout << "1. Option random (write 1)" << endl;
    cout << "2. Option custom (write 2)\n" << endl;
    //showSeparator(elem);
    cin >> num;
    //showSeparator(elem);

    switch (num)
    {
    case '1':
        random(m, n, mtrx);
        break;
    case '2':
        custom(m, n, mtrx);
        break;
    default:
        if(num != '1' || num != '2' || cin.fail())
        {
            std::cout << "\nInvalid input. Please enter 1 or 2." << "\n" << endl;
            //showSeparator(elem);
            clear_input();
            if(aproove())
            {
                choose(m, n, mtrx);
            } 
            else
            {
                exit(INVALID_INPUT);
            } 
        }
    }
}
void random(int m, int n, int** mtrx)
{
    int a,b;
    cout << "\nSet the interval [a,b] with space: ";
    cin >> a >> b;
    cout << endl;
    while((cin.fail() || a > b)) 
    {
        //showSeparator(elem);
        cout << "\nInvalid interval!" << "\n" << endl;
        //showSeparator(elem);
        clear_input();
        cin >> a >> b;
    }
    srand(time(0)); 
    //showSeparator(elem);
    cout << "\nRandom matrix:\n";
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            mtrx[i][j] = a + rand() % (b - a + 1);
            cout << setw(12) << mtrx[i][j];
            //cout << mtrx[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n" << endl;
}

void custom(int m, int n, int** mtrx)
{
    cout << "\nEnter matrix elements separated by spaces:" << endl;
    //showSeparator(elem);
    for(int i = 0; i < m; i++)
    {
        cout << "Enter " << n << " elements for row " << i + 1 << ": ";
        for(int j = 0; j < n; j++)
        {
            cin >> mtrx[i][j];
            while(cin.fail())
            {
                //showSeparator(elem);
                cout << "\nInvalid input. Please enter a number." << endl;
                //showSeparator(elem);
                clear_input(); 
                cout << "Please re-enter the element for row " << i + 1 << ", column " << j + 1 << ": ";
                cin >> mtrx[i][j]; 
                cout << "\nAnd continue entering elements\n";
            }
        }
    }
    cout << "\nCustom matrix:\n";
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << setw(12) << mtrx[i][j];
        }
        cout << endl;
    }
}

void findMin(int m, int n, int** mtrx_temp)
{
    int min_i,min_j;
    unsigned int flag;
    int min = 2147483647;
    min_i = 0;
    min_j = 0;
    flag = 0;
    if(m == 1 && n == 1)
    {
        if(mtrx_temp[0][0] < 0)
        {
            cout << "Matrix is 1*1 and has only negative element,now that task cant be reached" << endl;
            return;
        }
        else 
        {
            cout << "Matrix is 1*1,now that Min positive element is " << mtrx_temp[0][0] << " with coords:" << endl;
            cout << "line: 1; column: 1" << endl;
            return;
        }
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(mtrx_temp[i][j] > 0)
            {
                flag = 1;
                if(mtrx_temp[i][j] < min)
                {
                    min = mtrx_temp[i][j];
                    min_i = i;
                    min_j = j; 
                }
            }
        }
    }
    if(flag == 0)
    {
        cout << "All matrix is negative,now that task cant be reached\n";
        return;
    }
    cout << "Min positive element is " << " with coords:\n";
    cout << "line: " << min_i + 1 << "; column: " << min_j + 1 << endl;
}
void sortMatrix(int m, int n, int** mtrx, int** mtrx_temp)
{
    if(n == 1 && m == 1)
    {
        mtrx_temp[0][0] = mtrx[0][0];
        return;
    }
    int tmp;
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <m; j++)
        {
            tmp = 0;
            if(i > 0)
            {
                tmp += mtrx[i-1][j];
                count++;
                if(j > 0)
                {
                tmp += mtrx[i-1][j-1];
                count++;
                }
                    if(j < m-1)
                    {
                        tmp += mtrx[i-1][j+1];
                        count++;
                    }
            }
            if(i < n-1)
            {
                tmp += mtrx[i+1][j];
                count++;
                if(j > 0)
                {
                    tmp += mtrx[i+1][j-1];
                    count++;
                }
                if(j < m-1)
                {
                    tmp += mtrx[i+1][j+1];  
                    count++; 
                }                    
            }
            if(j > 0)
            {
                tmp += mtrx[i][j-1];
                count++;
            }
            if(j < m-1)                
            {
                tmp += mtrx[i][j+1];
                count++;
            }
            mtrx_temp[i][j]=tmp / count;
        }
    }
    cout << "Sorted matrix:\n";
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << setw(12) << mtrx_temp[i][j];
        }
        cout << endl;
    }
}