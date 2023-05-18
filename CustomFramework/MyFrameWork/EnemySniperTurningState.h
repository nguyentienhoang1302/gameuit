#pragma once

#include "EnemyState.h"
#include "EnemyData.h"
#include "EnemySniperStandingState.h"


class EnemySniperTurningState : public EnemyState
{
public:
	EnemySniperTurningState(EnemyData* pData);
	~EnemySniperTurningState();
	virtual void onUpdate();
	virtual void onDead();
private:
	int count;
	int nFiringDelayTime;
	int nHoldFrames;
	int listAngle[6];
	int getIndex();
	int iCurrent; // xac dinh sprite hien tai
	float fAngle; // xac dinh goc hien tai
	float getAngle();
	float getDistance();
	int temp;
	float directPlayerX, directPlayerY;
};