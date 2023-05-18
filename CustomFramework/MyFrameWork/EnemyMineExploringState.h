#pragma once
#include "EnemyState.h"
class EnemyMineExploringState : public EnemyState
{
public:
	EnemyMineExploringState(EnemyData* data);
	~EnemyMineExploringState(void);
	virtual void onUpdate();
};

