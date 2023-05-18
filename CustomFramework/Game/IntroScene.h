#pragma once
#include "Scene.h"
#include "GameGlobal.h"
#include "Sprite.h"
#include "SpriteFactory.h"
#include "SceneManager.h"
#include "PlayScene.h"

class IntroScene : public Scene
{
private:
	Sprite* nameSprite;
	float vx;
	float vy;

public:
	IntroScene();
	~IntroScene();

	void Render();
	void Update(float dt);
	void OnKeyDown(int key);
};