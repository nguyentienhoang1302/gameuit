#pragma once
#include"EnemySprite.h"
class EnemyTankSprite : public EnemySprite
{
public:
	EnemyTankSprite(int respawnX, int respawnY, std::vector<BulletSprite*>& bulletSpriteVector);
	~EnemyTankSprite();
	static void loadResources();
	void update();
	void draw(Camera*);
	virtual void playBeShootedEffect();
};