#ifndef HIGHERCARD_FUNC_H
#define HIGHERCARD_FUNC_H

//structs
struct GameInfo {
    struct Card {
        char name[10];
        char suit[10];
        int value;
    };
    struct Player {
        char name[50];
        int firstcard = 0;
        int secondcard = 0;
        int score = 0;
    };
};

//enums
enum suits {
    HEARTS = 0,
    DIAMONDS = 1,
    CLUBS = 2,
    SPADES = 3
};
enum cardNames {

    Two = 0,
    Three = 1,
    Four = 2,
    Five = 3,
    Six = 4,
    Seven = 5,
    Eight = 6,
    Nine = 7,
    Ten = 8,
    Jack = 9,
    Queen = 10,
    King = 11,
    Ace = 12

};

//typedefs

//functions
void fillDeck(GameInfo::Card &card, const char *name, const char *suit, int value);
void makeDeck(GameInfo::Card deck[], int numCards, int cardIndex, const char* cardNamesStr[], const char* suitsStr[]);
void randomiseDeck(GameInfo::Card deck[], int numCards);
void printDeck(GameInfo::Card deck[], int numCards);
char *getName(char *name);
void print_welcome();
void dealCard(GameInfo::Card deck[], int numCards, GameInfo::Player &player);


//variables (global)
extern bool debug;



#endif //HIGHERCARD_FUNC_H
