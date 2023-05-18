#pragma once
#include "EnemyState.h"
#include "EnemyData.h"
#include "EnemyWhiteBullet.h"
#include "EnemyCannonDeadState.h"
#include "EnemyCannonData.h"
#include "MBullet.h"

class EnemyCannonTurningState : public EnemyState
{
public:
	EnemyCannonTurningState(EnemyData* pData);
	~EnemyCannonTurningState();
	void getIndex();
	virtual void onUpdate();
	virtual void onDead();
private:
	int count;
	int nShootCycle;
	float tanalpha; //goc ban
	float angle;
	float bulletX;
	float bulletY;
	float directPlayerX;
	float directPlayerY;
};

