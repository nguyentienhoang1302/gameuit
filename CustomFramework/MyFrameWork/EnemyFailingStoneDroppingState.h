#pragma once
#include "EnemyState.h"
#include "EnemyFailingStone.h"

class EnemyFailingStoneDroppingState :
	public EnemyState
{
public:
	EnemyFailingStoneDroppingState(EnemyData* pData);
	~EnemyFailingStoneDroppingState();
	virtual void onUpdate();
	virtual void onDead();
	virtual void onCollision(CollisionRectF rect);
private:
	float acceleration;
	int status;
};