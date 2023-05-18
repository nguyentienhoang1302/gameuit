#include "EnemyFinalBoss5DisappearingState.h"


EnemyFinalBoss5DisappearingState::EnemyFinalBoss5DisappearingState(EnemyData* data)
{
	pData = data;
	pData->isHittable = false;
	pData->iCurrentArr = 3;
}

EnemyFinalBoss5DisappearingState::~EnemyFinalBoss5DisappearingState()
{
}

void EnemyFinalBoss5DisappearingState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	if (pData->ppTextureArrays[pData->iCurrentArr]->isLastTexture())
	{
		transition(new EnemyFinalBoss5PreparingState(pData));
	}
}