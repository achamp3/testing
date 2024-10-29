#pragma once
#include <iostream>

class Player;
class Enemy;

class Game
{
    private:
    Player *aPlayer;
    Enemy *aEnemy;
    bool isRunning;
    void isEnemyDead();
    void isPlayerDead();
    void printHealth();
    void doTurn();

    public:
    Game();
    void setup(); //Sets up the game.
    void loop(); //Loops through the game.

};