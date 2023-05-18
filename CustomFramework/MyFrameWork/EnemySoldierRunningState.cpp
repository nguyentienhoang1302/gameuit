#include "EnemySoldierRunningState.h"
#include "EnemySoldierData.h"

EnemySoldierRunningState::EnemySoldierRunningState(EnemyData *pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = EnemySoldierData::RUN;
    this->pData->vx = 1.0f;
    this->pData->vy = 1.0f;
    acceleration = 1.5f;
    isFallDown = false;
    frameShot = rand() % 10 + 15;
}


EnemySoldierRunningState::~EnemySoldierRunningState()
{

}

void EnemySoldierRunningState::onUpdate()
{
    if (((EnemySoldierData*)pData)->isShooter)
    {
        if (frameShot >= 0)
        {
            frameShot--;
        }
        else
        {
            if (!((EnemySoldierData*)pData)->isShooted)
            {
                ((EnemySoldierData*)pData)->isShooted = true;
                transition(new EnemySoldierShootingState(this->pData));
                return;
            }
        }
    }

    if (!isFallDown)
        EnemyState::onUpdate();
    else
    {
        //luc nay enemy dang bi roi xuong
        this->pData->vy += acceleration;
    }

    if (pData->dir.isLeft())
    {
        pData->x -= pData->vx;
    }
    else if (pData->dir.isRight())
    {
        pData->x += pData->vx;
    }

    pData->y += pData->vy;

    if (pData->cSupportRect == CollisionRectF())
    {
        transition(new EnemySoldierFallingState(this->pData));
    }
}

//void EnemySoldierRunningState::onCollision(RectF rect)
//{
//
//}

void EnemySoldierRunningState::onCollision(CollisionRectF rect)
{
    float distanceLeft = this->pData->getBody().x - rect.rect.x;
    float distanceRight = this->pData->getBody().x - (rect.rect.x + rect.rect.width);

    if (distanceLeft <= SOLDIER_RANGE_TO_JUMP)
    {
        if (rand() % 3 != 0)
        {
            transition(new EnemySoldierJumpingState(pData));
            return;
        }            
        else
        {
            this->pData->dir = Direction::createRight();
        }
    }

    if (-distanceRight <= SOLDIER_RANGE_TO_JUMP)
    {
        this->pData->dir = Direction::createLeft();
    }

    //xac dinh vi tri va cham
    //lay tam cua vat collision
    D3DXVECTOR2 colcenter = D3DXVECTOR2(rect.rect.x + rect.rect.width / 2, rect.rect.y + rect.rect.height / 2);

    //lay tam cua enemy
    RectF enrect = this->pData->getBody();
    D3DXVECTOR2 encenter = D3DXVECTOR2(enrect.x + enrect.width / 2, enrect.y + enrect.height / 2);

    //tinh toan vector huong tu enemy toi vat collision tu do xac dinh side coliision
    D3DXVECTOR2 direction = encenter - colcenter;

    if (this->pData->vy > 0 && direction.y <= 0)
    {
        //va cham ben tren (enemy ben tren vat collision)
        this->pData->vy = 0;
    }
}
