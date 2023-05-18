#include"EnemyState.h"

class EnemyScubarSoliderHidingState : public EnemyState
{
public:
	EnemyScubarSoliderHidingState(EnemyData *pData, bool isFirst = false);
	~EnemyScubarSoliderHidingState();
	void onUpdate();
	virtual void onDead();
private:
	int iFrame;
	bool isFirst;
	float directPlayerY;
};