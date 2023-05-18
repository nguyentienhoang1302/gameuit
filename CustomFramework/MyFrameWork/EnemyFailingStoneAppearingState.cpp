#include "EnemyFailingStoneAppearingState.h"


EnemyFailingStoneAppearingState::EnemyFailingStoneAppearingState(EnemyData* pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = EnemyFailingStoneData::APPEAR;
	count = 0;
	nHoldFrames = 100;
	crow = 0.0f; 
	this->pData->vx = 2.0f;
}


EnemyFailingStoneAppearingState::~EnemyFailingStoneAppearingState()
{
}

void EnemyFailingStoneAppearingState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	count++;
	count %= nHoldFrames; 
	crow += M_PI / 4;
	pData->x += 1.0f * sin(crow);
	if (crow==2*M_PI)
	{
		crow = 0;
	}
	if (count == 0)
	{
		transition(new EnemyFailingStoneDroppingState(pData));
	}
}