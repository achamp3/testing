#include "../Headers/Game.h"
#include "../Headers/Player.h"
#include "../Headers/Enemy.h"
#include "../Headers/Move.h"

Game::Game()
{
}

void Game::setup()
{
    isRunning = true;
    aPlayer = new Player();
    aEnemy = new Enemy();
    cout << "ROUND 1. FIGHT. (Enter 5 to end game)" << endl;
}

void Game::loop()
{
    while (isRunning)
    {
        doTurn();
    }
}

void Game::isEnemyDead()
{
    if (aEnemy->getEnemyHealth() == 0)
    {
        delete aEnemy;
        aEnemy = new Enemy();
        cout << "You defeated an enemy." << endl;
        aPlayer->increaseScore();
        cout << "Score: " << aPlayer->getPlayerScore() << endl;
    }
}

void Game::isPlayerDead()
{
    if (aPlayer->getPlayerHealth() == 0)
    {
        cout << "You died. Try again next time." << endl;
        cout << "Score: " << aPlayer->getPlayerScore() << endl;
        exit(0);
    }
}

void Game::printHealth()
{
    cout << "Your HP: " << aPlayer->getPlayerHealth() << endl;
    cout << "Enemy's HP: " << aEnemy->getEnemyHealth() << endl;
}

void Game::doTurn()
{
    printHealth();           // Print player health, then print enemy health.
    aPlayer->doMove(aEnemy); // Print the player's choices for moves. Do the player's move on the enemy.
    isEnemyDead();           // Check if the enemy is dead. hp = 0. respawn enemy. Track high score.
    aEnemy->doMove(aPlayer); // Do enemy's move on the player.
    isPlayerDead();          // Check if the player is dead (hp = 0), if true, then end game. Print "You died." Print player score.
}