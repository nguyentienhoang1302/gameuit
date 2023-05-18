#include "EnemyFinalBoss5AppearingState.h"


EnemyFinalBoss5AppearingState::EnemyFinalBoss5AppearingState(EnemyData* data, float x, float y)
{
	pData = data;
	pData->iCurrentArr = 1;
	pData->x = x;
	pData->y = y;
	pData->isThrougable = false;
}


EnemyFinalBoss5AppearingState::~EnemyFinalBoss5AppearingState()
{
}

void EnemyFinalBoss5AppearingState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	if (pData->ppTextureArrays[pData->iCurrentArr]->isLastTexture())
	{
		transition(new EnemyFinalBoss5WaitingState(pData));
	}
}