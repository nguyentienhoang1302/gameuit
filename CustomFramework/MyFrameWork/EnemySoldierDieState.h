#pragma once
#include "EnemySoldierJumpingState.h"
#include "EnemySoldierRunningState.h"
#include "EnemySoldier.h"

class EnemySoldierDieState : public EnemyState
{
public:
    EnemySoldierDieState(EnemyData *pData);
    ~EnemySoldierDieState();

    void onUpdate();

private:
    float acceleration;
};

