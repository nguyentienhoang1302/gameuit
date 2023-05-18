#pragma once

#include "EnemyState.h"
#include "EnemyData.h"
#include "EnemySniperDeadState.h"

class EnemySniperStandingState : public EnemyState
{
public:
	EnemySniperStandingState(EnemyData* data);
	~EnemySniperStandingState();

	virtual void onUpdate();
private:
	int count;
	int nHoldFrames;
};