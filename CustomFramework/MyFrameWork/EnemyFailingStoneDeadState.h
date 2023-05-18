#pragma once
#include "EnemyState.h"
#include "EnemyFailingStone.h"

class EnemyFailingStoneDeadState :
	public EnemyState
{
public:
	EnemyFailingStoneDeadState(EnemyData* pData);
	~EnemyFailingStoneDeadState();
	virtual void onUpdate();
};

