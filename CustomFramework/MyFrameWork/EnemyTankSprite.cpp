#include"EnemyTankSprite.h"
#include"EnemyTankData.h"
#include"EnemyTankStartingState.h"
#include"Sound.h"

EnemyTankSprite::EnemyTankSprite(int respawnX, int respawnY, std::vector<BulletSprite*>& bulletSpriteVector)
	: EnemySprite(bulletSpriteVector)
{
	pData = new EnemyTankData(bulletSpriteVector);

	pData->x = respawnX;
	pData->y = respawnY;

	pData->ppTextureArrays = new TextureArray*[13];

	pData->ppTextureArrays[0] = new TextureArray("Resources\\Sprites\\Enemy", "tank", "start0", 1, 6);
	pData->ppTextureArrays[0]->setAnchorPoint(0.1f, 1.0f);

	pData->ppTextureArrays[1] = new TextureArray("Resources\\Sprites\\Enemy", "tank", "start1", 1, 6);
	pData->ppTextureArrays[1]->setAnchorPoint(0.1f, 1.0f);

	pData->ppTextureArrays[2] = new TextureArray("Resources\\Sprites\\Enemy", "tank", "start2", 1, 6);
	pData->ppTextureArrays[2]->setAnchorPoint(0.1f, 1.0f);

	pData->ppTextureArrays[3] = new TextureArray("Resources\\Sprites\\Enemy", "tank", "between0", 1, 6);
	pData->ppTextureArrays[3]->setAnchorPoint(0.1f, 1.0f);

	pData->ppTextureArrays[4] = new TextureArray("Resources\\Sprites\\Enemy", "tank", "between1", 1, 6);
	pData->ppTextureArrays[4]->setAnchorPoint(0.1f, 1.0f);

	pData->ppTextureArrays[5] = new TextureArray("Resources\\Sprites\\Enemy", "tank", "between2", 1, 6);
	pData->ppTextureArrays[5]->setAnchorPoint(0.1f, 1.0f);

	pData->ppTextureArrays[6] = new TextureArray("Resources\\Sprites\\Enemy", "tank", "next0", 1, 6);
	pData->ppTextureArrays[6]->setAnchorPoint(0.1f, 1.0f);

	pData->ppTextureArrays[7] = new TextureArray("Resources\\Sprites\\Enemy", "tank", "next1", 1, 6);
	pData->ppTextureArrays[7]->setAnchorPoint(0.1f, 1.0f);

	pData->ppTextureArrays[8] = new TextureArray("Resources\\Sprites\\Enemy", "tank", "next2", 1, 6);
	pData->ppTextureArrays[8]->setAnchorPoint(0.1f, 1.0f);

	pData->ppTextureArrays[9] = new TextureArray("Resources\\Sprites\\Enemy", "tank", "finally0", 1, 6);
	pData->ppTextureArrays[9]->setAnchorPoint(0.1f, 1.0f);

	pData->ppTextureArrays[10] = new TextureArray("Resources\\Sprites\\Enemy", "tank", "finally1", 1, 6);
	pData->ppTextureArrays[10]->setAnchorPoint(0.1f, 1.0f);

	pData->ppTextureArrays[11] = new TextureArray("Resources\\Sprites\\Enemy", "tank", "finally2", 1, 6);
	pData->ppTextureArrays[11]->setAnchorPoint(0.1f, 1.0f);

	pData->ppTextureArrays[12] = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "", 3, 8);
	pData->ppTextureArrays[12]->setAnchorPoint(0.1f, 1.0f);

	pData->ppTextureArrays[13] = new TextureArray("Resources\\Sprites\\Enemy", "tank", "start0", 2, 6);
	pData->ppTextureArrays[13]->setAnchorPoint(0.1f, 1.0f);

	pData->ppTextureArrays[14] = new TextureArray("Resources\\Sprites\\Enemy", "tank", "between0", 2, 6);
	pData->ppTextureArrays[14]->setAnchorPoint(0.1f, 1.0f);

	pData->ppTextureArrays[15] = new TextureArray("Resources\\Sprites\\Enemy", "tank", "next0", 2, 6);
	pData->ppTextureArrays[15]->setAnchorPoint(0.1f, 1.0f);

	pData->ppTextureArrays[16] = new TextureArray("Resources\\Sprites\\Enemy", "tank", "finally0", 2, 6);
	pData->ppTextureArrays[16]->setAnchorPoint(0.1f, 1.0f);

	pData->dir = Direction::createRight();
	pData->body = RectF(-97 / 10 * 1.0f, -62.0f, 97.0f, 62.0f);
	//pData->body = RectF(-24.0f, -65.0f, 24.0f, 65.0f);
	pData->pState = new EnemyTankStartingState(pData, 40);

}

void EnemyTankSprite::draw(Camera *cam)
{
	if (pData->dir.isRight())
		pData->ppTextureArrays[pData->iCurrentArr]->draw(pData->x, pData->y, cam);
	else if (pData->dir.isLeft())
		pData->ppTextureArrays[pData->iCurrentArr]->drawFlipX(pData->x, pData->y, cam);
}

void EnemyTankSprite::update()
{
	pData->pState->onUpdate();
}

void EnemyTankSprite::loadResources()
{
	TextureArray* temp;

	// load sprite
	temp = new TextureArray("Resources\\Sprites\\Enemy", "tank", "start0", 1, 6);
	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Enemy", "tank", "start1", 1, 6);
	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Enemy", "tank", "start2", 1, 6);
	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Enemy", "tank", "between0", 1, 6);
	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Enemy", "tank", "between1", 1, 6);
	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Enemy", "tank", "between2", 1, 6);
	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Enemy", "tank", "next0", 1, 6);
	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Enemy", "tank", "next1", 1, 6);
	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Enemy", "tank", "next2", 1, 6);
	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Enemy", "tank", "finally0", 1, 6);
	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Enemy", "tank", "finally1", 1, 6);
	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Enemy", "tank", "finally2", 1, 6);
	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "", 3, 8);
	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Enemy", "tank", "start0", 2, 6);
	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Enemy", "tank", "between0", 2, 6);
	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Enemy", "tank", "next0", 2, 6);
	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Enemy", "tank", "finally0", 2, 6);
	delete temp;
}

void EnemyTankSprite::playBeShootedEffect()
{
	Sound::getInstance()->play("beShooted", false, 1);
}

EnemyTankSprite::~EnemyTankSprite()
{

}