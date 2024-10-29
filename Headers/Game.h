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

    public:
    Game();
    void setup(); //Sets up the game.
    void loop(); //Loops through the game.
};