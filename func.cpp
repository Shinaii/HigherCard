#include "func.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

void fillDeck(GameInfo::Card &card, const char *name, const char *suit, int value) {
    strcpy(card.name, name);
    strcpy(card.suit, suit);
    if (strcmp(name, "Jack") == 0 || strcmp(name, "Queen") == 0 || strcmp(name, "King") == 0) {
        card.value = 10;
    } else if (strcmp(name, "Ace") == 0) {
        card.value = 11;
    } else {
        card.value = value;
    }
}

void makeDeck(GameInfo::Card deck[], int numCards, int cardIndex, const char* cardNamesStr[], const char* suitsStr[]) {
    for(int i = suits::HEARTS; i <= suits::SPADES; i++) {
        for(int j = cardNames::Two; j <= cardNames::Ace; j++) {
            fillDeck(deck[cardIndex], cardNamesStr[j], suitsStr[i], j+2);
            cardIndex++;
        }
    }
}

void randomiseDeck(GameInfo::Card deck[], int numCards) {
    srand(time(0));
    for(int i = 0; i < numCards; i++) {
        int j = rand() % numCards;
        GameInfo::Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void printDeck(GameInfo::Card deck[], int numCards) {
    for(int i = 0; i < numCards; i++) {
        std::cout << deck[i].name << " of " << deck[i].suit << " has a value of " << deck[i].value << std::endl;
    }
}

char *getName(char *name) {
    std::cout << "Enter your name: ";
    std::cin.getline(name, 50);
    return name;
}

void print_welcome() {
    std::cout << "Welcome to Higher Card!" << std::endl;
    std::cout << "The game is simple, you will be dealt a card and so will your opponent." << std::endl;
    std::cout << "The player with the highest card wins the round." << std::endl;
    std::cout << "The game will continue until you decide to quit." << std::endl;
    std::cout << "Good luck!" << std::endl;
}

void dealCard(GameInfo::Card deck[], int numCards, GameInfo::Player &player) {
    do {
        int cardIndex = rand() % numCards;
        if (player.firstcard == 0) {
            player.firstcard = deck[cardIndex].value;
        } else {
            player.secondcard = deck[cardIndex].value;
        }
        player.score = player.firstcard + player.secondcard;
        std::cout << player.name << " has been dealt the " << deck[cardIndex].name << " of " << deck[cardIndex].suit
                  << std::endl;
        for (int i = cardIndex; i < numCards - 1; i++) {
            deck[i] = deck[i + 1];
        }
    } while (player.firstcard == 0 || player.secondcard == 0);
    numCards--;
}
