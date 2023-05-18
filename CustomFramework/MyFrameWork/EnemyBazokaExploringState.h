#pragma once
#include "EnemyState.h"
class EnemyBazokaExploringState : public EnemyState
{
public:
	EnemyBazokaExploringState(EnemyData* data);
	~EnemyBazokaExploringState(void);
	virtual void onUpdate();
};

