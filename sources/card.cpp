#include "card.hpp"

string name_container[13]= {"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};
string color_container[4] = {"Heart","Spades","Diamonds","Clubs"};

Card::Card(int value, string name) {
    this->value = value;
    this->name = name;
}

void Card::print_card() {
    cout << "The value is: " << this->value << " The name is " << this->name << "\n";
}