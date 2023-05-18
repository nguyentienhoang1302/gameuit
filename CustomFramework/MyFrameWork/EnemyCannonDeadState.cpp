#include "EnemyCannonDeadState.h"
#include "EnemyCannonData.h"
#include "Sound.h"

EnemyCannonDeadState::EnemyCannonDeadState(EnemyData* pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = EnemyCannonData::DEAD;
	pData->isHittable = false;

	Sound::getInstance()->play("qexplode", false, 1);
}


EnemyCannonDeadState::~EnemyCannonDeadState()
{
}

void EnemyCannonDeadState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	if (pData->ppTextureArrays[pData->iCurrentArr]->isLastTexture())
	{
		pData->isDesTroyed = true;
	}
}
