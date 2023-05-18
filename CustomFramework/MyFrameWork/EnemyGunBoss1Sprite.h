#pragma once

#include "EnemySprite.h"
#include "EnemyGunBoss1Sprite.h"
#include "Sound.h"
class EnemyGunBoss1Sprite : public EnemySprite
{
public:
	EnemyGunBoss1Sprite(int respawnX, int respawnY, std::vector < BulletSprite*>& bulletSpriteVector);
	virtual void draw( Camera* cam) ;
	virtual void update();
	virtual void playBeShootedEffect();
	static void loadResources();
};