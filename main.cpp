#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Move.h" 

using namespace std;

int main()
{
    bool isRunning = true;
    int score = 0;
    //Make player
    Player *aPlayer = new Player();
    //Make enemy
    Enemy *aEnemy = new Enemy();
    //Round 1. FIGHT.
    cout << "ROUND 1. FIGHT." << endl;
    while(isRunning)
    {
        //Print the player's choices for moves.
        //Do the player's move on the enemy.
        aPlayer->doMove(aEnemy);
        //Print enemy's HP.
        cout << "Enemy's HP: "<< aEnemy->getEnemyHealth() << endl;
        //Check if the enemy is dead. hp = 0. respawn enemy. Track high score.
        if(aEnemy->getEnemyHealth() == 0)
        {
            delete aEnemy;
            aEnemy = new Enemy();
            cout << "You defeated an enemy." << endl;
            score++;
            cout << "Score: " << score << endl;
        }
        //Do enemy's move on the player.
        aEnemy->doMove(aPlayer);
        //Print player's HP.
        cout << "Your HP: "<< aPlayer->getPlayerHealth() << endl;
        //Check if the player is dead. hp = 0. end game. print you died.
        if(aPlayer->getPlayerHealth() == 0)
        {
            cout << "You died. Try again next time." << endl;
            cout << score;
            exit(0);
        }
    }
}
