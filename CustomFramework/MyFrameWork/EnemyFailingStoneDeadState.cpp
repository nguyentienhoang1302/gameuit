#include "EnemyFailingStoneDeadState.h"


EnemyFailingStoneDeadState::EnemyFailingStoneDeadState(EnemyData* pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = EnemyFailingStoneData::DEAD;
	pData->isHittable = false;

	Sound::getInstance()->play("qexplode", false, 1);
}


EnemyFailingStoneDeadState::~EnemyFailingStoneDeadState()
{
}

void EnemyFailingStoneDeadState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	if (pData->ppTextureArrays[pData->iCurrentArr]->isLastTexture())
	{
		pData->isDesTroyed = true;
	}
}
