#pragma once
#include "EnemyState.h"
#include "EnemySoldierRunningState.h"
#include "EnemyData.h"
#include "EnemySoldierDrowningState.h"

class EnemySoldierFallingState : public EnemyState
{
public:
    EnemySoldierFallingState(EnemyData *pData);
    ~EnemySoldierFallingState();

    void onUpdate();
    void onCollision(CollisionRectF rect);

private:
    float acceleration;
};

