#pragma once
#include "DemoScene.h"

class SceneManager
{
public:
	static SceneManager* getInstance() 
	{
		if(pInstance == nullptr )
		{
			pInstance = new SceneManager();
		}
		return pInstance;
	}

	void createScene(Scene* scene )
	{
		
		if(scene)
		{
			if(pCurrentScene)
			 delete pCurrentScene;
			pCurrentScene = scene;
		}
	}

	Scene* getCurrentScene() { return pCurrentScene ;}
private:
	SceneManager() 
	{
		pCurrentScene = NULL;
	}
	static SceneManager* pInstance;
	Scene* pCurrentScene;
    Scene* destScene;
};
