#include "EnemySoldierDieState.h"


EnemySoldierDieState::EnemySoldierDieState(EnemyData *pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = EnemySoldierData::DIE;

    this->pData->vx = 0;
    this->pData->vy = -3.0f;
    this->pData->isHittable = false;
    this->pData->isThrougable = true;

    acceleration = 0.1f;
}


EnemySoldierDieState::~EnemySoldierDieState()
{
}

void EnemySoldierDieState::onUpdate()
{
    EnemyState::onUpdate();

    this->pData->y += this->pData->vy;
    this->pData->vy += acceleration;

    if (this->pData->vy >= 0)
    {
        //destroy: run animation destroy
        transition(new EnemySoldierDestroyState(this->pData));
    }
}
