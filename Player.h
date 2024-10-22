#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>

class Move;
class Enemy;

using namespace std;

class Player 
{ //They can attack and heal. Moves are sold to shop and buy move to replace.
private:
    vector<Move> moves; //Array that holds onto the four player moves.
    int health; //Player's health points (0-100)
    int coins; //0 - int_max
    const int moveSetSize = 4; //Always 4.
    void makeMoveSet(); //Creates the array for the player's move set.
    int getMove(); //Print's the player's moves.

public:
    Player(); //Creates player with initial health, coins, and moves.
    ~Player(); //Deletes the move set array.
    void changeHealth(int amount); //Changes player's hp by amount.
    void doMove(Enemy *aEnemy); //Gets the move and player does move.
    int getCoins(); //Returns player's coins.
    int getPlayerHealth(); //Returns player's health.
};

#endif