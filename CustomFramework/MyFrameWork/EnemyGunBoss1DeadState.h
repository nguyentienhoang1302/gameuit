#pragma once
#include "EnemyState.h"
class EnemyGunBoss1DeadState : public EnemyState
{
public:
public:
	EnemyGunBoss1DeadState( EnemyData* data);
	~EnemyGunBoss1DeadState(void);
	virtual void onUpdate() ;
private:
	int count;
	int nHoldFrames;
	
};

