#include"EnemyScubarSoliderShootState.h"
#include"BulletScubarSoliderSprite.h"
#include"EnemyScubarSoliderData.h"
#include"EnemyScubarSoliderHidingState.h"
#include"EnemyScubarSoliderDeadState.h"

EnemyScubarSoliderShootState::EnemyScubarSoliderShootState(EnemyData *pData)
{
	this->pData = pData;
	iFrames = 0;
	pData->iCurrentArr = 1;
	flag = false;
	pData->isHittable = true;
}

EnemyScubarSoliderShootState::~EnemyScubarSoliderShootState()
{

}

void EnemyScubarSoliderShootState::onUpdate()
{

	pData->ppTextureArrays[pData->iCurrentArr]->update();
	iFrames++;

	if (iFrames == 20)
	{

		pData->bulletsVector.push_back(new BulletScubarSoliderSprite(pData->x + pData->body.width / 3, pData->y - pData->body.height * 3 / 4, 0, 0, pData->stage));
		pData->bulletsVector.push_back(new BulletScubarSoliderSprite(pData->x + pData->body.width / 3, pData->y - pData->body.height * 3 / 4, 3, 0.08, pData->stage));
		pData->bulletsVector.push_back(new BulletScubarSoliderSprite(pData->x + pData->body.width / 3, pData->y - pData->body.height * 3 / 4, 1, -0.08, pData->stage));
		pData->bulletsVector.push_back(new BulletScubarSoliderSprite(pData->x + pData->body.width / 3, pData->y - pData->body.height * 3 / 4, 2, 0, pData->stage));

		transition(new EnemyScubarSoliderHidingState(pData, true));
	}
}

void EnemyScubarSoliderShootState::onDead()
{
	transition(new EnemyScubarSoliderDeadState(pData));
}