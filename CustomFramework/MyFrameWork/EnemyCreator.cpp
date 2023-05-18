#include "EnemyCreator.h"
#include "EnemyInkSprite.h"
#include "EnemyGunBoss1Sprite.h"
#include "EnemyFinalBoss1Sprite.h"
#include "EnemyFinalBoss5Sprite.h"
#include "ObjectBridge.h"
#include "ObjectDynamicBridgeSprite.h"
#include "EnemyCannon.h"
#include "EnemyGunRotating.h"
#include "Boss2FinalArm.h"
#include "Boss2FinalHead.h"
#include "EnemyBlazerSprite.h"
#include "EnemyFailingStone.h"
#include"EnemyScubarSoliderSprite.h"
#include "EnemyMineSprite.h"
#include"EnemyTankSprite.h"


EnemyCreator* EnemyCreator::instance = nullptr;

EnemyCreator::EnemyCreator()
{
	// set up the map direction by function addAppearDirection(std::string name , Direction dir )
	addAppearDirection("gunboss1", Direction::createRight());

	addAppearDirection("finalboss1", Direction::createRight());

	addAppearDirection("bridge", Direction::createRight());

	addAppearDirection("staticweapons", Direction::createRight() | Direction::createUp());
    addAppearDirection("staticweaponm", Direction::createRight() | Direction::createUp());
    addAppearDirection("staticweaponf", Direction::createRight() | Direction::createUp());
    addAppearDirection("staticweaponb", Direction::createRight() | Direction::createUp());
    addAppearDirection("staticweaponr", Direction::createRight() | Direction::createUp());
    addAppearDirection("staticweaponl", Direction::createRight() | Direction::createUp());

	addAppearDirection("gunrotating1", Direction::createRight());
	addAppearDirection("gunrotating3", Direction::createUp());

	addAppearDirection("cannon1", Direction::createRight());
	addAppearDirection("cannon3", Direction::createUp());

	addAppearDirection("sniper", Direction::createRight() | Direction::createUp());
    addAppearDirection("sniperh", Direction::createRight() | Direction::createUp());
	addAppearDirection("snipere", Direction::createRight() | Direction::createUp());

	addAppearDirection("capsuleweapons", Direction::createLeft());
	addAppearDirection("capsuleweaponm", Direction::createLeft());
	addAppearDirection("capsuleweaponf", Direction::createLeft());
	addAppearDirection("capsuleweaponb", Direction::createLeft());
	addAppearDirection("capsuleweaponr", Direction::createLeft());
	addAppearDirection("capsuleweaponl", Direction::createLeft());
	addAppearDirection("capsuleweapond", Direction::createLeft());

	addAppearDirection("capsuleweapon3s", Direction::createDown());
	addAppearDirection("capsuleweapon3m", Direction::createDown());
	addAppearDirection("capsuleweapon3f", Direction::createDown());
	addAppearDirection("capsuleweapon3b", Direction::createDown());
	addAppearDirection("capsuleweapon3r", Direction::createDown());
	addAppearDirection("capsuleweapon3l", Direction::createDown());

    addAppearDirection("boss2finalarmleft", Direction::createUp());
    addAppearDirection("boss2finalarmright", Direction::createUp());
    addAppearDirection("boss2finalhead", Direction::createUp());
	addAppearDirection("soldierl", Direction::createRight());
    addAppearDirection("soldierr", Direction::createLeft());
    addAppearDirection("soldiershotl", Direction::createNone() | Direction::createRight());
    addAppearDirection("soldiershotr", Direction::createUp() | Direction::createLeft());

	addAppearDirection("blazer", Direction::createUp());
	addAppearDirection("dynamicbridge", Direction::createUp());
	addAppearDirection("failingstone", Direction::createNone());

	addAppearDirection("scubarsolider1", Direction::createUp());
	addAppearDirection("scubarsolider2", Direction::createUp());
	addAppearDirection("scubarsolider3", Direction::createUp()| Direction::createRight());

	addAppearDirection("finalboss5", Direction::createRight());
	addAppearDirection("mine", Direction::createNone());
	addAppearDirection("bazoka", Direction::createRight());
	addAppearDirection("tank", Direction::createRight());
}

