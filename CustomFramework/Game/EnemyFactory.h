#pragma once
#include "Enemy.h"
#include "EnemySwordMan.h"
#include "EnemyGunMan.h"
#include "EnemyCloakMan.h"
#include "EnemyEagle.h"
#include "EnemyPanther.h"
#include "EnemyBazokaMan.h"
#include "EnemyRunMan.h"
#include "EnemyBoss.h"
#include "EnemySoldier.h"
#include "EnemyCannon.h"

class EnemyFactory
{
public:
	EnemyFactory() {};
	~EnemyFactory() {};

	static Enemy* CreateEnemy(int enemyID)
	{
		switch (enemyID)
		{
		case SWORDMAN: return new EnemySwordMan();
		case GUNMAN: return new EnemyGunMan();
		case PANTHER: return new EnemyPanther();
		case EAGLE: return new EnemyEagle();
		case CLOAKMAN: return new EnemyCloakMan();
		case BAZOKAMAN: return new EnemyBazokaMan();
		case RUNMAN: return new EnemyRunMan();
		case BOSS: return new EnemyBoss();
		case SOLIDER: return new EnemySoldier();
		case CANNON: return new EnemyCannon();
		default: return NULL;
		}
	}
};