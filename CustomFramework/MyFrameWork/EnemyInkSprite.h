#pragma once

#include "EnemySprite.h"
#include "EnemyInkStandingState.h"
class EnemyInkSprite : public EnemySprite
{
public:
	EnemyInkSprite(int respawnX, int respawnY);
	virtual void draw( Camera* cam) ;
	virtual void update();
	virtual void setPlayerX(int x) ;
	virtual void setPlayerY( int y ) ;
};