void EnemyCreator::addAppearDirection(std::string name, Direction dir)
{
	appearDirections[name] = dir;
}

EnemyCreator* EnemyCreator::getInstance()
{
	if (instance == nullptr)
	{
		instance = new EnemyCreator();
	}
	return instance;
}

EnemySprite* EnemyCreator::createEnemySprite(std::string EnemyName, int respawnX, int respawnY, std::vector < BulletSprite* >& bulletSprites)
{
	if (EnemyName == "ink")
	{
		return new EnemyInkSprite(respawnX, respawnY);
	}

	if (EnemyName == "gunrotating1")
	{
		return new EnemyGunRotating(respawnX, respawnY,1, bulletSprites);
	}

	if (EnemyName == "gunrotating3")
	{
		return new EnemyGunRotating(respawnX, respawnY, 3, bulletSprites);
	}

	if (EnemyName == "cannon1")
	{
		return new EnemyCannon(respawnX, respawnY, 1, bulletSprites);
	}

	if (EnemyName == "cannon3")
	{
		return new EnemyCannon(respawnX, respawnY, 3, bulletSprites);
	}

	if (EnemyName == "soldierl")
	{
		return new EnemySoldier(respawnX, respawnY, Direction::createLeft());
	}

	if (EnemyName == "soldierr")
	{
		return new EnemySoldier(respawnX, respawnY, Direction::createRight());
	}

    if (EnemyName == "soldiershotl")
    {
        //from left
        return new EnemySoldier(respawnX, respawnY, Direction::createLeft(), true, bulletSprites);
    }

    if (EnemyName == "soldiershotr")
    {
        return new EnemySoldier(respawnX, respawnY, Direction::createRight(), true, bulletSprites);
    }

	if (EnemyName == "sniper")
	{
		return new EnemySniper(respawnX, respawnY, bulletSprites);
	}

    if (EnemyName == "sniperh")
    {
        return new EnemySniper(respawnX, respawnY, bulletSprites,2);
    }
	if (EnemyName == "snipere")
	{
		return new EnemySniper(respawnX, respawnY, bulletSprites, 3);
	}

	if (EnemyName == "gunboss1")
	{
		return new EnemyGunBoss1Sprite(respawnX, respawnY, bulletSprites);
	}

	if (EnemyName == "finalboss1")
	{
		return new EnemyFinalBoss1Sprite(respawnX, respawnY);
	}


    if (EnemyName == "boss2finalarmleft")
    {
        return new Boss2FinalArm(respawnX, respawnY, bulletSprites, Boss2FinalData::ArmSide::LEFT);
    }

    if (EnemyName == "boss2finalarmright")
    {
        return new Boss2FinalArm(respawnX, respawnY, bulletSprites, Boss2FinalData::ArmSide::RIGHT);
    }

    if (EnemyName == "boss2finalhead")
    {
        return new Boss2FinalHead(respawnX, respawnY, bulletSprites);
    }

	if (EnemyName == "finalboss5")
	{
		return new EnemyFinalBoss5Sprite(respawnX, respawnY, bulletSprites);
	}

	if (EnemyName == "blazer")
	{
		return new EnemyBlazerSprite(respawnX, respawnY);
	}

	if (EnemyName == "failingstone")
	{
		return new EnemyFailingStone(respawnX, respawnY);
	}
	if (EnemyName == "scubarsolider1")
	
	{
		
		return new EnemyScubarSoliderSprite(respawnX, respawnY,1, bulletSprites);

	}

	
	if (EnemyName == "scubarsolider2")
	
	{
		
		return new EnemyScubarSoliderSprite(respawnX, respawnY, 2, bulletSprites);

	}

	
	if (EnemyName == "scubarsolider3")
	
	{

		return new EnemyScubarSoliderSprite(respawnX, respawnY, 3, bulletSprites);

	}

	if (EnemyName == "mine")
	{
		return new EnemyMineSprite(respawnX, respawnY);
	}

	if (EnemyName == "bazoka")
	{
		return new EnemyBazokaSprite(respawnX, respawnY, bulletSprites);
	}

	if (EnemyName == "tank")
	{
		return new EnemyTankSprite(respawnX, respawnY, bulletSprites);
	}

	return nullptr;
}

