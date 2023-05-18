#include "EnemyFinalBoss1DeadState.h"


EnemyFinalBoss1DeadState::EnemyFinalBoss1DeadState(EnemyData* data)
{
	pData  = data;
	pData -> iCurrentArr = 1;
	pData -> isHittable = false;
}



EnemyFinalBoss1DeadState::~EnemyFinalBoss1DeadState(void)
{
}

void EnemyFinalBoss1DeadState :: onUpdate() 
{
	pData ->ppTextureArrays[ pData ->iCurrentArr ] ->update();
	if(pData ->ppTextureArrays[ pData ->iCurrentArr ] ->isLastTexture())
	{
		pData -> isDesTroyed = true;
	}
}


