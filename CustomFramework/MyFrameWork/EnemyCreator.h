#pragma once

#include "EnemyInkSprite.h"
#include "EnemySoldier.h"
#include "EnemySniper.h"
#include "ObjectBridgeHead.h"
#include "ObjectBridgeBody.h"
#include "ObjectBridgeTail.h"
#include "EnemySprite.h"
#include "ObjectSprite.h"
#include "ObjectStaticWeapon.h"
#include "ObjectCapsuleWeapon.h"
#include "EnemyBazokaSprite.h"
#include <map>


class EnemyCreator
{
private:
	static EnemyCreator* instance;
	EnemyCreator();
	void addAppearDirection(std::string name, Direction dir);
public:
	static EnemyCreator* getInstance();
	EnemySprite * createEnemySprite(std::string EnemyName, int respawnX, int respawnY, std :: vector < BulletSprite* >& bulletSprites);
	ObjectSprite* createObjectSprite(std::string name, int respawnX, int respawnY);
	Direction getAppearDir(std::string name);
	std::map < std::string, Direction > appearDirections;
};