#pragma once
#include "EnemyState.h"
#include "EnemySoldier.h"
#include "EnemySoldierDrowningState.h"

class EnemySoldierJumpingState : public EnemyState
{
public:
    EnemySoldierJumpingState(EnemyData *pData);
    ~EnemySoldierJumpingState();

    void onUpdate();
    void onCollision(RectF rect);
    void onCollision(CollisionRectF rect);
    //void onCameraCollision(RectF camera);

private:
    float acceleration;
};

