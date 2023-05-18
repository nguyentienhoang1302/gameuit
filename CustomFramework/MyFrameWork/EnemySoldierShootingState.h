#pragma once
#include "EnemyState.h"
#include "EnemySoldierData.h"
#include "EnemyWhiteBullet.h"
#include "EnemySoldierRunningState.h"

class EnemySoldierShootingState : public EnemyState
{
public:
    EnemySoldierShootingState(EnemyData *pData);
    ~EnemySoldierShootingState();
    void onUpdate();

private:
    int frameDelayTransition;
};

