
#include "Game.h"
#include <vector>
#include "iostream"

Game:: Game(HWND hWnd)
{
	Graphics::create(hWnd);
	Sound::create(hWnd);
	SceneManager::getInstance()->createScene(new DemoScene());
}

void Game :: update()
{
    SceneManager::getInstance()->getCurrentScene()->onUpdate();
}

void Game :: render()
{

    SceneManager::getInstance()->getCurrentScene()->render();
}

void Game :: cleanUp()
{
	UIComponents::getInstance() -> cleanUp();
	Sound::getInstance() -> cleanUp();
	Graphics::getInstance() -> cleanUp();
}
