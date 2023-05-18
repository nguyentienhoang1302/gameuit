#pragma once
#include "EnemySprite.h"
#include "EnemyFailingStoneData.h"
#include "EnemyFailingStoneAppearingState.h"
#include "EnemyFailingStoneDroppingState.h"
#include "EnemyFailingStoneDeadState.h"
#include "Sound.h"

class EnemyFailingStone :
	public EnemySprite
{
public:
	EnemyFailingStone(float respawnX, float respawnY);
	~EnemyFailingStone();

	static void loadResources();
	virtual void update();
	virtual void draw(Camera *cam);
	virtual void playBeShootedEffect();
};

