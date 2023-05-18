#pragma once
#include "EnemyState.h"
#include "EnemyFinalBoss5Sprite.h"

class EnemyFinalBoss5WaitingState :
	public EnemyState
{
public:
	EnemyFinalBoss5WaitingState(EnemyData* data);
	~EnemyFinalBoss5WaitingState();
	virtual void onUpdate();
	virtual void onDead();
private:
	int count;
	int nHoldFrames;
	int nCycleBullet;
	int nCycleShip;
	bool typeLeft;
	float bulletX;
	float bulletY;
};

