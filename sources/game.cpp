#include "game.hpp"
#include "player.hpp"
#include "card.hpp"
#include "stdio.h"
#include "iostream"
#include "algorithm"
#include "random"

void print_card_container(vector <Card> &card_container) {
    for (size_t i = 0; i < card_container.size(); ++i) {
        cout << card_container[i].name << " valued at " << card_container[i].value << "\n";
    }
}

void print_player_stack(Player p) {
    while (!p.cards.empty()) {
        p.cards.top().print_card();
        p.cards.pop();
    }
}

void create_card_container(vector <Card> &card_container) {
    for (size_t i = 0; i < 13; ++i) {
        for (size_t j = 0; j < 4; ++j) {
            string name = name_container[i] + " " + color_container[j];
            if (name_container[i] == "Ace")
                card_container.push_back(Card(14, name));
            else
                card_container.push_back(Card(i + 1, name));
        }
    }
}

void divide_cards(Player &p1, Player &p2, vector <Card> &card_container) {
    for (size_t i = 0; i < card_container.size(); ++i) {
        if (i % 2 == 0)
            p1.cards.push(card_container[i]);
        else
            p2.cards.push(card_container[i]);
    }
}
Player dummy1("");
Player dummy2("");
Game::Game() : p1(dummy1),p2(dummy2) {

}


Game::Game(Player &player1, Player &player2): p1(player1),p2(player2) {
    if (p1.stacksize() > 0 || p2.stacksize() > 0) {
        throw std::invalid_argument("One has already registered");
    }
    this->p1.already_playing = true;
    this->p2.already_playing = true;
    create_card_container(this->card_container);
    std::random_device r;
    std::seed_seq seed{r(), r(), r(), r(), r(), r(), r(), r()};
    std::mt19937 eng(seed);
    std::shuffle(card_container.begin(), card_container.end(), eng);
    divide_cards(this->p1, this->p2, card_container);
    this->count_p1_wins = 0, this->count_p2_wins = 0 , this->count_draws = 0 , this->count_division = 0;
}

void Game::printLog() {
    std::list<string>::iterator it;
    for (it = this->log.begin(); it != this->log.end(); ++it) {
        std::cout << *it;
    }
}

void Game::playTurn() {
    if(ended)
        throw invalid_argument("Game as already ended");
    this->log.push_back( this->p1.name + " Plays : " + this->p1.cards.top().name + "\n");
    this->log.push_back( this->p2.name +" Plays : " + this->p2.cards.top().name + "\n");
    Card c1 = p1.cards.top();
    Card c2 = p2.cards.top();
    this->p1.cards.pop();
    this->p2.cards.pop();

    if ((c1.value == 14 && c2.value == 2) || (c2.value == 14 && c2.value == 2)) {
        if (c1.value == 14 && c2.value == 2) {
            this->count_p2_wins++;
            this->p2.cards_taken.push_back(c1);
            this->p2.cards_taken.push_back(c2);
        } else {
            this->count_p1_wins++;
            this->p1.cards_taken.push_back(c1);
            this->p1.cards_taken.push_back(c2);
        }
    } else if (c1.value > c2.value) {
        this->count_p1_wins++;
        this->p1.cards_taken.push_back(c1);
        this->p1.cards_taken.push_back(c2);
    } else if (c1.value < c2.value) {
        this->count_p2_wins++;
        this->p2.cards_taken.push_back(c1);
        this->p2.cards_taken.push_back(c2);
    } else {
        while (c1.value == c2.value) {
            this->count_draws++;
            this->table.push_back(c1);
            this->table.push_back(c2);
            if(p1.stacksize()!=0 && p2.stacksize()!=0) {
                this->log.push_back( this->p1.name + " Plays : " + this->p1.cards.top().name + "\n");
                this->log.push_back( this->p2.name +" Plays : " + this->p2.cards.top().name + "\n");
                this->table.push_back(p1.cards.top());
                this->table.push_back(p2.cards.top());
                p1.cards.pop();
                p2.cards.pop();
            }
            else
                break;
            if (p1.stacksize() == 0 && p2.stacksize() == 0) {
                std::random_device r;
                std::seed_seq seed{r(), r(), r(), r(), r(), r(), r(), r()};
                std::mt19937 eng(seed);
                std::shuffle(table.begin(), table.end(), eng);
                divide_cards(this->p1, this->p2, table);
                this->count_division++;
            }
            if(p1.stacksize()!=0 && p2.stacksize()!=0) {
                this->log.push_back( this->p1.name + " Plays : " + this->p1.cards.top().name + "\n");
                this->log.push_back( this->p2.name +" Plays : " + this->p2.cards.top().name + "\n");
                c1 = p1.cards.top();
                c2 = p2.cards.top();
                this->p1.cards.pop();
                this->p2.cards.pop();
            }
            else
                break;
        }
        if (c1.value > c2.value) {
            this->count_p1_wins++;
            while (!this->table.empty()) {
                p1.cards_taken.insert(p1.cards_taken.end(), this->table.begin(), this->table.end());
                this->table.erase(this->table.begin(), this->table.end());
            }
        } else if (c1.value<c2.value){
            this->count_p2_wins++;
            while (!this->table.empty()) {
                p2.cards_taken.insert(p2.cards_taken.end(), this->table.begin(), this->table.end());
                this->table.erase(this->table.begin(), this->table.end());
            }
        }

    }
}

void Game::playAll() {
    if(ended)
        throw invalid_argument("Game has already ended");
    while (p1.stacksize() > 0 && p2.stacksize() > 0)
        playTurn();
    ended = true;
}

void Game::printLastTurn() {
    list<string> temp = this->log;
    cout << temp.back();
    temp.pop_back();
    cout << temp.back();
    temp.pop_back();
}

void Game::printStats() {
    cout << "Number of wins of: " << this->p1.name << " is " << this->count_p1_wins << "\n";
    cout << "Number of wins of: " << this->p2.name << " is " << this->count_p2_wins << "\n";
    cout << "Number of draws is: " << this->count_draws << "\n";
    cout << "Number of divisions is: " << this->count_division << "\n";
}

void Game::printWiner() {
    if (p1.cardesTaken() > p2.cardesTaken())
        cout << this->p1.name << "wins!!!!!!!!!!!!!!!!!!!!!!\n";
    else
        cout << this->p1.name << "wins!!!!!!!!!!!!!!!!!!!!!!\n";
}
