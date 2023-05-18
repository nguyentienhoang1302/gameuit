#include"EnemyScubarSoliderData.h"

EnemyScubarSoliderData::EnemyScubarSoliderData(std::vector < BulletSprite* >& bulletsVector)
	:
	EnemyData(bulletsVector)
{
	this->isHittable = false;
	this->isThrougable = true;

	this->isDesTroyed = false;
	this->HP = 1;
	this->botName = "scubarsolider";
	this->score = 1000;
}

EnemyScubarSoliderData::~EnemyScubarSoliderData()
{

}