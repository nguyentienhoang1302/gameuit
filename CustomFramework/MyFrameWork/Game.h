#pragma once

#include "SceneManager.h"
#include "Graphics.h"
#include "Sound.h"

class Game
{

public :
	Game(HWND hWnd);
	~Game()
	{}
	void cleanUp();
	void update();
	void render();
};