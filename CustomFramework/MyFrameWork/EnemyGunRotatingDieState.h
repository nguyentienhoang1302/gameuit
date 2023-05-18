#include"EnemyState.h"
#include"EnemyGunRotatingData.h"
#define PI 3.14

class EnemyGunRotatingDieState :public EnemyState
{
public:
	EnemyGunRotatingDieState(EnemyData *pData);
	~EnemyGunRotatingDieState();

	void onUpdate();
private:
	int iFrame;
};