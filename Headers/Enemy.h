#pragma once
#include <random>

class Move;
class Player;

class Enemy
{
private:
    std::vector<Move> moves; //Vector that contains the enemy move set.
    int health; //Enemy's HP (0-100)
    void getEnemyMoves(); //Creates the enemy's default moves.

public:
    Enemy(); //Creates an enemy with initial health and moves.
    void changeHealth(int amount); //Changes the enemy health by amount.
    void doMove(Player *aPlayer); //Picks a random move from the moves array, then does the move. 
    int getEnemyHealth(); //Returns enemy health.
    friend class Move;
};
