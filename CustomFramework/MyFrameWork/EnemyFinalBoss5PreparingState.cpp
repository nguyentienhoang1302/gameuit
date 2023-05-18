#include "EnemyFinalBoss5PreparingState.h"


EnemyFinalBoss5PreparingState::EnemyFinalBoss5PreparingState(EnemyData* data)
{
	pData = data;
	pData->iCurrentArr = 0;
	count = 0;
	nHoldFrames = 120;
	appearX = DurexX + rand() % 150;// + this->pData->body.width / 2
	appearY = DurexY + rand() % 50;// + this->pData->body.height / 2
}

EnemyFinalBoss5PreparingState::~EnemyFinalBoss5PreparingState()
{
}

void EnemyFinalBoss5PreparingState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	count++;
	count %= nHoldFrames;
	if (count == 0)
	{
		transition(new EnemyFinalBoss5AppearingState(pData, appearX, appearY));
	}
}