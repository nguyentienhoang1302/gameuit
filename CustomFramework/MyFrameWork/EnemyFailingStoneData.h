#pragma once
#include "EnemyData.h"
class EnemyFailingStoneData :
	public EnemyData
{
public:
	EnemyFailingStoneData();
	~EnemyFailingStoneData();

	enum EnemyFailingStoneArrayIndex
	{
		PREPARE,
		APPEAR,
		DROP,
		DEAD,
		COUNT
	};
};

