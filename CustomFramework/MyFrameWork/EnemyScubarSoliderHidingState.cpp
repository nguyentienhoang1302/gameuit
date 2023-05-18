#include"EnemyScubarSoliderShootState.h"
#include"EnemyScubarSoliderHidingState.h"
#include"EnemyScubarSoliderData.h"
#include"EnemyScubarSoliderDeadState.h"

EnemyScubarSoliderHidingState::EnemyScubarSoliderHidingState(EnemyData *pData, bool isFirst)
{
	this->pData = pData;
	this->pData->iCurrentArr = 0;
	iFrame = 0;
	pData->isHittable = false;

	this->isFirst = isFirst;
}

EnemyScubarSoliderHidingState::~EnemyScubarSoliderHidingState()
{

}

void EnemyScubarSoliderHidingState::onUpdate()
{
	switch (this->pData->getPlayerIndexToExcute())
	{
	case 1:
		directPlayerY = this->pData->playerY;
		break;
	case 2:
		directPlayerY = this->pData->player2Y;
		break;
	default:
		break;
	}

	pData->ppTextureArrays[pData->iCurrentArr]->update();
	if (isFirst == false)
	{
		if (pData->y > directPlayerY)
			iFrame++;
	}
	else
		iFrame++;
	if (iFrame == 200)
		transition(new EnemyScubarSoliderShootState(pData));
}

void EnemyScubarSoliderHidingState::onDead()
{
	transition(new EnemyScubarSoliderDeadState(pData));
}