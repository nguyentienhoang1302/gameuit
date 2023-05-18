#include "EnemySoldierJumpingState.h"


EnemySoldierJumpingState::EnemySoldierJumpingState(EnemyData *pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = EnemySoldierData::JUMP;
    acceleration = 0.2f;
    pData->vy = -4.2f;
    pData->vx = 1.0f;
}


EnemySoldierJumpingState::~EnemySoldierJumpingState()
{

}


void EnemySoldierJumpingState::onUpdate()
{
    EnemyState::onUpdate();

    if (pData->dir.isLeft())
    {
        pData->x -= pData->vx;
    }
    else if (pData->dir.isRight())
    {
        pData->x += pData->vx;
    }

    pData->y += pData->vy;
    pData->vy += acceleration;
}

void EnemySoldierJumpingState::onCollision(RectF rect)
{

}

void EnemySoldierJumpingState::onCollision(CollisionRectF rect)
{
    if (rect.type == "water")
    {
        transition(new EnemySoldierDrowningState(this->pData));
        return;
    }

    if (pData->vy > 0)
    {
        if (this->pData->y - rect.rect.y <= 10)
        {
            transition(new EnemySoldierRunningState(pData));
        }        
    }
}

//void EnemySoldierJumpingState::onCameraCollision(RectF camera)
//{
//    if (this->pData->y >= (camera.y + camera.height))
//    {
//        this->pData->isDesTroyed = true;
//    }
//}