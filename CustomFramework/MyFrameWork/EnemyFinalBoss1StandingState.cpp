#include "EnemyFinalBoss1StandingState.h"
#include "EnemyFinalBoss1DeadState.h"

EnemyFinalBoss1StandingState::EnemyFinalBoss1StandingState( EnemyData* data )
{
	pData  = data;
	pData -> iCurrentArr = 0;
	pData -> isHittable = true;
}


EnemyFinalBoss1StandingState::~EnemyFinalBoss1StandingState()
{
}

void EnemyFinalBoss1StandingState:: onUpdate() 
{
	pData ->ppTextureArrays[ pData ->iCurrentArr ] ->update();
}
void EnemyFinalBoss1StandingState::onDead()
{
	transition(new EnemyFinalBoss1DeadState(pData ));
}