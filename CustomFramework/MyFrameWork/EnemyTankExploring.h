#include"EnemyState.h"

class EnemyTankExploring : public EnemyState
{
public: 
	EnemyTankExploring(EnemyData *pData, int index);
	~EnemyTankExploring();

	void onUpdate();
private:
	int index;
};