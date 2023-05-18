#include "EnemyInkSprite.h"

EnemyInkSprite :: EnemyInkSprite( int respawnX, int respawnY)
{
	pData = new EnemyData();

	pData->x  = respawnX;

	pData->y  = respawnY;

	pData->ppTextureArrays = new TextureArray* [ 2 ];

	pData->ppTextureArrays[0 ] = new TextureArray("Resources\\Sprites\\Enemy\\" ,"ink","stand", 1, 30);

	pData->ppTextureArrays[ 0 ] -> setAnchorPoint(0.5f, 1.0f );

	pData -> ppTextureArrays [ 1 ] = new TextureArray("Resources\\Sprites\\Enemy\\","ink","jump", 1, 30);

	pData->ppTextureArrays[ 1 ] -> setAnchorPoint(0.5f, 1.0f );

	pData ->dir = Direction::createRight();

	pData ->pState = new EnemyInkStandingState(pData);

	pData ->body = RectF( -11.0f, -62.0f, 22.0f, 62.0f);
}

void EnemyInkSprite :: draw( Camera* cam) 
{
	if( pData -> dir.isRight())
		pData->ppTextureArrays[ pData->iCurrentArr ] -> draw(pData -> x, pData -> y , cam);
	else if( pData -> dir.isLeft())
		pData->ppTextureArrays[ pData->iCurrentArr ] -> drawFlipX(pData -> x, pData -> y , cam);
}

void EnemyInkSprite :: update() 
{
	pData ->pState ->onUpdate(); 

}

void EnemyInkSprite :: setPlayerX(int x) {pData ->playerX = x; }
void EnemyInkSprite :: setPlayerY( int y ) { pData ->playerY = y; }