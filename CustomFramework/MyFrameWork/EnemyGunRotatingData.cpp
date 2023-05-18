#include"EnemyGunRotatingData.h"

EnemyGunRotatingData::EnemyGunRotatingData(std::vector < BulletSprite* >& bulletsVector)
	:
	EnemyData(bulletsVector)
{
	this->botName = "gunrotating";
	this->isHittable = false;
	this->isThrougable = true;
	this->isDesTroyed = false;
	this->HP = 10;
	this->isGun = true; // gun stage1
	this->score = 300;
}
EnemyGunRotatingData::~EnemyGunRotatingData()
{

}