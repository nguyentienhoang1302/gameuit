#include "EnemyBazokaExploringState.h"
#include "Sound.h"

EnemyBazokaExploringState::EnemyBazokaExploringState(EnemyData* data)
{
	pData = data;
	pData -> iCurrentArr = 2;
	pData -> isHittable = false;
	Sound :: getInstance() -> play( "enemydead.wav", false , 1);
}


EnemyBazokaExploringState::~EnemyBazokaExploringState(void)
{
}

void EnemyBazokaExploringState:: onUpdate()
{
	EnemyState::onUpdate();
	if(pData -> ppTextureArrays[ pData -> iCurrentArr] ->isLastTexture())
	{
		pData -> isDesTroyed = true;
	}
}