#pragma once
#include "EnemyState.h"
class EnemyBazokaStandingState : public EnemyState
{
public:
	EnemyBazokaStandingState(EnemyData* data);
	~EnemyBazokaStandingState(void);
	virtual void onUpdate();
	virtual void onDead();
private:
	int nHoldingFrames;
	int count;
};

