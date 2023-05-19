#include "EnemyCannon.h"

EnemyCannon::EnemyCannon()
{
	animations[STANDING] = new Animation(ENEMY, 0, 0);
	tag = ENEMY;
	type = CANNON;
	width = ENEMY_SWORDMAN_WIDTH;
	height = ENEMY_SWORDMAN_HEIGHT;
	speed = ENEMY_SWORDMAN_SPEED;
}

EnemyCannon::~EnemyCannon()
{
}

void EnemyCannon::UpdateDistance(float dt)
{
	this->dx = 0;
}
