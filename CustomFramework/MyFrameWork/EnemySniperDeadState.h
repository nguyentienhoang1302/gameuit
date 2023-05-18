#pragma once
#include "EnemyState.h"


class EnemySniperDeadState : public EnemyState
{
public:
	EnemySniperDeadState(EnemyData* data);
	~EnemySniperDeadState(void);

	virtual void onUpdate();
private:
	float acc;
};