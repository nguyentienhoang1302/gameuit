#pragma once
#include "EnemyState.h"
#include "Boss2FinalData.h"
#include "Boss2FinalBullet.h"
#include "Boss2FinalHeadOpeningState.h"

class Boss2FinalHeadShuttingState : public EnemyState
{
public:
    Boss2FinalHeadShuttingState(EnemyData *pData);
    ~Boss2FinalHeadShuttingState();

    void onUpdate();

private:
    int frameCountOpen;
    bool isStartChange;
};

