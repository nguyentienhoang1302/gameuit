#pragma once
#include "Enemy.h"

class EnemySoldier : public Enemy
{
public:
	EnemySoldier();
	~EnemySoldier();
	void UpdateDistance(float dt);
};