#ifndef CARDGAME_PLAYER_H
#define CARDGAME_PLAYER_H
#include "iostream"
#include "stdio.h"
using namespace std;

class Player {
public:
    string name;
    bool already_playing;
    Player();
    Player(string name);

    int stacksize();

    int cardesTaken();
};


#endif
