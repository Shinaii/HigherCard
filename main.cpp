#include <iostream>
#include "func.h"
#include <thread>

bool debug = true;

int main() {

    int numCards = 52;
    GameInfo::Card deck[numCards];

    const char* cardNamesStr[] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
    const char* suitsStr[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    int cardIndex = 0;

    for(int i = suits::HEARTS; i <= suits::SPADES; i++) {
        for(int j = cardNames::Two; j <= cardNames::Ace; j++) {
            fillDeck(deck[cardIndex], cardNamesStr[j], suitsStr[i], j+2);
            cardIndex++;
        }
    }

    randomiseDeck(deck, numCards);


    if(debug == true) {
        printDeck(deck, numCards);
    }

    print_welcome();

    GameInfo::Player player1;
    GameInfo::Player player2;

    std::cout << "Player 1" << std::endl;
    getName(player1.name);
    std::cout << "Player 2" << std::endl;
    getName(player2.name);
    system("cls");


    std::cout << "Welcome " << player1.name << " and " << player2.name << "!" << std::endl;
    std::cout << "The Card Dealer gives out Cards now!" << std::endl;

    while(true) {
        //1st card
        std::cout << player1.name << " press enter to be dealt a card... ";
        std::cin.get();
        dealCard(deck, numCards, player1);

        //1st card
        std::cout << player2.name << " press enter to be dealt a card... ";
        std::cin.get();
        dealCard(deck, numCards, player2);
        std::cout << "\n";

        std::cout << player1.name << " has a score of " << player1.score << std::endl;
        std::cout << player2.name << " has a score of " << player2.score << std::endl;

        if(player1.score > player2.score) {
            std::cout << player1.name << " wins!" << std::endl;
        } else if(player1.score < player2.score) {
            std::cout << player2.name << " wins!" << std::endl;
        } else {
            std::cout << "It's a draw!" << std::endl;
        }

        std::cout << "Do you want to play again? (y/n): ";
        char playAgain;
        std::cin >> playAgain;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (playAgain == 'y') {
            player1.firstcard = 0;
            player1.secondcard = 0;
            player1.score = 0;

            player2.firstcard = 0;
            player2.secondcard = 0;
            player2.score = 0;
        }
        if(playAgain == 'n') {
            break;
        }
    }










}
