#include "EnemyCannonAppearingState.h"

EnemyCannonAppearingState::EnemyCannonAppearingState(EnemyData *pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = EnemyCannonData::APPEAR;
}

EnemyCannonAppearingState::~EnemyCannonAppearingState()
{

}

void EnemyCannonAppearingState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	if (pData->ppTextureArrays[pData->iCurrentArr]->isLastTexture())
	{
		transition(new EnemyCannonTurningState(pData));
	}
}