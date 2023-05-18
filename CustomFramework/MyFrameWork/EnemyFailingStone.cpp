#include "EnemyFailingStone.h"


EnemyFailingStone::EnemyFailingStone(float respawnX, float respawnY)
{
	pData = new EnemyFailingStoneData();
	pData->x = respawnX;
	pData->y = respawnY;

	this->initTextureArrays(EnemyFailingStoneData::COUNT);
	//this->addTextureArray(EnemyFailingStoneData::APPEAR, "appear", 4, 6);
	pData->ppTextureArrays[EnemyFailingStoneData::APPEAR] = new TextureArray("Resources\\Sprites", "failingstone", "appear", 1, 60);
	pData->ppTextureArrays[EnemyFailingStoneData::APPEAR]->setAnchorPoint(0.5f, 1.0f);

	pData->ppTextureArrays[EnemyFailingStoneData::DROP] = new TextureArray("Resources\\Sprites", "failingstone", "appear", 4, 6);
	pData->ppTextureArrays[EnemyFailingStoneData::DROP]->setAnchorPoint(0.5f, 1.0f);

	pData->ppTextureArrays[EnemyFailingStoneData::DEAD] = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "", 3, 8);
	pData->ppTextureArrays[EnemyFailingStoneData::DEAD]->setAnchorPoint(0.5f, 1.0f);

	pData->dir = Direction::createRight();
	pData->body = RectF(-8.0f, -16.0f, 16.0f, 16.0f);
	pData->HP = 8;
	pData->pState = new EnemyFailingStoneAppearingState(pData);
}


EnemyFailingStone::~EnemyFailingStone()
{
}

void EnemyFailingStone::draw(Camera* cam)
{
	if (pData->dir.isRight())
		pData->ppTextureArrays[pData->iCurrentArr]->draw(pData->x, pData->y, cam);
	else if (pData->dir.isLeft())
		pData->ppTextureArrays[pData->iCurrentArr]->drawFlipX(pData->x, pData->y, cam);
}

void EnemyFailingStone::update()
{
	pData->pState->onUpdate();
}

void EnemyFailingStone::loadResources()
{
	TextureArray* temp = new TextureArray("Resources\\Sprites", "failingstone", "appear", 4, 6);
	delete temp;
	temp = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "", 3, 8);
	delete temp;
}

void EnemyFailingStone::playBeShootedEffect()
{
	Sound::getInstance()->play("beShooted", false, 1);
}