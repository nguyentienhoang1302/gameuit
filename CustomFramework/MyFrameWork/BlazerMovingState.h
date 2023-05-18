#pragma once

#include "EnemyState.h"
class BlazerMovingState : public EnemyState
{
public:
	BlazerMovingState(EnemyData* data);
	~BlazerMovingState(void);
	virtual void onUpdate();
private:
	float speed;
};

