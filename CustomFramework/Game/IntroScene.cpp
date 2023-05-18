#include "IntroScene.h"

IntroScene::IntroScene()
{
	nameSprite = SpriteFactory::GetInstance()->GetSprite(INTROSCENE, 0);

	vx = 0.25;
	vy = 0.1;

	nameSprite->posX = SCREEN_HEIGHT / 2;
	nameSprite->posY = SCREEN_HEIGHT / 2;

	Sound::getInstance()->play("intro", true);
}

IntroScene::~IntroScene()
{

}

void IntroScene::Render()
{
	nameSprite->ScaleRender(nameSprite->posX, nameSprite->posY, 2, 2);
}

void IntroScene::Update(float dt)
{
	if (nameSprite->posX >= SCREEN_WIDTH >> 1)
	{
		nameSprite->posX = SCREEN_WIDTH >> 1;
	}
	else
	{
		nameSprite->posX += vx * dt;
	}

}

void IntroScene::OnKeyDown(int key)
{
	if (key == DIK_RETURN)
	{
		Sound::getInstance()->stop("intro");
		SceneManager::GetInstance()->ReplaceScene(new PlayScene(1));
	}
}
