#ifndef CARDGAME_CARD_H
#define CARDGAME_CARD_H
#include "iostream"
#include "array"
using namespace std;

extern const array<string,13> name_container;
extern const array<string,4> color_container;

class Card{
public: // declare the attributes as public
    int value; // use semicolons to end the declarations
    string name;
    Card(int value, string name); // define a constructor to initialize the attributes
    void print_card();
};






#endif //CARDGAME_CARD_H