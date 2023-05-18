#pragma once
#include "EnemyState.h"
class EnemyMineFallingState : public EnemyState
{
public:
	EnemyMineFallingState(EnemyData* data);
	~EnemyMineFallingState(void);
	virtual void onUpdate();
	virtual void onCollision(CollisionRectF rect);
private:
	float speedX;
	float speedY;
	float acceleration;
};

