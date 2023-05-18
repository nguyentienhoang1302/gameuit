#include "EnemyGunBoss1StandingState.h"
#include "EnemyGunBoss1FiringState.h"
#include "EnemyGunBoss1DeadState.h"

EnemyGunBoss1StandingState::EnemyGunBoss1StandingState( EnemyData* data)
{
	pData = data;
	pData ->iCurrentArr = 0;
	nHoldFrames = 20;
	count = 0;
}


void EnemyGunBoss1StandingState :: onUpdate()
{
	pData ->ppTextureArrays[ pData ->iCurrentArr ] ->update();
	count ++;
	count %= nHoldFrames;
	if( count == 0)
	{
		transition(new EnemyGunBoss1FiringState(pData));
	}
}

void EnemyGunBoss1StandingState :: onDead()
{
	transition(new EnemyGunBoss1DeadState(pData));
}

