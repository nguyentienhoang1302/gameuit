#pragma once
#include "EnemyState.h"
#include "Boss2FinalData.h"
#include "Boss2FinalArmWaveState.h"
#include "Boss2FinalArm.h"

class Boss2FinalArmStartState : public EnemyState
{
public:
    Boss2FinalArmStartState(EnemyData *pData);
    ~Boss2FinalArmStartState();

    void onUpdate();

private:
    D3DXVECTOR2 direction;    
    float speedFrame, distance, delayFrame;
};

