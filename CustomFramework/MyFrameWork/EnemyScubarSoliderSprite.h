#pragma once
#include"EnemySprite.h"
class EnemyScubarSoliderSprite :public EnemySprite
{
public:
	EnemyScubarSoliderSprite(int respawnX, int respawnY,int kind, std::vector < BulletSprite*>& bulletSpriteVector);
	~EnemyScubarSoliderSprite();
	static void loadResources();
	void update();
	void draw(Camera*);
	virtual void playBeShootedEffect();
};