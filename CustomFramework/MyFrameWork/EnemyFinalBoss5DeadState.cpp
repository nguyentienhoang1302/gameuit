#include "EnemyFinalBoss5DeadState.h"


EnemyFinalBoss5DeadState::EnemyFinalBoss5DeadState(EnemyData* data)
{
	pData = data;
	pData->iCurrentArr = 4;
	pData->isHittable = false;
	Sound::getInstance()->play("boss2finaldestroy.wav", false, 1);
}


EnemyFinalBoss5DeadState::~EnemyFinalBoss5DeadState()
{
}

void EnemyFinalBoss5DeadState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	if (pData->ppTextureArrays[pData->iCurrentArr]->isLastTexture())
	{
		pData->isDesTroyed = true;
	}
}
