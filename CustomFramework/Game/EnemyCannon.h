#pragma once
#include "Enemy.h"

class EnemyCannon : public Enemy
{
public:
	EnemyCannon();
	~EnemyCannon();
	void UpdateDistance(float dt);
};