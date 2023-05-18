#include"EnemyScubarSoliderSprite.h"
#include"BulletScubarSoliderSprite.h"
#include"EnemyScubarSoliderShootState.h"
#include"EnemyScubarSoliderData.h"
#include"EnemyScubarSoliderHidingState.h"
#include"Sound.h"



EnemyScubarSoliderSprite::EnemyScubarSoliderSprite(int respawnX, int respawnY,int kind, std::vector < BulletSprite*>& bulletSpriteVector)
	:EnemySprite(bulletSpriteVector)
{
	pData = new EnemyScubarSoliderData(bulletSpriteVector);

	pData->x = respawnX;
	pData->y = respawnY;

	pData->stage = kind; // kind == 1, scubar vi tri 1, 3, kind == 2 scubar vi tri 2

	pData->ppTextureArrays = new TextureArray*[2];

	pData->ppTextureArrays[0] = new TextureArray("Resources\\Sprites", "scubarsolider", "hide", 1, 6);
	pData->ppTextureArrays[0]->setAnchorPoint(0.5f, 0.5f);

	pData->ppTextureArrays[1] = new TextureArray("Resources\\Sprites", "scubarsolider", "shoot", 1, 6);
	pData->ppTextureArrays[1]->setAnchorPoint(0.5f, 0.5f);

	pData->ppTextureArrays[2] = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "", 3, 16);
	pData->ppTextureArrays[2]->setAnchorPoint(0.5f, 0.5f);

	pData->dir = Direction::createRight();

	pData->body = RectF(-20.0f / 2, -18.0f, 20.0f, 18.0f);

	pData->pState = new EnemyScubarSoliderHidingState(pData);
}

EnemyScubarSoliderSprite::~EnemyScubarSoliderSprite()
{

}

void EnemyScubarSoliderSprite::loadResources()
{

	TextureArray* temp = new TextureArray("Resources\\Sprites", "scubarsolider", "hide", 1, 6);
	delete temp;

	temp = new TextureArray("Resources\\Sprites", "scubarsolider", "shoot", 1, 6);
	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Bullets", "gunboss1bullet", "", 1, 60);
	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "", 6, 8);
	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "type1", 6, 8);
	delete temp;
}
void EnemyScubarSoliderSprite::draw(Camera* cam)
{
	if (pData->dir.isRight())
		pData->ppTextureArrays[pData->iCurrentArr]->draw(pData->x, pData->y, cam);
	else
		if (pData->dir.isLeft())
			pData->ppTextureArrays[pData->iCurrentArr]->drawFlipX(pData->x, pData->y, cam);
}

void EnemyScubarSoliderSprite::update()
{
	pData->pState->onUpdate();
}

void EnemyScubarSoliderSprite::playBeShootedEffect()
{
	Sound::getInstance()->play("beShooted", false, 1);
}