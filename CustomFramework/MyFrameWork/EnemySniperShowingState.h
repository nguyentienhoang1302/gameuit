#pragma once
#include "EnemyState.h"
#include "EnemyData.h"
#include "EnemySniperHidingState.h"
#include "EnemyWhiteBullet.h"

class EnemySniperShowingState : public EnemyState
{
public:
    EnemySniperShowingState(EnemyData* data);
    ~EnemySniperShowingState();
	virtual void onDead();

    virtual void onUpdate();

private:
    int frameToShot;
    int shotCount;
};

