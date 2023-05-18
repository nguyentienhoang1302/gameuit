#include "EnemySoldierFallingState.h"


EnemySoldierFallingState::EnemySoldierFallingState(EnemyData *pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = EnemySoldierData::FALL;
    acceleration = 0.1f;
    this->pData->vx = 0;
    this->pData->vy = 1.3f;
}


EnemySoldierFallingState::~EnemySoldierFallingState()
{
}

void EnemySoldierFallingState::onUpdate()
{
    EnemyState::onUpdate();

    this->pData->y += this->pData->vy;
    this->pData->vy += acceleration;

    if (!(this->pData->cSupportRect == CollisionRectF()))
    {
        transition(new EnemySoldierRunningState(this->pData));
    }
}

void EnemySoldierFallingState::onCollision(CollisionRectF rect)
{
    if (rect.type == "water")
    {
        transition(new EnemySoldierDrowningState(this->pData));
    }
}