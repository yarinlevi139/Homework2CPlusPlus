#ifndef CARDGAME_PLAYER_H
#define CARDGAME_PLAYER_H
#include "iostream"
#include "stdio.h"
#include "stack"
#include "vector"
#include "card.hpp"

using namespace std;


class Player {
public:
    string name;
    bool already_playing;
    bool isWinner;
    stack<Card> cards;
    vector<Card> cards_taken;
    Player();
    Player(string name);

    int stacksize();

    int cardesTaken();
};


#endif