ObjectSprite* EnemyCreator::createObjectSprite(std::string name, int respawnX, int respawnY)
{
	if (name == "bridge")
	{
		return new ObjectBridge(respawnX, respawnY, 2);
	}

	if (name == "staticweapons")
	{
		return new ObjectStaticWeapon(respawnX, respawnY, BulletTypes::S);
	}

	if (name == "staticweaponm")
	{
		return new ObjectStaticWeapon(respawnX, respawnY, BulletTypes::M);
	}

	if (name == "staticweaponf")
	{
		return new ObjectStaticWeapon(respawnX, respawnY, BulletTypes::F);
	}

	if (name == "staticweaponb")
	{
		return new ObjectStaticWeapon(respawnX, respawnY, BulletTypes::B);
	}

	if (name == "staticweaponr")
	{
		return new ObjectStaticWeapon(respawnX, respawnY, BulletTypes::R);
	}

	if (name == "staticweaponl")
	{
		return new ObjectStaticWeapon(respawnX, respawnY, BulletTypes::L);
	}

	//capsule weapon
	if (name == "capsuleweapons")
	{
		return new ObjectCapsuleWeapon(respawnX, respawnY, 1, BulletTypes::S);
	}

	if (name == "capsuleweaponm")
	{
		return new ObjectCapsuleWeapon(respawnX, respawnY, 1, BulletTypes::M);
	}

	if (name == "capsuleweaponf")
	{
		return new ObjectCapsuleWeapon(respawnX, respawnY, 1, BulletTypes::F);
	}

	if (name == "capsuleweaponb")
	{
		return new ObjectCapsuleWeapon(respawnX, respawnY, 1, BulletTypes::B);
	}

	if (name == "capsuleweaponr")
	{
		return new ObjectCapsuleWeapon(respawnX, respawnY, 1, BulletTypes::R);
	}

	if (name == "capsuleweaponl")
	{
		return new ObjectCapsuleWeapon(respawnX, respawnY, 1, BulletTypes::L);
	}

	if (name == "capsuleweapond")
	{
		return new ObjectCapsuleWeapon(respawnX, respawnY, 1, BulletTypes::D);
	}
	//capsuleweapon stage 3
	if (name == "capsuleweapon3s")
	{
		return new ObjectCapsuleWeapon(respawnX, respawnY, 3, BulletTypes::S);
	}

	if (name == "capsuleweapon3m")
	{
		return new ObjectCapsuleWeapon(respawnX, respawnY, 3, BulletTypes::M);
	}

	if (name == "capsuleweapon3f")
	{
		return new ObjectCapsuleWeapon(respawnX, respawnY, 3, BulletTypes::F);
	}

	if (name == "capsuleweapon3b")
	{
		return new ObjectCapsuleWeapon(respawnX, respawnY, 3, BulletTypes::B);
	}

	if (name == "capsuleweapon3r")
	{
		return new ObjectCapsuleWeapon(respawnX, respawnY, 3, BulletTypes::R);
	}

	if (name == "capsuleweapon3l")
	{
		return new ObjectCapsuleWeapon(respawnX, respawnY, 3, BulletTypes::L);
	}

	if (name == "dynamicbridge")
	{
		return new ObjectDynamicBridgeSprite(respawnX, respawnY);
	}


	return nullptr;
}


Direction EnemyCreator::getAppearDir(std::string name)
{
	std::map < std::string, Direction >::iterator it = appearDirections.find(name);
	if (it != appearDirections.end())
	{
		return it->second;
	}
	return Direction::createNone();
}