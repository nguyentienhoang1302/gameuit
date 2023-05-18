#pragma once
#include "EnemySprite.h"
#include "EnemySoldierData.h"
#include "EnemySoldierRunningState.h"
#include "EnemySoldierJumpingState.h"
#include "EnemySoldierDestroyState.h"
#include "EnemySoldierDieState.h"
#include "Camera.h"
#include "PlayerSprite.h"
#include "EnemyWhiteBullet.h"

class EnemySoldier : public EnemySprite
{
public:
    EnemySoldier(float x, float y, Direction dir, bool isShoter = false, std::vector<BulletSprite*>& bullet = std::vector<BulletSprite*>());
    ~EnemySoldier();

    void setSupportCollisionRect(CollisionRectF rect);
    void onCameraCollision(RectF cameraRect);
    void die();
    static void loadResources();
    //void update();
    //void draw(Camera *cam);
};


