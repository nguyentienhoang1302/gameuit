#pragma once

#include "EnemyState.h"


class EnemyInkStandingState : public EnemyState
{
public:
	EnemyInkStandingState( EnemyData* data);
	virtual void onUpdate() ;
private:
	int count;
	int nHoldFrame;
};