#pragma once
#include "EnemyState.h"
#include "EnemyCannonAppearingState.h"
class EnemyCannonPreaparingState :
	public EnemyState
{
public:
	EnemyCannonPreaparingState(EnemyData* pData);
	~EnemyCannonPreaparingState();
	virtual void onUpdate();
	float directPlayerX;
};

