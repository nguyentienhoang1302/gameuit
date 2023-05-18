#pragma once

#include "EnemyState.h"


class EnemyGunBoss1FiringState : public EnemyState
{
public:
	EnemyGunBoss1FiringState( EnemyData* data);
	virtual void onUpdate() ;
	virtual void onDead();
private:
	int count;
	int nHoldFrames;
};