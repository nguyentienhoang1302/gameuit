#pragma once
#include "EnemyState.h"
#include "EnemyFinalBoss5Sprite.h"

const float DurexX = 4900.0f;
const float DurexY = 35.0f;

class EnemyFinalBoss5PreparingState :
	public EnemyState
{
public:
	EnemyFinalBoss5PreparingState(EnemyData* data);
	~EnemyFinalBoss5PreparingState();
	virtual void onUpdate();
private:
	int count;
	int nHoldFrames;
	int appearX;
	int appearY;
};