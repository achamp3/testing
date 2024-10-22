#include "Enemy.h"
#include "Move.h"
#include "Player.h"

Enemy::Enemy()
{
    int health = 100;
    getEnemyMoves();
}

void Enemy::getEnemyMoves()
{
    moves.emplace_back(-20, true, "Sword Attack");
    moves.emplace_back(-30, true, "Fire Ball");
    moves.emplace_back(-15, true, "Sneak Attack");
    moves.emplace_back(20, false, "Heal");
}

void Enemy::changeHealth(int amount)
{
    health += amount;
    if (health < 0)
    {
        health = 0;
    }
}

void Enemy::doMove(Player *aPlayer)
{
    random_device randomDevice;
    int moveIndex = 1 + (randomDevice() % 3);
    moves[moveIndex].doMove(aPlayer, this, false);
}

int Enemy::getEnemyHealth()
{
    return health;
}