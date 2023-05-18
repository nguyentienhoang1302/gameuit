#include"EnemyGunRotatingClosingState.h"
#include"EnemyGunRotatingOpeningState.h"
EnemyGunRotatingClosingState::EnemyGunRotatingClosingState(EnemyData *pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = EnemyGunRotatingData::CLOSE;
	iFrame = 0;
}

EnemyGunRotatingClosingState::~EnemyGunRotatingClosingState()
{

}
void EnemyGunRotatingClosingState::onUpdate()		
{
	switch (this->pData->getPlayerIndexToExcute())
	{
	case 1:
		directPlayerX = this->pData->playerX;
		directPlayerY = this->pData->playerY;
		break;
	case 2:
		directPlayerX = this->pData->player2X;
		directPlayerY = this->pData->player2Y;
		break;
	default:
		break;
	}

	pData->ppTextureArrays[pData->iCurrentArr]->update();
	D3DXVECTOR2 currvec = D3DXVECTOR2(directPlayerX, directPlayerY) - D3DXVECTOR2(pData->x, pData->y);
	float distance = D3DXVec2Length(&currvec);

	if (distance < 120)
	{
		iFrame++;
		if (iFrame == 2)
			transition(new EnemyGunRotatingOpeningState(pData));
	}

	/*
	if (pData->stage == 1)
	{
		if (pData->x - directPlayerX < 95)
		{
			iFrame++;
			if (iFrame == 2)
				transition(new EnemyGunRotatingOpeningState(pData));
		}
	}


	else

	{
		if (directPlayerY - pData->y < 20)
		{
			iFrame++;
			if (iFrame == 2)
				transition(new EnemyGunRotatingOpeningState(pData));
		}

	}
	*/
}
