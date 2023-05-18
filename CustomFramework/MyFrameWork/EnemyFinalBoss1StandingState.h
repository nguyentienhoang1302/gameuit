#pragma once
#include "EnemyState.h"
class EnemyFinalBoss1StandingState : public EnemyState
{
public:
	EnemyFinalBoss1StandingState(EnemyData* data);
	~EnemyFinalBoss1StandingState();
	virtual void onUpdate() ;
	virtual void onDead();
};

