#pragma once
#include "EnemySprite.h"
class EnemyBlazerSprite : public EnemySprite
{
public:
	EnemyBlazerSprite(int respawnX, int respawnY);
	~EnemyBlazerSprite();
	static void loadResources();
};

