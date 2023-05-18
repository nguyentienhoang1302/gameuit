#pragma once

#include "EnemyState.h"


class EnemyGunBoss1StandingState : public EnemyState
{
public:
	EnemyGunBoss1StandingState( EnemyData* data);
	virtual void onUpdate() ;
	virtual void onDead();
private:
	int count;
	int nHoldFrames;
};