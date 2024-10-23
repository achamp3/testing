#include "Player.h"
#include "Enemy.h"
#include "Move.h"

Player::Player()
{
    health = 100;
    coins = 0;
    makeMoveSet();
}

Player::~Player()
{
    moves.clear();
}

void Player::changeHealth(int amount)
{
    health += amount;
    if (health < 0)
    {
        health = 0;
    }
}

// Player asks user to choose move from move set array, then attacks or heals depending.
void Player::doMove(Enemy *aEnemy)
{
    int moveNumber = getMove() - 1;
    cout << "You used a " << moves[moveNumber].getMoveName() << endl;
    moves[moveNumber].doMove(this, aEnemy, true);
}

int Player::getCoins()
{
    return coins;
}

int Player::getPlayerHealth()
{
    return health;
}

void Player::makeMoveSet()
{
    moves.emplace_back(-20, true, "Sword Attack");
    moves.emplace_back(-30, true, "Fire Ball");
    moves.emplace_back(-15, true, "Sneak Attack");
    moves.emplace_back(20, false, "Heal");
}

int Player::getMove()
{
    int moveNumber = -1;
    while (moveNumber < 1 || moveNumber > 4)
    {
        cout << "Pick a move: " << endl;
        for (int i = 0; i < moveSetSize; i++)
        {
            cout << i + 1 << ". " << moves[i]; // Add operator overloading
        }
        cin >> moveNumber;
    }
    return moveNumber;
}