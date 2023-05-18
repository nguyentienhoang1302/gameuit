#include "EnemyFinalBoss5WaitingState.h"

EnemyFinalBoss5WaitingState::EnemyFinalBoss5WaitingState(EnemyData* data)
{
	pData = data;
	pData->iCurrentArr = 2;
	pData->isHittable = true;
	count = 0;
	nHoldFrames = 240;
	nCycleBullet = 0;
	nCycleShip = 0;
	typeLeft = true;
	bulletX = pData->x;
	bulletY = pData->y;
}


EnemyFinalBoss5WaitingState::~EnemyFinalBoss5WaitingState()
{
}

void EnemyFinalBoss5WaitingState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	count++;
	nCycleBullet++;
	nCycleShip++;
	count %= nHoldFrames;

	if (nCycleBullet==30)
	{
		nCycleBullet = 0;
		pData->bulletsVector.push_back(new GunBoss5Bullet(bulletX,bulletY));
	}

	if (nCycleShip==40)
	{
		nCycleShip = 0;
		switch (typeLeft)
		{
		case true:
			pData->bulletsVector.push_back(new ShipBoss5(bulletX-20, bulletY-10, typeLeft));
			break;
		case false:
			pData->bulletsVector.push_back(new ShipBoss5(bulletX+20, bulletY-10, typeLeft));
			break;
		}
		typeLeft = (!typeLeft);
	}

	if (count == 0)
	{
		transition(new EnemyFinalBoss5DisappearingState(pData));
	}
}

void EnemyFinalBoss5WaitingState::onDead()
{
	transition(new EnemyFinalBoss5DeadState(pData));
}