

#ifndef __INTRO_SCENE__
#define __INTRO_SCENE__

#include "../../Graphics/Sprite.h"
#include "../Managers/SpriteManager.h"
#include "../Managers/SoundManager.h"
#include "../../Graphics/InputController.h"
#include "../../Graphics/StopWatch.h"

#include "../Objects/IComponent.h"
#include "../Objects/BaseObject.h"
#include "../Objects/TextSprite.h"

#include "SelectionScene.h"
#include "Scene.h"

[event_receiver(native)]
class IntroScene : public Scene, public IControlable
{
public:
	IntroScene();
	~IntroScene();


	bool init() override;
	void update(float dt) override;
	void draw(LPD3DXSPRITE spriteHandle) override;
	void release() override;
	void updateInput(float deltatime) override;

private:
	Sprite* _yellowfancon;
	Sprite* _introtable;
	Movement* _movement;

	void onKeyPressed(KeyEventArg* key_event);
	StopWatch* _flash;
	StopWatch* _access;
	int _ok;
	bool _draw;
	bool _drawyellowFalcon;
	TextSprite* _playOption;
	TextSprite* _chosenOption;
};
#endif // !__INTRO_SCENE__
