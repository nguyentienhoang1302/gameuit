#ifndef __SELECTION_SCENE_H__
#define __SELECTION_SCENE_H__

#include "../../Const.h"
#include "../Managers/SoundManager.h"
#include "../../Graphics/Sprite.h"

#include "../TextSprite.h"

#include "BeginPlayScene.h"
#include "Scene.h"

class SelectionScene : public Scene, public IControlable
{
public:
	SelectionScene();
	~SelectionScene();

	bool virtual init();
	void virtual updateInput(float dt);
	void virtual update(float dt);
	void virtual draw(LPD3DXSPRITE spriteHandle);
	void virtual release();

private:
	int _selectIndex;
	int _maxIndex;
	int _gap;

	TextSprite* _stage1;
	TextSprite* _stage3;

	Sprite* _yellowFancon;
	Sprite* _tutLayer;
};

#endif // !__SELECTION_SCENE_H__
