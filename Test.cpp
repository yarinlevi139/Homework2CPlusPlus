#include "doctest.h"
#include "sources/game.hpp"
#include "sources/player.hpp"
#include "sources/card.hpp"
#include "string"
using namespace std;

TEST_CASE("Check if game class constructor is OK")
{
    Player p1("player1");
    Player p2("player2");
    CHECK_NOTHROW(Game g(p1, p2));
}

TEST_CASE("Check if both cards taken equal to 52")
{
    Player p1("player1"); //Creating player objects
    Player p2("player2");
    Game g(p1, p2);
    g.playAll();
    bool flag;
    if(p1.cardesTaken() + p2.cardesTaken() == 52)
        flag = true;
    else
        flag = false;
    CHECK(flag);
}

TEST_CASE("Check if players are initialized")
{
    CHECK_NOTHROW(Player p("player"));
    Player p("player");
    CHECK_NOTHROW(p.stacksize());
    CHECK_NOTHROW(p.cardesTaken());
    CHECK(p.stacksize() == 0);
    CHECK(p.cardesTaken() == 0);
}
TEST_CASE("Check Good Division")
{
    Player p1("player1"); //Creating player objects
    Player p2("player2");
    Game g(p1, p2);             //Creating game
    int SIZE = 26;
    bool is_good;             //flag
    if ((p1.stacksize() == SIZE) && (p2.stacksize() == SIZE)) //Checking if both stack of cards is equal to 26 (half)
        is_good = true;
    else
        is_good = false;
    CHECK(is_good);
}

TEST_CASE("Check if both stacks equal 52 in total after creating the game")
{
    Player p1("player1"); //Creating player objects
    Player p2("player2");
    Game g(p1, p2);
    int SIZE = 26;
    CHECK(p1.stacksize() == SIZE);
    CHECK(p2.stacksize() == SIZE);
    CHECK(p1.stacksize() - p2.stacksize() == 0);
}

TEST_CASE("Check if both names correct")
{
    Player p1("player1"); //Creating player objects
    Player p2("player2");
    Game g(p1, p2);
    CHECK(g.p1.name == "player1");
    CHECK(g.p2.name == "player2");
}


TEST_CASE("Check After Turn")
{
    Player p1("player1"); //Creating player objects
    Player p2("player2");
    Game g(p1, p2);
    CHECK_NOTHROW(g.playTurn());
    int SIZE = 26;
    CHECK(p1.stacksize() != SIZE);
    CHECK(p2.stacksize() != SIZE);
}

TEST_CASE("Check if someone won a card after a certain turn")
{
    Player p1("player1"); //Creating player objects
    Player p2("player2");
    Game g(p1, p2);
    int card_won_p1 = p1.cardesTaken();
    int card_won_p2 = p2.cardesTaken();
    CHECK_NOTHROW(g.playTurn());
    bool good;
    if ((p1.cardesTaken() > card_won_p1 && card_won_p2 == p2.cardesTaken()) ||
        (p2.cardesTaken() > card_won_p2 && p1.cardesTaken() == card_won_p1))
        good = true;
    else
        good = false;
    CHECK(good);

}

TEST_CASE("Check if someone won")
{
    Player p1("player1"); //Creating player objects
    Player p2("player2");
    Game g(p1, p2);
    CHECK_NOTHROW(g.playAll());              //Plays the game until someone wins;
    int MAX = 52, NOTHING = 0;
    bool ended;
    if (p1.cardesTaken()>p2.cardesTaken() || p2.cardesTaken()>p1.cardesTaken())
        ended = true;
    else
        ended = false;
    CHECK(ended);
    //-------------------------------------------------------------------------------
    Player p3("player3");
    Player p4("player4");
    Game g2(p3,p4);
    while(p3.stacksize()>0 && p4.stacksize()>0)
        g2.playTurn();
    bool ok;
    if(p3.stacksize() == 0 || p4.stacksize() == 0)
        ok = true;
    else
        ok = false;
    CHECK(ok);
}

TEST_CASE("Check if only 2 correctly registered to the game")
{
    Player p1("player1");
    Player p2("player2");
    Game g(p1, p2);
    CHECK_NOTHROW(g.playTurn());
    Player p3("player3");
    CHECK_THROWS_AS(Game g2(p2, p3),invalid_argument);
    int SIZE = 26;
    bool flag;
    if (p2.stacksize() == SIZE)
        flag = false;
    else
        flag = true;
    CHECK(flag);
}

TEST_CASE("Check if not calling play function after game ends")
{
    Player p1("player1");
    Player p2("player2");
    Game g(p1, p2);
    CHECK_NOTHROW(g.playAll());
    CHECK_THROWS(g.playAll());
    CHECK_THROWS(g.playTurn());
}

TEST_CASE("Check if void tests are fine")
{
    Player p1("player1");
    Player p2("player2");
    Game g(p1, p2);
    CHECK_NOTHROW(g.playAll());
    CHECK_NOTHROW(g.printWiner());
    CHECK_NOTHROW(g.printStats());
    CHECK_NOTHROW(g.printLastTurn());
    CHECK_NOTHROW(g.printLog());
}
