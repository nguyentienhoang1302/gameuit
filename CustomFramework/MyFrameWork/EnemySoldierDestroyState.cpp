#include "EnemySoldierDestroyState.h"


EnemySoldierDestroyState::EnemySoldierDestroyState(EnemyData *pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = EnemySoldierData::DESTROY;
}

EnemySoldierDestroyState::~EnemySoldierDestroyState()
{

}

void EnemySoldierDestroyState::onUpdate()
{
    if (this->pData->isDesTroyed)
        return;

    if (this->pData->ppTextureArrays[EnemySoldierData::DESTROY]->isLastTexture())
    {
        this->pData->isDesTroyed = true;
    }
        

    EnemyState::onUpdate();
}
