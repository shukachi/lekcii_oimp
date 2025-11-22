#include <iostream>
#include <string>
#include <vector>
#include <cctype> 
#include <windows.h>
using namespace std;

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

int main()
{
    #ifdef _WIN32
    system("chcp 65001 > nul");
    #endif

    cout << "Введите строку: ";
    string input_line;
    getline(cin, input_line);

    vector<string> words;
    vector<string> delimiters;
    string current_word;
    string current_delimiters;
    const string delimiter_chars = ". !?,:;-()\"";

    for (char c : input_line)
    {
        if (delimiter_chars.find(c) != string::npos)
        {
            if (!current_word.empty())
            {
                words.push_back(current_word);
                current_word.clear();
            }
            current_delimiters += c;
        }
        else
        {
            if (!current_delimiters.empty())
            {
                delimiters.push_back(current_delimiters);
                current_delimiters.clear();
            }
            current_word += c;
        }
    }
    if (!current_word.empty()) words.push_back(current_word);
    if (!current_delimiters.empty()) delimiters.push_back(current_delimiters);

    vector<string> digit_words;
    vector<string> other_words;

    for (const auto& word : words)
    {
        if (is_all_digits(word))
        {
            digit_words.push_back(word);
        }
        else
        {
            other_words.push_back(word);
        }
    }

    string result_str;
    size_t digit_idx = 0;
    size_t other_idx = 0;
    bool take_digit_next = true;

    while (digit_idx < digit_words.size() || other_idx < other_words.size())
    {
        if (take_digit_next && digit_idx < digit_words.size())
        {
            result_str += digit_words[digit_idx++];
        }
        else if (!take_digit_next && other_idx < other_words.size())
        {
            result_str += other_words[other_idx++];
        }
        if (digit_idx + other_idx -1 < delimiters.size()) 
        {
            result_str += delimiters[digit_idx + other_idx - 1];
        }
        take_digit_next = !take_digit_next; 
    }

    cout << "\nРезультат:\n" << result_str << endl;

    system("pause");
    return 0;
}