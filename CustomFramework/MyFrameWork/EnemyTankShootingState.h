#include"EnemyState.h"
#define PI 3.14

class EnemyTankShootingState : public EnemyState
{
public:
	EnemyTankShootingState(EnemyData *pData, int index);
	~EnemyTankShootingState();
	void onUpdate();

private:
	int iFrames;
	int index;
	int count;
	int iLastIndex;
	void Shoot();
	void getSprite();
	float directPlayerX, directPlayerY;
};