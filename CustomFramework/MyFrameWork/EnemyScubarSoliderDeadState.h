#pragma once
#include"EnemyState.h"
class EnemyScubarSoliderDeadState : public EnemyState
{
public:
	EnemyScubarSoliderDeadState(EnemyData *pData);
	~EnemyScubarSoliderDeadState();
	void onUpdate();

private:
	int iFrames;
};

