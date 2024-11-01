#include "../Headers/Enemy.h"
#include "../Headers/Move.h"
#include "../Headers/Player.h"

Enemy::Enemy()
{
    health = 100;
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
    int moveIndex = randomDevice() % 4;
    cout << "The enemy used a " << moves[moveIndex].getMoveName() << endl;
    moves[moveIndex].doMove(aPlayer, this, false);
}

int Enemy::getEnemyHealth()
{
    return health;
}