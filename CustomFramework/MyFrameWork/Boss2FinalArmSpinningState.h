#pragma once
#include "Boss2FinalArmWaveState.h"
#include "Boss2FinalArmAttackState.h"
#include "EnemyState.h"
#include "Boss2FinalData.h"
#include "Boss2FinalBullet.h"

class Boss2FinalArmSpinningState : public EnemyState
{
public:
    Boss2FinalArmSpinningState(EnemyData *pData);
    ~Boss2FinalArmSpinningState();

    void onUpdate();

private:
    
    void moveAround(Boss2FinalJoint* joint, Boss2FinalJoint* joint0, float deltaRadius, float speed, float frame,
        Boss2FinalJoint::MoveAroundDirection dir, float delay = 0);
    float getAngle(D3DXVECTOR2 pos1, D3DXVECTOR2 pos2);

    const int FRAME_ATTACK;
    float speedAngle;
    float numRound; //so vong xoay de doi state
    int totalFrame;
    int delayChangeState;
    int frameAttack;
    Boss2FinalJoint **joints;
};

