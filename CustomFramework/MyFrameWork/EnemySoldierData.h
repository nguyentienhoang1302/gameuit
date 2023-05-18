#pragma once
#include "EnemyData.h"

const float SOLDIER_RANGE_TO_JUMP = 5.0f;
const float SOLDIER_RANGE_TO_TURN = 15.0f;

class EnemySoldierData : public EnemyData
{
public:
    EnemySoldierData(std::vector<BulletSprite*>& bullet = std::vector<BulletSprite*>());
    ~EnemySoldierData();

    enum SoldierArrayIndex
    {
        RUN,
        JUMP,
        SHOT,
        DIE,
        DESTROY,
        FALL,
        DROWNING,
        COUNT
    };

    bool isShooter;
    bool isShooted;
};

