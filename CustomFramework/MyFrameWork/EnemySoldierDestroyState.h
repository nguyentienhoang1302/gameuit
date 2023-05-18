#pragma once
#include "EnemyState.h"
#include "EnemyData.h"
#include "EnemySoldierData.h"
#include "Sound.h"

class EnemySoldierDestroyState : public EnemyState
{
public:
    EnemySoldierDestroyState(EnemyData *pData);
    ~EnemySoldierDestroyState();

    void onUpdate();
};

