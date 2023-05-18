#include "EnemyCannon.h"

EnemyCannon::EnemyCannon(int respawnX, int respawnY, int isStage, std::vector < BulletSprite*>& bulletSpriteVector)
	: 
	EnemySprite(bulletSpriteVector)
{
	pData = new EnemyCannonData(bulletSpriteVector);
	pData->x = respawnX;
	pData->y = respawnY;

	pData->stage = isStage;

	this->initTextureArrays(EnemyCannonData::COUNT);
	this->addTextureArray(EnemyCannonData::PREPARE, "prepare", 1, 60);
	pData->ppTextureArrays[EnemyCannonData::PREPARE]->setAnchorPoint(0.5f, 1.0f);
	this->addTextureArray(EnemyCannonData::APPEAR, "appear", 6, 5);
	pData->ppTextureArrays[EnemyCannonData::APPEAR]->setAnchorPoint(0.5f, 1.0f);
	this->addTextureArray(EnemyCannonData::TURN0, "standzero", 3, 6);
	pData->ppTextureArrays[EnemyCannonData::TURN0]->setAnchorPoint(0.5f, 1.0f);
	this->addTextureArray(EnemyCannonData::TURN30, "standthirty", 3, 6);
	pData->ppTextureArrays[EnemyCannonData::TURN30]->setAnchorPoint(0.5f, 1.0f);
	this->addTextureArray(EnemyCannonData::TURN60, "standsixty", 3, 6);
	pData->ppTextureArrays[EnemyCannonData::TURN60]->setAnchorPoint(0.5f, 1.0f);
	pData->ppTextureArrays[EnemyCannonData::DEAD] = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "", 3, 10);
	pData->ppTextureArrays[EnemyCannonData::DEAD]->setAnchorPoint(0.5f, 1.0f);

	pData->dir = Direction::createRight();
	pData->body = RectF(-16.0f, -32.0f, 32.0f, 32.0f);
	pData->HP = 8;
	pData->pState = new EnemyCannonPreaparingState(pData);
	
}

EnemyCannon::~EnemyCannon()
{

}

void EnemyCannon::draw(Camera* cam)
{
	if (pData->dir.isRight())
		pData->ppTextureArrays[pData->iCurrentArr]->draw(pData->x, pData->y, cam);
	else if (pData->dir.isLeft())
		pData->ppTextureArrays[pData->iCurrentArr]->drawFlipX(pData->x, pData->y, cam);
}

void EnemyCannon::update()
{
	pData->pState->onUpdate();
}

void EnemyCannon::loadResources()
{
	TextureArray* temp = new TextureArray("Resources\\Sprites\\cannon", "appear", "", 6, 5);
	delete temp;
	temp = new TextureArray("Resources\\Sprites\\cannon", "standzero", "", 3, 6);
	delete temp;
	temp = new TextureArray("Resources\\Sprites\\cannon", "standthirty", "", 3, 6);
	delete temp;
	temp = new TextureArray("Resources\\Sprites\\cannon", "standsixty", "", 3, 6);
	delete temp;
	temp = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "", 3, 10);
	delete temp;
}

void EnemyCannon::playBeShootedEffect()
{
	Sound::getInstance()->play("beShooted", false, 1);
}