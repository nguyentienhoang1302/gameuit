#pragma once
#include "EnemyState.h"
#include "EnemyData.h"
#include "EnemySoldierJumpingState.h"
#include "EnemySoldierFallingState.h"
#include "EnemySoldierShootingState.h"

class EnemySoldierRunningState : public EnemyState
{
public:
    EnemySoldierRunningState(EnemyData* pData);
    ~EnemySoldierRunningState();

    void onUpdate();
    //void onCollision(RectF rect);
    void onCollision(CollisionRectF rect);
private:
    float acceleration;
    bool isFallDown;
    float frameShot;
};

