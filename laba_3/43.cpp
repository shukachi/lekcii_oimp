#include <iostream>
#include <cmath>
#include <limits>
#include <time.h>
using namespace std;

enum ExitCode 
{
SUCCESS,
INVALID_INPUT 
};

void getEnter();
bool aproove();
void choose(int size,double arr[]);
void multiply(int size,double arr[]);
void bubbleSort(int size,double arr[]);
void unic_num(int size,double arr[]);
void clear_input();
void random(int size,double arr[]);
void custom(int size,double arr[]);
void output_arr(int size,double arr[]);
void sort_arr(int size,double arr[]);

int main()
{
    const int m_size = 1000;
    double arr[m_size];
    int n;
    cout << "\nInput size of array (n): ";
    cin >> n;

    while(cin.fail() || n < 1 || n > m_size)
    {
        cout << "\nInvalid input. Please enter a number between 1 and " << m_size << ": ";
        clear_input();
        cin >> n;
    }
    choose(n, arr);

    double temp_arr[m_size];

    copy(arr, arr + n, temp_arr);
    bubbleSort(n, temp_arr); 
    unic_num(n, temp_arr);   

    copy(arr, arr + n, temp_arr);
    multiply(n, temp_arr); 

    copy(arr, arr + n, temp_arr);
    sort_arr(n, temp_arr);

    getEnter();

    return SUCCESS;
}
void getEnter()	
{
	cout << "\n\nPress Enter to finish...";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
	cin.get(); 
}

void output_arr(int size,double arr[]) 
{
    for(int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    cout << endl;
}

void sort_arr(int size, double arr[])
{
    cout << "\n\nSorted array with negative numbers moved to the front:";
    int write_idx = 0; 
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            double temp = arr[write_idx];
            arr[write_idx] = arr[i];
            arr[i] = temp;
            write_idx++;
        }
    }
    cout << endl;
    output_arr(size, arr);
}


void multiply(int size, double arr[])
{
    if (size == 1)
    {
        cout << "\nArray consists of 1 element: " << arr[0] << endl;
        return;
    }
    int max_idx = 0;
    long double result = 1.0;
    for(int i = 0; i < size; i++)
    {
        if(abs(arr[i]) > abs(arr[max_idx]))
        {
            max_idx = i;
        }
    }
    if((max_idx == (size - 1)) && (size != 1))
    {
        cout << "Undefined. Nothing after max element";
        return;
    }
    for(int i = max_idx + 1; i < size; i++)
    {
        result *= arr[i];
    }
    cout << "\nMultiplication: " << result;
}

void unic_num(int size, double arr[])
{
    if (size == 1)
    {
        cout << "\nArray consists of 1 element: " << arr[0] << endl;
        return;
    }
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            k++;
        }
    }
    cout << "\nNumber of unique elements: " << k << endl;    
}

void bubbleSort(int size,double arr[]) 
{
    for (int i = 0; i < size - 1; ++i) 
    {
        for (int j = 0; j < size - i - 1; ++j) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "\n\nSorted (by bubble sort) array: ";
    output_arr(size,arr);
}

inline void clear_input()
{
    cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
}

void random(int size, double arr[])
{
    int a,b;
    cout << "\nSet the interval [a,b] with space: ";
    cin >> a >> b;
    while((cin.fail() || a > b)) 
    {
        cout << "\nInvalid interval!" << endl;
        clear_input();
        cin >> a >> b;
    }
    srand(time(0)); 
    cout << "\nRandom array: ";
    for (int i = 0; i < size; i++)
    {
        arr[i] = a + rand() % (b - a + 1);
        cout << arr[i] << " ";
    }
}

void custom(int size, double arr[])
{
    cout << "\nEnter array elements: ";
    for(int i = 0; i < size; i++)
    {
    cin >> arr[i];
    cout << arr[i] << " ";
        while(cin.fail())
        {
            cout << "\nInvalid input. Please enter double values." << endl;
            clear_input();
            if(aproove())
            {
                cout << "\nEnter array elements: ";
                break;
            }
            else
            {
                exit(INVALID_INPUT);
            }
        }
    }
}

void choose(int size, double arr[])
{
    char num;
    cout << "How do you want to fill the array?" << endl;
    cout << "Choose an option:" << endl;
    cout << "1. Option random (write 1)" << endl;
    cout << "2. Option custom (write 2)\n" << endl;
    cin >> num;

    switch (num)
    {
    case '1':
        random(size, arr);
        break;
    case '2':
        custom(size, arr);
        break;
    default:
        if(num != '1' || num != '2' || cin.fail())
        {
            cout << "\nInvalid input. Please enter 1 or 2." << endl;
            clear_input();
            if(aproove())
            {
                choose(size, arr);
            } 
            else
            {
                exit(INVALID_INPUT);
            } 
        }
    }
}

bool aproove()
{
    char answer;
    cout << "\nDo you want to continue? (y/n): ";
    cin >> answer;
    switch (answer)
    {
    case 'y':
    return true;
        break;
    case 'n':
    return false;
        break;
    default:
        cout << "\nInvalid input. Please enter 'y' or 'n'." << endl;
        clear_input();
        return aproove(); 
    }
}