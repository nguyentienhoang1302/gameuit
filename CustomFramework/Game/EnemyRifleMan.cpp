#include "EnemyRifleMan.h"

EnemyRifleMan::EnemyRifleMan()
{
	animations[STANDING] = new Animation(ENEMY, 11, 11);
	animations[RUNNING] = new Animation(ENEMY, 12, 15, DEFAULT_TPF << 1);
	tag = ENEMY;
	type = RIFLEMAN;
	width = ENEMY_SWORDMAN_WIDTH;
	height = ENEMY_SWORDMAN_HEIGHT;
	speed = ENEMY_SWORDMAN_SPEED;
}

EnemyRifleMan::~EnemyRifleMan()
{
}
