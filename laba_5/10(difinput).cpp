#include <iostream>
#include <string>
#include <cmath>
#include <conio.h>
#include <windows.h>
using namespace std;


enum ExitCode
{
    SUCCESS,
    INVALID_INPUT
};

bool is_all_digits(const string& s);
void clearMemmory(string* a, string* b, string* c);
void output_str(string str);
int words_number(string& str);
int digit_number(string* all_words, int& word_count);
void full_str_elements(char* str_elements, string& str);
string sort_str(int& digit_count, int& other_count, string* digit_words, string* other_words, char* str_elements);
void full_digit_words_AND_other_words(string* digit_words, string* other_words, string* all_words, int& word_count);
void separate_str(string* all_words, string& str);
int elem_number(string& str);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string str;

    getline(cin, str);

    int word_count = words_number(str);
    int elem_count = elem_number(str);

    char* str_elements = new char[elem_count];
    full_str_elements(str_elements,str);

    string* all_words = new string[word_count];

    separate_str(all_words, str);

    int digit_count = digit_number(all_words,word_count);
    int other_count = word_count - digit_count;

    string* digit_words = new string[digit_count];
    string* other_words = new string[other_count];

    full_digit_words_AND_other_words(digit_words,other_words,all_words,word_count);

    string result_str = sort_str(digit_count,other_count,digit_words,other_words,str_elements);
    
    cout << "Result string:\n";
    output_str(result_str);
    clearMemmory(all_words, digit_words, other_words);
    system("pause");
    return SUCCESS;
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

inline void output_str(string str)
{
    cout << str << endl;
    cout << endl;
}

int words_number(string& str)
{
    const string delimiters = ". !?,:;-()\"";
    int word_count = 0;
    size_t start_pos = 0;
    size_t end_pos;
    while ((end_pos = str.find_first_of(delimiters, start_pos)) != string::npos)
    {
        if (end_pos > start_pos) 
        { 
            word_count++;
        }
        start_pos = end_pos + 1;
    }
    if (start_pos < str.length()) 
    {
        word_count++;
    }
    return word_count;
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

void full_str_elements(char* str_elements, string& str)
{
    const string delimiters = ". !?,:;-()\"";
    int temp_idx = 0;
    for (char c : str)
    {
        if (delimiters.find(c) != string::npos)
        {
            str_elements[temp_idx] = c;
            temp_idx++;
        }
    }
}

string sort_str(int& digit_count, int& other_count, string* digit_words, string* other_words, char* str_elements)
{
    string result_str;
    int digit_cursor = 0;
    int other_cursor = 0;
    bool position_is_odd = true;
    int temp_elem = 0;

    while (digit_cursor < digit_count && other_cursor < other_count)
    {
        if (position_is_odd)
        {
            result_str += digit_words[digit_cursor++];
        }
        else
        {
            result_str += other_words[other_cursor++];
        }
        position_is_odd = !position_is_odd;

        if (digit_cursor < digit_count || other_cursor < other_count) 
        {
            result_str += str_elements[temp_elem++];
        }
    }

    while (digit_cursor < digit_count) 
    {
        result_str += str_elements[temp_elem++];
        result_str += digit_words[digit_cursor++];
    }
    while (other_cursor < other_count) 
    {
        result_str += str_elements[temp_elem++];
        result_str += other_words[other_cursor++];
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

void separate_str(string* all_words, string& str)
{
    int current_word_idx = 0;
    const string delimiters = ". !?,:;-()\"";
    size_t start_pos = 0;
    size_t end_pos;
    while ((end_pos = str.find_first_of(delimiters, start_pos)) != string::npos)
    {
        if (end_pos > start_pos) 
        { 
            all_words[current_word_idx++] = str.substr(start_pos, end_pos - start_pos);
        }
        start_pos = end_pos + 1;
    }
    if (start_pos < str.length()) 
    { 
        all_words[current_word_idx] = str.substr(start_pos);
    }
}

int elem_number(string& str)
{
    const string delimiters = ". !?,:;-()\"";
    int elem_count = 0;
    for (char c : str)
    {
        if (delimiters.find(c) != string::npos)
        {
            ++elem_count;
        }
    }
    return elem_count;
}