#pragma once
#include "EnemySprite.h"
#include "EnemyFinalBoss5PreparingState.h"
#include "EnemyFinalBoss5AppearingState.h"
#include "EnemyFinalBoss5WaitingState.h"
#include "EnemyFinalBoss5DisappearingState.h"
#include "EnemyFinalBoss5DeadState.h"
#include "GunBoss5Bullet.h"
#include "ShipBoss5.h"

class EnemyFinalBoss5Sprite :
	public EnemySprite
{
public:
	EnemyFinalBoss5Sprite(float respawnX, float respawnY, std::vector < BulletSprite*>& bulletSpriteVector);
	~EnemyFinalBoss5Sprite();
	static void loadResources();
	virtual void playBeShootedEffect();
};

