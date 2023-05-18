#include "Boss2FinalHeadShuttingState.h"


Boss2FinalHeadShuttingState::Boss2FinalHeadShuttingState(EnemyData *pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = Boss2FinalData::ArrayIndex::SHUT;
    frameCountOpen = 265;
    isStartChange = false;
}

Boss2FinalHeadShuttingState::~Boss2FinalHeadShuttingState()
{
}

void Boss2FinalHeadShuttingState::onUpdate()
{
    EnemyState::onUpdate();

    if (frameCountOpen >= 0)
    {
        frameCountOpen--;
    }
    else
    {
        transition(new Boss2FinalHeadOpeningState(this->pData));
        return;
    }
}


