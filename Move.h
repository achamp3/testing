#pragma once
#include <string>
#include <iostream>

class Player;
class Enemy;

using namespace std;

class Move
{
private:
    int deltaHealth; //Holds onto the change in health (+/- depending on move).
    bool isAttack; //If the move is an attack, it is true, otherwise it's a heal.
    string moveName; //Holds onto the move name.

public:
    Move(); //Default constructor creates a "default" move.
    Move(int delta, bool doesDamage, string name); //Creates move with the value for its change in hp, if it is an attack or heal, and the move name.
    void doMove(class Player *aPlayer, class Enemy *aEnemy, bool isPlayer); //Executes the move. If attack, then decrease enemy hp by delta. If heal, increase player hp by delta.
    string getMoveName(); //Returns the name of the move.
    friend ostream &operator<<(ostream &os, Move move);
};
