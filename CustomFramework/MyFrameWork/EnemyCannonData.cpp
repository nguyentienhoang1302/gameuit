#include "EnemyCannonData.h"

EnemyCannonData::EnemyCannonData(std::vector < BulletSprite* >& bulletsVector )
	:
	EnemyData(bulletsVector)
{
	this->botName = "cannon";
	this->isHittable = false;
	this->isThrougable = true;
	this->isDesTroyed = false;
	this->HP = 8;
	this->score = 500;
}

EnemyCannonData::~EnemyCannonData()
{
}