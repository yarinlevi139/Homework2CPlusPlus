#include "player.hpp"

Player::Player() {
    this->name = "";
    this->already_playing = false;
}

Player::Player(string name) {
    this->name = name;
}
int Player::stacksize() {
    return 0;
}

int Player::cardesTaken() {
    return 0;
}
