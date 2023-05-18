#pragma once
#include "EnemyState.h"
#include "EnemyData.h"
#include "EnemySniperData.h"
#include "EnemySniperShowingState.h"

class EnemySniperHidingState : public EnemyState
{
public:
    EnemySniperHidingState(EnemyData* pData);
    ~EnemySniperHidingState();

    virtual void onUpdate();

private:
    float rangeChangeState;
    int frameChangeState;
};

