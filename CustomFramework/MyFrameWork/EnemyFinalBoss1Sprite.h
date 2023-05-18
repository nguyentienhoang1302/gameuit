#pragma once
#include "EnemySprite.h"
class EnemyFinalBoss1Sprite : public EnemySprite
{
public:
	~EnemyFinalBoss1Sprite();
	EnemyFinalBoss1Sprite(int respawnX, int respawnY);
	virtual void playBeShootedEffect();
	static void loadResources();
};

