#include "EnemySoldierData.h"

EnemySoldierData::EnemySoldierData(std::vector<BulletSprite*>& bullet) : EnemyData(bullet)
{
    this->botName = "soldier";
    this->isHittable = true;
    this->isDesTroyed = false;
    this->isThrougable = false;
    this->isShooted = false;
    this->bulletsVector = bullet;
    this->HP = 1;
}


EnemySoldierData::~EnemySoldierData()
{
}
