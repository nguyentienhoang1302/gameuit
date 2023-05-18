#pragma once
#include "EnemyState.h"
#include "EnemyFinalBoss5Sprite.h"

class EnemyFinalBoss5DisappearingState :
	public EnemyState
{
public:
	EnemyFinalBoss5DisappearingState(EnemyData* data);
	~EnemyFinalBoss5DisappearingState();
	virtual void onUpdate();
};

