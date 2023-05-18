#pragma once
#include"EnemyData.h"

class EnemyScubarSoliderData :public EnemyData
{
public:
	EnemyScubarSoliderData(std::vector < BulletSprite* >& bulletsVector = std::vector <BulletSprite* >());
	~EnemyScubarSoliderData();
};