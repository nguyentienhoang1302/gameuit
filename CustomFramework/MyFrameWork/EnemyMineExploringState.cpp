#include "EnemyMineExploringState.h"
#include "EnemyMineFallingState.h"
#include "Sound.h"
EnemyMineExploringState::EnemyMineExploringState(EnemyData* data)
{
	this -> pData = data;
	pData -> iCurrentArr = 1;
	Sound::getInstance() -> play("fallingmine", false , 1);	
}


EnemyMineExploringState::~EnemyMineExploringState(void)
{
}

void EnemyMineExploringState::onUpdate()
{
	EnemyState :: onUpdate();
	if(pData -> ppTextureArrays[pData -> iCurrentArr ] -> isLastTexture())
	{
		transition(new EnemyMineFallingState(pData));
	}
}
