#pragma once
#include "EnemyState.h"
class EnemyBazokaFiringState : public EnemyState
{
public:
	EnemyBazokaFiringState(EnemyData* data);
	~EnemyBazokaFiringState(void);
	virtual void onUpdate();
	virtual void onDead();
private:
	int counter;
	int nHoldingFrames;
};

