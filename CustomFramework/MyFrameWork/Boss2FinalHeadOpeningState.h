#pragma once
#include "EnemyState.h"
#include "Boss2FinalData.h"
#include "Boss2FinalBullet.h"
#include "Boss2FinalHeadShuttingState.h"
#include "Boss2FinalHeadAttackingState.h"

class Boss2FinalHeadOpeningState : public EnemyState
{
public:
    Boss2FinalHeadOpeningState(EnemyData *pData);
    ~Boss2FinalHeadOpeningState();
    void onUpdate();

private:
    int frameChange;
};

