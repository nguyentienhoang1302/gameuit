#pragma once

#include "PlayerState.h"

// trang thai leo/treo
class PlayerClimbingState : public PlayerState
{
public:
	PlayerClimbingState(PlayerData* data , bool isMoving = true);
	virtual void onUpdate();
	virtual void onVeticalDirectionPressed( Direction dir);
	virtual void onVeticalDirectionReleased();
	void onMovePressed(Direction d);
	void onMoveReleased(Direction d);
	virtual void onDead();
private:
	int count;
	int nHoldFrames;
	bool isMoving;
	
};