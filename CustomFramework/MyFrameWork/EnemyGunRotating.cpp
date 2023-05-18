#include"EnemyGunRotating.h"
#include"EnemyGunRotatingData.h"
#include<sstream>
#include <iomanip>

EnemyGunRotating::EnemyGunRotating(float respawnX, float respawnY, int isStage, std::vector < BulletSprite*>& bulletSpriteVector) :EnemySprite(bulletSpriteVector)
{
	pData = new EnemyGunRotatingData(bulletSpriteVector);
	pData->x = respawnX;
	pData->y = respawnY;

	pData->stage = isStage;

	this->initTextureArrays(EnemyGunRotatingData::COUNT);
	this->addTextureArray(EnemyGunRotatingData::CLOSE, "close",1,6);
	pData->ppTextureArrays[EnemyGunRotatingData::CLOSE]->setAnchorPoint(0.5f, 0.5f);
	this->addTextureArray(EnemyGunRotatingData::OPEN, "open", 1, 6);
	pData->ppTextureArrays[EnemyGunRotatingData::OPEN]->setAnchorPoint(0.5f, 0.5f);
	this->addTextureArray(EnemyGunRotatingData::SWAVEL1, "swavel1", 1, 6);
	pData->ppTextureArrays[EnemyGunRotatingData::SWAVEL1]->setAnchorPoint(0.5f, 0.5f);
	this->addTextureArray(EnemyGunRotatingData::SWAVEL2, "swavel2", 1, 6);
	pData->ppTextureArrays[EnemyGunRotatingData::SWAVEL2]->setAnchorPoint(0.5f, 0.5f);
	this->addTextureArray(EnemyGunRotatingData::SWAVEL3, "swavel3", 1, 6);
	pData->ppTextureArrays[EnemyGunRotatingData::SWAVEL3]->setAnchorPoint(0.5f, 0.5f);
	this->addTextureArray(EnemyGunRotatingData::SWAVEL4, "swavel4", 1, 6);
	pData->ppTextureArrays[EnemyGunRotatingData::SWAVEL4]->setAnchorPoint(0.5f, 0.5f);
	this->addTextureArray(EnemyGunRotatingData::SWAVEL5, "swavel5", 1, 6);
	pData->ppTextureArrays[EnemyGunRotatingData::SWAVEL5]->setAnchorPoint(0.5f, 0.5f);
	this->addTextureArray(EnemyGunRotatingData::SWAVEL6, "swavel6", 1, 6);
	pData->ppTextureArrays[EnemyGunRotatingData::SWAVEL6]->setAnchorPoint(0.5f, 0.5f);
	this->addTextureArray(EnemyGunRotatingData::SWAVEL7, "swavel7", 1, 6);
	pData->ppTextureArrays[EnemyGunRotatingData::SWAVEL7]->setAnchorPoint(0.5f, 0.5f);
	this->addTextureArray(EnemyGunRotatingData::SWAVEL8, "swavel8", 1, 6);
	pData->ppTextureArrays[EnemyGunRotatingData::SWAVEL8]->setAnchorPoint(0.5f, 0.5f);
	this->addTextureArray(EnemyGunRotatingData::SWAVEL9, "swavel9", 1, 6);
	pData->ppTextureArrays[EnemyGunRotatingData::SWAVEL9]->setAnchorPoint(0.5f, 0.5f);
	this->addTextureArray(EnemyGunRotatingData::SWAVEL10, "swavel10", 1, 6);
	pData->ppTextureArrays[EnemyGunRotatingData::SWAVEL10]->setAnchorPoint(0.5f, 0.5f);
	this->addTextureArray(EnemyGunRotatingData::SWAVEL11, "swavel11", 1, 6);
	pData->ppTextureArrays[EnemyGunRotatingData::SWAVEL11]->setAnchorPoint(0.5f, 0.5f);
	this->addTextureArray(EnemyGunRotatingData::SWAVEL12, "swavel12", 1, 6);
	pData->ppTextureArrays[EnemyGunRotatingData::SWAVEL12]->setAnchorPoint(0.5f, 0.5f);
	pData->ppTextureArrays[EnemyGunRotatingData::DIE] = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "", 3, 16);
	pData->ppTextureArrays[EnemyGunRotatingData::DIE]->setAnchorPoint(0.5f, 0.5f);

	pData->dir = Direction::createRight();
	pData->body = RectF(-16.0f, -32.0f, 32.0f, 32.0f);
	pData->pState = new EnemyGunRotatingClosingState(pData);
	
}

EnemyGunRotating::~EnemyGunRotating()
{
	
}

void EnemyGunRotating::draw(Camera *cam)
{
	if (pData->dir.isRight())
		pData->ppTextureArrays[pData->iCurrentArr]->draw(pData->x, pData->y, cam);
	else if (pData->dir.isLeft())
		pData->ppTextureArrays[pData->iCurrentArr]->drawFlipX(pData->x, pData->y, cam);
}

void EnemyGunRotating::update()
{
	pData->pState->onUpdate();
}

void EnemyGunRotating::loadResources()
{
	TextureArray* temp;
	
	// load sprite
	temp = new TextureArray("Resources\\Sprites", "gunrotating", "close", 1, 6);
	delete temp;

	temp = new TextureArray("Resources\\Sprites", "gunrotating", "open", 1, 6);
	delete temp;

	std::stringstream s;
	for (int i = 1; i < 13; i++)
	{
		s << std::setw(1)<< i;
		temp = new TextureArray("Resources\\Sprites", "gunrotating",std::string("swavel") + s.str(), 1, 6);
		delete temp;
	}

	temp = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "", 3, 16);
	delete temp;

	// load bullet
	temp = new TextureArray("Resources\\Sprites\\Bullets", "wbullet", "", 1, 10);
	delete temp;
	
}

void EnemyGunRotating::playBeShootedEffect()
{
	Sound::getInstance()->play("beShooted", false, 1);
}