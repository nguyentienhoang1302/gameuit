#include "EnemyGunRotatingClosingState.h"
#include "EnemySprite.h"
#include "PlayerSprite.h"
#include "Camera.h"
#define PI 3.4

class EnemyGunRotating :public EnemySprite
{
public:
	EnemyGunRotating(float x, float y, int isStage, std::vector < BulletSprite*>& bulletSpriteVector);
	~EnemyGunRotating();
	void update();
	void draw(Camera *cam);
	static void loadResources();
	virtual void playBeShootedEffect();

};