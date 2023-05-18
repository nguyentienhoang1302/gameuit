#pragma once
#include "EnemyState.h"
#include "EnemySoldierData.h"

class EnemySoldierDrowningState : public EnemyState
{
public:
    EnemySoldierDrowningState(EnemyData *pData);
    ~EnemySoldierDrowningState();
    void onUpdate();
};

