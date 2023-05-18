#pragma once
#include "EnemyData.h"

class EnemyCannonData : public EnemyData
{
public:
	EnemyCannonData(std::vector < BulletSprite* >& bulletsVector = std::vector <BulletSprite* >());
	~EnemyCannonData();

	enum EnemyCannonArrayIndex
	{
		APPEAR,
		TURN0,
		TURN30,
		TURN60,
		FIRE,
		DEAD,
		PREPARE,
		COUNT
	};
};

