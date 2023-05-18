#include "EnemyCannonPreaparingState.h"


EnemyCannonPreaparingState::EnemyCannonPreaparingState(EnemyData* pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = EnemyCannonData::PREPARE;
}


EnemyCannonPreaparingState::~EnemyCannonPreaparingState()
{
}

void EnemyCannonPreaparingState::onUpdate()
{
	switch (this->pData->getPlayerIndexToExcute())
	{
	case 1:
		directPlayerX = this->pData->playerX;
		break;
	case 2:
		directPlayerX = this->pData->player2X;
		break;
	default:
		break;
	}
	if (this->pData->x - directPlayerX <= 100)
	{
		transition(new EnemyCannonAppearingState(pData));
	}
}