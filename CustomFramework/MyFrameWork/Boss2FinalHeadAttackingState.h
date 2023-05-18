#pragma once
#include "EnemyState.h"
#include "Boss2FinalData.h"
#include "Boss2FinalBullet.h"
#include "Boss2FinalHeadOpeningState.h"

class Boss2FinalHeadAttackingState : public EnemyState
{
public:
    Boss2FinalHeadAttackingState(EnemyData *pData);
    ~Boss2FinalHeadAttackingState();
    void onUpdate();

private:
    int frameAttack;
};

