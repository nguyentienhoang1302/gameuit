#pragma once
#include "EnemyState.h"
#include "EnemyFailingStone.h"

class EnemyFailingStoneAppearingState :
	public EnemyState
{
public:
	EnemyFailingStoneAppearingState(EnemyData* pData);
	~EnemyFailingStoneAppearingState();
	virtual void onUpdate();
private:
	int count;
	int nHoldFrames;
	float crow;
};