#pragma once
#include "EnemyState.h"
#include "EnemyFinalBoss5Sprite.h"

class EnemyFinalBoss5AppearingState :
	public EnemyState
{
public:
	//EnemyFinalBoss5AppearingState(EnemyData* data);
	EnemyFinalBoss5AppearingState(EnemyData* data, float x, float y);
	~EnemyFinalBoss5AppearingState();
	virtual void onUpdate();
};

