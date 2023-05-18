#include "EnemySoldierDrowningState.h"


EnemySoldierDrowningState::EnemySoldierDrowningState(EnemyData *pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = EnemySoldierData::DROWNING;
}


EnemySoldierDrowningState::~EnemySoldierDrowningState()
{
}

void EnemySoldierDrowningState::onUpdate()
{
    EnemyState::onUpdate();

    if (this->pData->ppTextureArrays[EnemySoldierData::DROWNING]->isLastTexture())
    {
        this->pData->isDesTroyed = true;
    }
}