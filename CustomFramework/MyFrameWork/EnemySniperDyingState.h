#pragma once
#include "EnemyState.h"
#include "EnemyData.h"
#include "EnemySniperData.h"
#include "EnemySniperDeadState.h"
#include "EnemySniperShowingState.h"

class EnemySniperDyingState : public EnemyState
{
public:
    EnemySniperDyingState(EnemyData* pData);
    ~EnemySniperDyingState();

    virtual void onUpdate();

private:
    float acc;
};

