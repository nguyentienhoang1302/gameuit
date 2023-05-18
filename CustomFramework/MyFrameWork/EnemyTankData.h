#pragma once
#include"EnemyData.h"

class EnemyTankData : public EnemyData
{
public:
	EnemyTankData ( std::vector<BulletSprite*>& bulletsVector = std::vector<BulletSprite*>());
	~EnemyTankData();
};