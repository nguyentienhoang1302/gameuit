#include "EnemyFinalBoss5Sprite.h"


EnemyFinalBoss5Sprite::EnemyFinalBoss5Sprite(float respawnX, float respawnY, std::vector < BulletSprite*>& bulletSpriteVector)
	:
	EnemySprite(bulletSpriteVector)
{
	//pData = new EnemyData();
	pData->botName = "finalboss5";
	pData->x = respawnX;
	pData->y = respawnY;

	pData->ppTextureArrays = new TextureArray*[5];
	//prepare
	pData->ppTextureArrays[0] = new TextureArray("Resources\\Sprites\\finalboss5", "finalboss5", "prepare", 1, 60);
	pData->ppTextureArrays[0]->setAnchorPoint(0.5f, 0.5f);
	//appear
	pData->ppTextureArrays[1] = new TextureArray("Resources\\Sprites\\finalboss5", "finalboss5", "appear", 10, 5);
	pData->ppTextureArrays[1]->setAnchorPoint(0.5f, 0.5f);
	//waiting
	pData->ppTextureArrays[2] = new TextureArray("Resources\\Sprites\\finalboss5", "finalboss5", "waiting", 2, 5);
	pData->ppTextureArrays[2]->setAnchorPoint(0.5f, 0.5f);
	//disappear
	pData->ppTextureArrays[3] = new TextureArray("Resources\\Sprites\\finalboss5", "finalboss5", "disappear", 10, 5);
	pData->ppTextureArrays[3]->setAnchorPoint(0.5f, 0.5f);
	//die
	pData->ppTextureArrays[4] = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "", 3, 8);
	pData->ppTextureArrays[4]->setAnchorPoint(0.5f, 0.5f);

	pData->pState = new EnemyFinalBoss5PreparingState(pData);
	pData->dir = Direction::createRight();

	pData->isDesTroyed = false;
	pData->isHittable = false;
	pData->isThrougable = true;
	pData->HP = 50;
	pData->score = 15000;
	pData->body = RectF(-31.0f, -33.5f, 62.0f, 67.0f);
}


EnemyFinalBoss5Sprite::~EnemyFinalBoss5Sprite()
{
}

void EnemyFinalBoss5Sprite::loadResources()
{
	TextureArray* temp = new TextureArray("Resources\\Sprites\\finalboss5", "finalboss5", "prepare", 1, 60);
	delete temp;
	temp = new TextureArray("Resources\\Sprites\\finalboss5", "finalboss5", "appear", 10, 5);
	delete temp;
	temp = new TextureArray("Resources\\Sprites\\finalboss5", "finalboss5", "waiting", 2, 5);
	delete temp;
	temp = new TextureArray("Resources\\Sprites\\finalboss5", "finalboss5", "disappear", 10, 5);
	delete temp;
	temp = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "", 6, 8);
	delete temp;
}

void EnemyFinalBoss5Sprite::playBeShootedEffect()
{
	Sound::getInstance()->play("beShooted", false, 1);
}