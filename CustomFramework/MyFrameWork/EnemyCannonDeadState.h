#pragma once
#include "EnemyState.h"
class EnemyCannonDeadState : public EnemyState
{
public:
	EnemyCannonDeadState(EnemyData* pData);
	~EnemyCannonDeadState();
	virtual void onUpdate();
};

