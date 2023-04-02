#include "card.hpp"
#include "array"
const array<string,13> name_container= {"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};
const array<string,4> color_container = {"Heart","Spades","Diamonds","Clubs"};

Card::Card(int value, string name) {
    this->value = value;
    this->name = name;
}

void Card::print_card() {
    cout << "The value is: " << this->value << " The name is " << this->name << "\n";
}