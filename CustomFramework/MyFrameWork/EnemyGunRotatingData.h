#pragma once
#include"EnemyData.h"

class EnemyGunRotatingData : public EnemyData
{
public:
	EnemyGunRotatingData(std::vector < BulletSprite* >& bulletsVector = std::vector <BulletSprite* >());
	~EnemyGunRotatingData();

	enum EnemyGunRotatingArrayIndex
	{
		CLOSE,
		OPEN,
		SWAVEL1,
		SWAVEL2,
		SWAVEL3,
		SWAVEL4,
		SWAVEL5,
		SWAVEL6,
		SWAVEL7,
		SWAVEL8,
		SWAVEL9,
		SWAVEL10,
		SWAVEL11,
		SWAVEL12,
		DIE,
		COUNT
	};
	bool isGun;
};