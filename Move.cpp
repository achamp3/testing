#include "Move.h"
#include "Player.h"
#include "Enemy.h"

Move::Move()
{
    deltaHealth = 0;
    isAttack = true;
    moveName = "default move";
}

Move::Move(int delta, bool doesDamage, string name)
{
    deltaHealth = delta;
    isAttack = doesDamage;
    moveName = name;
}

void Move::doMove(Player *aPlayer, Enemy *aEnemy, bool isPlayer)
{
    if (isPlayer)
    {
        if (isAttack)
        {
            aEnemy->changeHealth(deltaHealth);
        }
        else
        {
            aPlayer->changeHealth(deltaHealth);
        }
    }
    else
    {
        if (isAttack)
        {
            aPlayer->changeHealth(deltaHealth);
        }
        else
        {
            aEnemy->changeHealth(deltaHealth);
        }
    }
}

string Move::getMoveName()
{
    return moveName;
}

ostream &operator<<(ostream &os, Move move)
{
    os << move.moveName << endl;
    return os;
}