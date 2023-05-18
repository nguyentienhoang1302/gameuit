#include "EnemyGunBoss1DeadState.h"


EnemyGunBoss1DeadState::EnemyGunBoss1DeadState(EnemyData* data)
{
	pData  = data;
	pData -> iCurrentArr = 2;
	pData -> isHittable = false;
}


EnemyGunBoss1DeadState::~EnemyGunBoss1DeadState(void)
{
}

void EnemyGunBoss1DeadState :: onUpdate() 
{
	pData ->ppTextureArrays[ pData ->iCurrentArr ] ->update();
	if( pData ->ppTextureArrays[ pData ->iCurrentArr ] ->isLastTexture())
	{
		pData -> isDesTroyed = true;
	}
}
