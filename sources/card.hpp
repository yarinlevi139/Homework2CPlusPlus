#ifndef CARDGAME_CARD_H
#define CARDGAME_CARD_H
#include "iostream"

using namespace std;

extern string name_container[13];
extern string color_container[4];

class Card{
public: // declare the attributes as public
    int value; // use semicolons to end the declarations
    string name;
    Card(int value, string name); // define a constructor to initialize the attributes
    void print_card();
};






#endif //CARDGAME_CARD_H