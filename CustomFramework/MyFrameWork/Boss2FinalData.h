#pragma once
#include "Boss2FinalJoint.h"
#include "Boss2FinalHand.h"
#include "BulletSprite.h"
#include "EnemyData.h"

class Boss2FinalData : public EnemyData
{
public:
    enum ArmSide
    {
        LEFT,
        RIGHT
    };

    enum ArrayIndex
    {
        SHUT,
        OPEN,
        DIE,
        COUNT
    };

    Boss2FinalData(std::vector < BulletSprite* >& bulletsVector = std::vector <BulletSprite* >());
    ~Boss2FinalData();

    Boss2FinalJoint* joints[5];
    float armLength;
    ArmSide armSide;
};

