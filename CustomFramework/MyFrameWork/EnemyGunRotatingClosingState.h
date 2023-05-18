#include"EnemyState.h"
#include"EnemyGunRotatingData.h"

class EnemyGunRotatingClosingState :public EnemyState
{
public:
	EnemyGunRotatingClosingState(EnemyData *pData);
	~EnemyGunRotatingClosingState();

	void onUpdate();
private:
	int iFrame;
	float directPlayerX, directPlayerY;
};