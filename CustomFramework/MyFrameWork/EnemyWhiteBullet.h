#pragma once

#include "BulletSprite.h"


class EnemyWhiteBullet : public BulletSprite
{
public:

	EnemyWhiteBullet(float x, float y, bool  isBoosting, float angle, int  kindBullet = 0);
	virtual void draw(Camera* cam);
	virtual void update();
private:
	int kindBullet;
};