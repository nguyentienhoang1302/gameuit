#include "EnemyGunBoss1FiringState.h"
#include "EnemyGunBoss1StandingState.h"
#include "EnemyGunBoss1DeadState.h"
#include "GunBoss1Bullet.h"
EnemyGunBoss1FiringState::EnemyGunBoss1FiringState( EnemyData* data)
{
	pData = data;
	pData ->iCurrentArr = 1;
	nHoldFrames = 30;
	count = 0;
}


void EnemyGunBoss1FiringState :: onUpdate()
{
	if( count == 0)
	{
		pData -> bulletsVector.push_back( new GunBoss1Bullet(pData -> x - pData ->ppTextureArrays[ pData ->iCurrentArr ] -> getWidth() / 2, pData -> y ));
	}
	pData ->ppTextureArrays[ pData ->iCurrentArr ] ->update();
	count ++;
	count %= nHoldFrames;
	if( count == 0)
	{
		transition(new EnemyGunBoss1StandingState(pData));
	}
}

void EnemyGunBoss1FiringState :: onDead()
{
	transition(new EnemyGunBoss1DeadState(pData));
}

