#include "EnemySoldier.h"

EnemySoldier::EnemySoldier()
{
	animations[STANDING] = new Animation(ENEMY, 6, 6);
	animations[RUNNING] = new Animation(ENEMY, 0, 5, DEFAULT_TPF << 1);
	tag = ENEMY;
	type = SOLIDER;
	width = ENEMY_SWORDMAN_WIDTH;
	height = ENEMY_SWORDMAN_HEIGHT;
	speed = ENEMY_SWORDMAN_SPEED;
}

EnemySoldier::~EnemySoldier()
{
}

void EnemySoldier::UpdateDistance(float dt)
{
	this->isReverse = false;
	this->dx = vx * dt;
}
