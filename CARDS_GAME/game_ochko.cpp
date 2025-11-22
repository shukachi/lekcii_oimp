#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

enum Errors
{
    SUCCESS,
    UNKOWN_RANK,
    UNKOWN_SUIT,
    EMPTY_FILE,
    ERROR_INPUT
};

enum Suits
{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
};

const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;
    
class Cards
{
private:
    int card_number;
    Suits suit;
public:
    Cards() 
        {}
    void set_card(int n, Suits s)
    {
        card_number = n;
        suit = s;
    }
    void show_card();
};

void Cards::show_card()
{
    if (card_number >= 2 && card_number <= 10)
    {
        cout << card_number;
    }
    else 
    {
        switch(card_number)
        {
            case jack:
                cout << 'J';
                break;
            case queen:
                cout << 'Q';
                break;
            case king:
                cout << 'K';
                break;
            case ace:
                cout << 'A';
                break;
        }
    }
    switch (suit)
    {
        case CLUBS:
            cout << "♣"; 
            break;
        case DIAMONDS:
            cout << "♦"; 
            break;
        case HEARTS:
            cout << "♥"; 
            break;
        case SPADES:
            cout << "♠"; 
            break;
    }
}


void tasovka_deck(Cards deck[]);
void show_deck(Cards deck[]);
inline void clear_input();
bool next_game();


int main()
{
    int a;
    #ifdef _WIN32
    system("chcp 65001 > nul"); 
    #endif
    Cards main_deck[52];
    int i;
    srand(time(0));
    for (i = 0; i < 52; i++)
    {
        int number = (i % 13) + 2;
        Suits suit = static_cast<Suits>(i / 13);
        main_deck[i].set_card(number,suit);
    }
    cout << "\nDeck:\n";
    show_deck(main_deck);
    tasovka_deck(main_deck);
    //cout << "\033[2J\033[1;1H";
    cout << "\nShuffled deck:\n";
    show_deck(main_deck);
    cin >> a;
    cout << "\033[1;1H";
    system("pause");

    return SUCCESS;
}

void tasovka_deck(Cards deck[])
{
    srand(time(0));
    for(int i = 0; i < 52; i++)
    {
        int j = rand() % 52;
        Cards temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void show_deck(Cards deck[])
{
    for (int i = 0; i < 52; i++)
    {
        deck[i].show_card();
        cout << " ";
        if (!((i + 1) % 13))
        {
            cout << endl;
        }
    }
}

inline void clear_input()
{
    cout << "\033[2J\033[1;1H";
    cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
}

bool next_game()
{
    char answer;
    cout << "\nDo you want to continue? (y/n): ";
    cin >> answer;
}

