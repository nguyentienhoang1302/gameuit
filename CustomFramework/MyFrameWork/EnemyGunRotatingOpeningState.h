#include"EnemyState.h"
#include"EnemyGunRotatingData.h"

class EnemyGunRotatingOpeningState :public EnemyState
{
public:
	EnemyGunRotatingOpeningState(EnemyData *pData);
	~EnemyGunRotatingOpeningState();

	void onUpdate();
private:
	int iFrame;
};