#include"EnemyGunRotatingDieState.h"

EnemyGunRotatingDieState::EnemyGunRotatingDieState(EnemyData *pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = EnemyGunRotatingData::DIE;
	iFrame = 0;
	pData->isHittable = false;
	Sound::getInstance()->play("qexplode", false, 1);
}

EnemyGunRotatingDieState::~EnemyGunRotatingDieState()
{

}
void EnemyGunRotatingDieState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	iFrame++;
	if (iFrame == 10)
	{
		pData->isDesTroyed = true;
	}
}