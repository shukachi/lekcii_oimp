#include <iostream>
#include <cmath>
#include <limits>
#include <time.h>
#include <conio.h>
using namespace std;

enum ExitCode 
{
SUCCESS,
INVALID_INPUT 
};

char choose_design();
void write_design(char elem);
void getEnter(char elem);
bool aproove();
void choose(int size,double arr[],char elem);
void multiply(int size,double arr[],char elem);
void bubbleSort(int size,double arr[],char elem);
void unic_num(int size,double arr[],char elem);
void clear_input();
void random(int size,double arr[],char elem);
void custom(int size,double arr[],char elem);
void output_arr(int size,double arr[]);
void sort_arr(int size,double arr[],char elem);

int main()
{
    const int m_size = 100000;
    double arr[m_size];
    int n;
    char design_char = choose_design();
    write_design(design_char);
    cout << "\nInput size of array (n): ";
    cin >> n;
    cout << endl;

    while(cin.fail() || n < 1 || n > m_size)
    {
        write_design(design_char);
        cout << "\nInvalid input. Please enter a number between 1 and " << m_size << ": ";
        clear_input();
        cin >> n;
        cout << endl;
    }
    choose(n, arr,design_char);

    double temp_arr[m_size];

    copy(arr, arr + n, temp_arr);
    bubbleSort(n, temp_arr,design_char); 
    unic_num(n, temp_arr,design_char);   

    copy(arr, arr + n, temp_arr);
    multiply(n, temp_arr,design_char); 

    copy(arr, arr + n, temp_arr);
    sort_arr(n, temp_arr,design_char);

    getEnter(design_char);

    return SUCCESS;
}
void getEnter(char elem)	
{
    write_design(elem);
    cout << "\n\n";
    write_design(elem);
	cout << "Press Enter to finish...\n";
    write_design(elem);
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

void sort_arr(int size, double arr[],char elem)
{
    cout << "\nSorted array with negative numbers moved to the front: ";
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
    output_arr(size, arr);
    cout << endl;
}


void multiply(int size, double arr[],char elem)
{
    if (size == 1)
    {
        write_design(elem);
        cout << "\nArray consists of 1 element: " << arr[0] << "\n" << endl;
        write_design(elem);
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
        write_design(elem);
        cout << "\nUndefined. Nothing after max element" << "\n" << endl;
        write_design(elem);
        return;
    }
    for(int i = max_idx + 1; i < size; i++)
    {
        result *= arr[i];
    }
    if(result == -0)
    {
        result = 0;
        write_design(elem);
        cout << "\nMultiplication: " << result << "\n" << endl;
        write_design(elem);
        return;
    }
    write_design(elem);
    cout << "\nMultiplication: " << result << "\n" << endl;
    write_design(elem);
}

void unic_num(int size, double arr[],char elem)
{
    if (size == 1)
    {
        write_design(elem);
        cout << "\nArray consists of 1 element: " << arr[0] << "\n" << endl;
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
    write_design(elem);
    cout << "\nNumber of unique elements: " << k << "\n"<< endl;    
}

void bubbleSort(int size,double arr[],char elem) 
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
    write_design(elem);
    cout << "\nSorted (by bubble sort) array: ";
    output_arr(size,arr);
    cout << endl;
}

inline void clear_input()
{
    cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
}

void random(int size, double arr[],char elem)
{
    int a,b;
    cout << "\nSet the interval [a,b] with space: ";
    cin >> a >> b;
    cout << endl;
    while((cin.fail() || a > b)) 
    {
        write_design(elem);
        cout << "\nInvalid interval!" << "\n" << endl;
        write_design(elem);
        clear_input();
        cin >> a >> b;
    }
    srand(time(0)); 
    write_design(elem);
    cout << "\nRandom array: ";
    for (int i = 0; i < size; i++)
    {
        arr[i] = a + rand() % (b - a + 1);
        cout << arr[i] << " ";
    }
    cout << "\n" << endl;
}

void custom(int size, double arr[],char elem)
{
    cout << "\nEnter array elements separated by spaces:" << endl;
    write_design(elem);
    for(int i = 0; i < size; i++)
    {
    cin >> arr[i];
        while(cin.fail())
        {
            write_design(elem);
            cout << "\nInvalid input. Please enter double values." << "\n" << endl;
            write_design(elem);
            clear_input();
            if(aproove())
            {
                write_design(elem);
                cout << "\nEnter array elements:" << endl;
                write_design(elem);
                break;
            }
            else
            {
                exit(INVALID_INPUT);
            }
        }
    }
}

void choose(int size, double arr[],char elem)
{
    char num;
    write_design(elem);
    cout << endl;
    cout << "How do you want to fill the array?" << endl;
    cout << "Choose an option:" << endl;
    cout << "1. Option random (write 1)" << endl;
    cout << "2. Option custom (write 2)\n" << endl;
    write_design(elem);
    cin >> num;
    write_design(elem);

    switch (num)
    {
    case '1':
        random(size, arr,elem);
        break;
    case '2':
        custom(size, arr,elem);
        break;
    default:
        if(num != '1' || num != '2' || cin.fail())
        {
            cout << "\nInvalid input. Please enter 1 or 2." << "\n" << endl;
            write_design(elem);
            clear_input();
            if(aproove())
            {
                choose(size, arr,elem);
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
char choose_design()
{
    char elem;
    cout << "what element do you want to use for design? ";
    elem = getche(); 
    cout << endl;    
    return elem;     
}
void write_design(char elem)
{
    for(int i = 0; i < 50; i++)
    {
        cout << elem;
    }  
    cout << endl;
}