#include "EnemyRifleMan.h"

EnemyRifleMan::EnemyRifleMan()
{
	animations[STANDING] = new Animation(ENEMY, 0, 0);
	animations[RUNNING] = new Animation(ENEMY, 0, 2, DEFAULT_TPF << 1);
	tag = ENEMY;
	type = SOLIDER;
	width = ENEMY_SWORDMAN_WIDTH;
	height = ENEMY_SWORDMAN_HEIGHT;
	speed = ENEMY_SWORDMAN_SPEED;
}

EnemyRifleMan::~EnemyRifleMan()
{
}
