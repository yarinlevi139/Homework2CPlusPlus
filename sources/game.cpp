#include "game.hpp"
#include "player.hpp"

Game::Game(Player player1, Player player2) {
    if(p1.stacksize()>0 || p2.stacksize()>0) {
       throw std::invalid_argument("One has already registered");
    }
    this->p1 = player1;
    this->p2 = player2;
    this->p1.already_playing = true;
    this->p2.already_playing = true;
}

void Game::printLog() {

}

void Game::playAll() {

}
void Game::playTurn() {

}
void Game::printLastTurn() {

}
void Game::printStats() {

}
void Game::printWiner() {

}
