#pragma once
#include"Sprite.h"

class SoliderSprite : public Sprite
{
public:
	Type type;
	SoliderSprite() {};
	SoliderSprite(Type type, int left, int top, int right, int bottom);
};