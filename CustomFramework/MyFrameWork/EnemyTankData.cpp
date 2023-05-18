#include"EnemyTankData.h"

EnemyTankData::EnemyTankData(std::vector<BulletSprite*>& bulletsVector)
	:EnemyData(bulletsVector)
{
	this->isHittable = true;
	this->isThrougable = false;

	this->isDesTroyed = false;
	this->HP = 50;
	this->botName = "tank";
	this->score = 5000;
}

EnemyTankData::~EnemyTankData()
{

}