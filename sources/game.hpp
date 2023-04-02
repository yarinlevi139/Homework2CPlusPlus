#ifndef CARDGAME_GAME_H
#define CARDGAME_GAME_H
#include "iostream"
#include "player.hpp"
using namespace std;
namespace ariel{}
using namespace  ariel;

class Game {
public:
    Player p1;
    Player p2;

    Game(){}
    Game(Player player1, Player player2);

    void playTurn();

    void printLastTurn();

    void playAll();

    void printWiner();

    void printLog();

    void printStats();
};


#endif //CARDGAME_GAME_H
