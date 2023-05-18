#include "EnemyGunBoss1Sprite.h"
#include "EnemyGunBoss1StandingState.h"

EnemyGunBoss1Sprite :: EnemyGunBoss1Sprite( int respawnX, int respawnY, std::vector < BulletSprite*>& bulletSpriteVector)
	:
	EnemySprite(bulletSpriteVector)
{

	pData -> botName = "gunboss1";

	pData->x  = respawnX;

	pData->y  = respawnY;

	pData->ppTextureArrays = new TextureArray* [ 3 ];

	pData->ppTextureArrays[0 ] = new TextureArray("Resources\\Sprites\\Enemy" ,"gunboss1","stand", 1, 60);

	pData->ppTextureArrays[ 0 ] -> setAnchorPoint(0.5f, 1.0f );

	pData -> ppTextureArrays [ 1 ] = new TextureArray("Resources\\Sprites\\Enemy","gunboss1","fire", 1, 60);

	pData->ppTextureArrays[ 1 ] -> setAnchorPoint(0.5f, 1.0f );

	pData ->ppTextureArrays[2] = new TextureArray("Resources\\Sprites\\Explosions", "explosion","", 3, 8);

	pData->ppTextureArrays[ 2 ] -> setAnchorPoint(0.5f, 1.0f );

	pData ->dir = Direction::createLeft();

	pData ->pState = new EnemyGunBoss1StandingState(pData);

	pData -> isThrougable = false;

	pData -> HP = 16;

	pData -> score	= 1000;

	pData ->body = RectF( -6.0f, -6.0f, 12.0f, 8.0f);
}
void EnemyGunBoss1Sprite :: draw( Camera* cam) 
{
	if( pData -> dir.isRight())
		pData->ppTextureArrays[ pData->iCurrentArr ] -> drawFlipX(pData -> x, pData -> y , cam);
	else if( pData -> dir.isLeft())
		pData->ppTextureArrays[ pData->iCurrentArr ] -> draw(pData -> x, pData -> y , cam);
}
void EnemyGunBoss1Sprite :: update() 
{
	pData ->pState ->onUpdate();
}

void EnemyGunBoss1Sprite :: loadResources()
{
	// loadSprite
	TextureArray* temp = new TextureArray("Resources\\Sprites\\Enemy" ,"gunboss1","stand", 1, 60);
	delete temp;
	temp = new TextureArray("Resources\\Sprites\\Enemy","gunboss1","fire", 1, 60);
	delete temp;
	temp = new TextureArray("Resources\\Sprites\\Explosions", "explosion","", 6, 8);
	delete temp;

	// loadBullet
	temp = new TextureArray("Resources\\Sprites\\Bullets", "gunboss1bullet","", 1, 60, D3DCOLOR_XRGB(255,255,255));
	delete temp;
	temp = new TextureArray("Resources\\Sprites\\Explosions", "explosion","", 6, 8);
	delete temp;
}

void EnemyGunBoss1Sprite :: playBeShootedEffect()
{
	Sound::getInstance() -> play("beShooted", false, 1);
}