#include"EnemyState.h"
#include"EnemyTankData.h"

class EnemyTankStartingState :public EnemyState
{
public:
	EnemyTankStartingState(EnemyData *pData, int s);
	~EnemyTankStartingState();

	void onUpdate();

private:
	int iFrames;
	int s, s0; // quang duong di duoc
	void getSprite();

};