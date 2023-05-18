#pragma once
#include "EnemySprite.h"
class EnemyMineSprite : public EnemySprite
{
public:
	EnemyMineSprite(int respawnX, int respawnY);
	~EnemyMineSprite(void);
	static void loadResources();
};

