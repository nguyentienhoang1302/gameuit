#pragma once
#include "EnemyState.h"
#include "EnemyData.h"
#include "EnemyCannonData.h"
#include "EnemyCannonTurningState.h"

class EnemyCannonAppearingState : public EnemyState
{
public:
	EnemyCannonAppearingState(EnemyData* pData);
	~EnemyCannonAppearingState();
	virtual void onUpdate();
};