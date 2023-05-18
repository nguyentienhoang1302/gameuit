#include "EnemySoldierShootingState.h"

EnemySoldierShootingState::EnemySoldierShootingState(EnemyData *pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = EnemySoldierData::SHOT;
    
    frameDelayTransition = 30;
}


EnemySoldierShootingState::~EnemySoldierShootingState()
{

}

void EnemySoldierShootingState::onUpdate()
{
    if (pData->ppTextureArrays[pData->iCurrentArr]->isLastTexture())
    {
        if (frameDelayTransition >= 0)
        {
            frameDelayTransition--;

            if (frameDelayTransition == 10 || frameDelayTransition == 25)
            {
                if (pData->dir.isLeft())
                {
                    pData->bulletsVector.push_back(new EnemyWhiteBullet(pData->x - 17.0 / 2, pData->y - 25, true, D3DXToRadian(180)));
                }
                else
                {
                    pData->bulletsVector.push_back(new EnemyWhiteBullet(pData->x + 17.0 / 2, pData->y - 25, true, 0));
                }
            }
        }
        else
        {
            transition(new EnemySoldierRunningState(this->pData));
            return;
        }
    }
    else
    {
        EnemyState::onUpdate();
    }
}
