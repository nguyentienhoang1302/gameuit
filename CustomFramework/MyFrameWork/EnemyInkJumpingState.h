#pragma once

#include "EnemyState.h"
#include "EnemyInkStandingState.h"
class EnemyInkJumpingState : public EnemyState
{
private:
	float acceleration;
	int nJumpingFrames;
	int count;

public:
	EnemyInkJumpingState(EnemyData* pData);
	virtual void onCollision(RectF rect);
	virtual void onUpdate();

};

