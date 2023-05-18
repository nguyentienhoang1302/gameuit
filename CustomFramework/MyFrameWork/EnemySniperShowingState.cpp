#include "EnemySniperShowingState.h"
#include"EnemySniperDeadState.h"

EnemySniperShowingState::EnemySniperShowingState(EnemyData* data)
{
    this->pData = data;
    this->pData->iCurrentArr = EnemySniperData::SHOWING;
    frameToShot = 0;
    shotCount = 0;
}


EnemySniperShowingState::~EnemySniperShowingState()
{
}

void EnemySniperShowingState::onUpdate()
{
	EnemyState::onUpdate();

	if (frameToShot <= 0)
	{
		this->pData->bulletsVector.push_back(new EnemyWhiteBullet(pData->x - 16, pData->y - 14, true, D3DXToRadian(180)));
		frameToShot = 40;
		shotCount++;
	}
	else
	{
		frameToShot--;
	}

	if (shotCount >= 3)
	{
		this->pData->pState = new EnemySniperHidingState(this->pData);
	}
}

void EnemySniperShowingState::onDead()
{
	transition(new EnemySniperDeadState(pData));
}