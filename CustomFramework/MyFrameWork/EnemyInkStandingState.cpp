#include "EnemyInkStandingState.h"

#include "EnemyInkJumpingState.h"


EnemyInkStandingState::EnemyInkStandingState( EnemyData* data)
{
	pData = data;
	pData ->iCurrentArr = 0;
	nHoldFrame = 30;
	count = 0;
}


void EnemyInkStandingState :: onUpdate()
{
	pData ->ppTextureArrays[ pData ->iCurrentArr ] ->update();
	count ++;
	count %= nHoldFrame;
	if( count == 0)
	{
		transition(new EnemyInkJumpingState(pData));
	}
}

