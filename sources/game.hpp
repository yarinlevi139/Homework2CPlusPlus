#ifndef CARDGAME_GAME_H
#define CARDGAME_GAME_H
#include "iostream"
#include "player.hpp"
#include "stack"
#include "vector"
#include "list"

using namespace std;
namespace ariel{}
using namespace  ariel;

class Game {
public:
    Player &p1;
    Player &p2;
    vector<Card> card_container;
    vector<Card> table;
    list<string> log;
    int count_p1_wins;
    int count_p2_wins;
    int count_draws;
    int count_division;
    bool ended;
    Game();
    Game(Player &player1, Player &player2);

    void playTurn();

    void printLastTurn();

    void playAll();

    void printWiner();

    void printLog();

    void printStats();
};


#endif //CARDGAME_GAME_H
