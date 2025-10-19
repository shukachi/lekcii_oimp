#include <iostream>
#include <string>
#include <cmath>
#include <windows.h>
using namespace std;

enum ExitCode
{
    SUCCESS,
    WARNING
};

void clear_input();
bool aproove();
char elemSepartor();
bool is_all_digits(const string& s);
void clearMemmory(string* a, string* b, string* c);
void output_str(char el, string str);
string input_str(char& elem);
int words_number(string& str, char& elem);
int digit_number(string* all_words, int& word_count);
string sort_str(int& digit_count, int& other_count, string* digit_words, string* other_words, char& elem);
void full_digit_words_AND_other_words(string* digit_words, string* other_words, string* all_words, int& word_count);
void separate_str(string* all_words, string& str, char& elem);
void warning(string& str, char& elem);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char elem = elemSepartor();
    string str = input_str(elem);
    warning(str,elem);
    cout << "Your string:" << endl;
    output_str(elem, str);
    int word_count = words_number(str, elem);

    string* all_words = new string[word_count];

    separate_str(all_words, str, elem);

    int digit_count = digit_number(all_words,word_count);
    int other_count = word_count - digit_count;

    string* digit_words = new string[digit_count];
    string* other_words = new string[other_count];

    full_digit_words_AND_other_words(digit_words,other_words,all_words,word_count);

    string result_str = sort_str(digit_count,other_count,digit_words,other_words,elem);
    
    cout << "Result string:\n";
    output_str(elem, result_str);
    clearMemmory(all_words, digit_words, other_words);
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

char elemSepartor()
{
    cout << "Enter punctuation mark: ";
    string line;
    while (true)
    {
        getline(cin, line);
        if (line.length() == 1)
        {
            return line[0]; 
        }
        else
        {
            cout << "Invalid input. Please enter exactly one char!\n";
            cout << "Enter punctuation mark: ";
        }
    }
}

bool is_all_digits(const string& s)
{
    if (s.empty()) 
    {
        return false;
    }
    for (char c : s) 
    {
        if (!isdigit(c)) 
        {
            return false;
        }
    }
    return true;
}

inline void clearMemmory(string* a, string* b, string* c)
{
    delete[] a;
    delete[] b;
    delete[] c;
}

inline void output_str(char elem, string str)
{
    cout << elem << str << elem << endl;
    cout << endl;

}

string input_str(char& elem)
{
    cout << "Enter word without separator:";
    cout << endl;
    string str,newstr;
    cin >> str;
    while (aproove())
    {
        cout << "Enter word without separator:\n";
        cin >> newstr;
        str = str + elem + newstr; 
    }
    return str;
}

int words_number(string& str, char& elem)
{
    int word_count = 0;
    for (char c : str) 
    {
        if (c == elem) 
        {
            word_count++;
        }
    }
    return ++word_count;
}

int digit_number(string* all_words, int& word_count)
{   
    int digit_count = 0;
    for (int i = 0; i < word_count; ++i) 
    {
        if (is_all_digits(all_words[i])) 
        {
            digit_count++;
        }
    }
    return digit_count;
}

string sort_str(int& digit_count, int& other_count, string* digit_words, string* other_words, char& elem)
{
    string result_str;
    int digit_cursor = 0;
    int other_cursor = 0;
    bool position_is_odd = true;

    while (digit_cursor < digit_count && other_cursor < other_count)
    {
        if (position_is_odd)
        {
            result_str += digit_words[digit_cursor++] + elem;
        }
        else
        {
            result_str += other_words[other_cursor++] + elem;
        }
        position_is_odd = !position_is_odd;
    }

    while (digit_cursor < digit_count) 
    {
        result_str += digit_words[digit_cursor++] + elem;
    }
    while (other_cursor < other_count) 
    {
        result_str += other_words[other_cursor++] + elem;
    }

    if (!result_str.empty()) 
    {
        result_str.pop_back();
    }

    return result_str;
}

void full_digit_words_AND_other_words(string* digit_words, string* other_words, string* all_words, int& word_count)
{
    int d_idx = 0, o_idx = 0;
    for (int i = 0; i < word_count; ++i)
    {
        if (is_all_digits(all_words[i]))
        {
            digit_words[d_idx++] = all_words[i];
        }
        else
        {
            other_words[o_idx++] = all_words[i];
        }
    }
}

void separate_str(string* all_words, string& str, char& elem)
{
    int current_word_idx = 0;
    int start_pos = 0;
    int end_pos;

    while ((end_pos = str.find(elem, start_pos)) != string::npos)
    {
        all_words[current_word_idx++] = str.substr(start_pos, end_pos - start_pos);
        start_pos = end_pos + 1;
    }
    all_words[current_word_idx] = str.substr(start_pos); 
}

void warning(string& str, char& elem)
{
    if(str.find_first_not_of(elem,0) == string::npos)
    {
        cout << "String consists of only elements-separators" << endl;
        cout << "Task cant be reached!" << endl;
        system("pause");
        exit(0);
    }
}