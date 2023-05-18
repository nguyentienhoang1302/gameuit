#include"EnemyState.h"

class EnemyScubarSoliderShootState : public EnemyState
{
public:
	EnemyScubarSoliderShootState(EnemyData *pData);
	~EnemyScubarSoliderShootState();
	void onUpdate();
	virtual void onDead();

private:
	int iFrames;
	bool flag;
};