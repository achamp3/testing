#include "Headers/main.h"

int main()
{
    bool isRunning = true;
    int score = 0; //Initialize score to 0.
    Player *aPlayer = new Player(); //Make player
    Enemy *aEnemy = new Enemy(); //Make enemy
    cout << "ROUND 1. FIGHT. (Enter 5 to end game)" << endl;

    while(isRunning)
    {
        aPlayer->doMove(aEnemy); //Print the player's choices for moves. Do the player's move on the enemy.
        cout << "Enemy's HP: "<< aEnemy->getEnemyHealth() << endl; //Print enemy's HP.
        
        if(aEnemy->getEnemyHealth() == 0) //Check if the enemy is dead. hp = 0. respawn enemy. Track high score.
        {
            delete aEnemy;
            aEnemy = new Enemy();
            cout << "You defeated an enemy." << endl;
            score++;
            cout << "Score: " << score << endl;
        }

        aEnemy->doMove(aPlayer); //Do enemy's move on the player.
        cout << "Your HP: "<< aPlayer->getPlayerHealth() << endl; //Print player's HP.
        
        if(aPlayer->getPlayerHealth() == 0) //Check if the player is dead (hp = 0), if true, then end game. Print "You died." Print player score.
        {
            cout << "You died. Try again next time." << endl;
            cout << "Score: " << score << endl;
            exit(0);
        }
    }
}
