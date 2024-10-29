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
    void loop();
};