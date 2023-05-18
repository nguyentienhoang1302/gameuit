#pragma once
#include "EnemySprite.h"
#include "EnemyCannonData.h"
#include "Camera.h"
#include "PlayerSprite.h"
#include "EnemyCannonPreaparingState.h"
#include "EnemyCannonAppearingState.h"
#include "EnemyCannonTurningState.h"

class EnemyCannon : public EnemySprite
{
private:
public:
	EnemyCannon(int respawnX, int respawnY, int isStage, std::vector < BulletSprite*>& bulletSpriteVector);
	~EnemyCannon();

	virtual void playBeShootedEffect();
	static void loadResources();
	virtual void update();
	virtual void draw(Camera *cam);
};