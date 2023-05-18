#include"EnemyGunRotatingOpeningState.h"
#include"EnemyGunRotatingSwavelingState.h"

EnemyGunRotatingOpeningState::EnemyGunRotatingOpeningState(EnemyData *pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = EnemyGunRotatingData::OPEN;
	this->pData->isHittable = true;
	iFrame = 0;
}

EnemyGunRotatingOpeningState::~EnemyGunRotatingOpeningState()
{

}

void EnemyGunRotatingOpeningState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	iFrame++;
	if (iFrame == 2)
		transition(new EnemyGunRotatingSwavelingState(pData));
}