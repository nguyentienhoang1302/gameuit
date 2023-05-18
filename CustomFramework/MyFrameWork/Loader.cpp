#include "Loader.h"

Loader* Loader::sInstance = nullptr;

Loader* Loader::getInstance()
{
	if (sInstance == nullptr)
	{
		sInstance = new Loader();
	}
	return sInstance;
}
Loader::Loader()
{
}


Loader::~Loader(void)
{
}
void Loader::loadResources(std::string name)
{
	if (std::find(spriteNamesLoaded.begin(), spriteNamesLoaded.end(), name) == spriteNamesLoaded.end())
	{
		spriteNamesLoaded.push_back(name);

		if (name == "player")
		{
			PlayerSprite::loadResources();
			return;
		}

		if (name == "gunboss1")
		{
			EnemyGunBoss1Sprite::loadResources();
			return;
		}

		if (name == "cannon")
		{
			EnemyCannon::loadResources();
			return;
		}

		if (name == "finalboss1")
		{
			EnemyFinalBoss1Sprite::loadResources();
			return;
		}

        if (name == "soldierl" || name == "solderr")
        {
            EnemySoldier::loadResources();
            return;
        }

        if (name == "bridge")
        {
            ObjectBridge::loadResources();
            return;
        }

        if (name == "boss2finalarmleft" || name == "boss2finalarmright" || name == "boss2finalhead")
        {
            Boss2Final::loadResources();
            return;
        }

		if (name == "finalboss5")
		{
			EnemyFinalBoss5Sprite::loadResources();
			return;
		}

		if (name == "blazer")
		{
			EnemyBlazerSprite::loadResources();
			return;
		}


		if (name == "dynamicbridge")
		{
			ObjectDynamicBridgeSprite::loadResources();
			return;
		}

		if (name == "failingstone")
		{
			EnemyFailingStone::loadResources();
			return;
		}

		if (name == "gunrotating")
		{
			EnemyGunRotating::loadResources();
			return;
		}

		if (name == "scubarsolider")
		{
			EnemyScubarSoliderSprite::loadResources();
			return;
		}

		if( name == "mine")
		{
			EnemyMineSprite::loadResources();
			return;
		}

        if (name.find("staticweapon"))
        {
            ObjectStaticWeapon::loadResources();
            return;
        }
		if (name == "tank")
		{
			EnemyTankSprite::loadResources();
			return;
		}
		if (name == "sniper")
		{
			EnemyTankSprite::loadResources();
			return;
		}
	}
}