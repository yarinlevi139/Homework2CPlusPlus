#include "player.hpp"
#include "vector"
Player::Player() {
    this->name = "";
    this->already_playing = false;
    this->isWinner = false;
}

Player::Player(string name) {
    this->name = name;
}
int Player::stacksize() {
    return this->cards.size();
}

int Player::cardesTaken() {
    return this->cards_taken.size();
}
