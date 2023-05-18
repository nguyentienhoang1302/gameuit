#pragma once
#include "EnemySprite.h"
class EnemyBazokaSprite : public EnemySprite
{
public:
	EnemyBazokaSprite(float respawnX, float respawnY, std::vector<BulletSprite*>& bulletVector);
	~EnemyBazokaSprite(void);
	virtual void playBeShootedEffect();
	static void loadResources();
};

