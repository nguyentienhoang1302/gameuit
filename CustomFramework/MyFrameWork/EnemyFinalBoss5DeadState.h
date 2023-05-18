#pragma once
#include "EnemyState.h"
#include "EnemyFinalBoss5Sprite.h"

class EnemyFinalBoss5DeadState :
	public EnemyState
{
public:
	EnemyFinalBoss5DeadState(EnemyData* data);
	~EnemyFinalBoss5DeadState(); 
	virtual void onUpdate();
};

