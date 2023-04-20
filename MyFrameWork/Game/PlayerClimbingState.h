#pragma once

#include "PlayerState.h"

// trạng thái leo/trèo
class PlayerClimbingState : public PlayerState
{
public:
	PlayerClimbingState(PlayerData* data, bool isMoving = true);
	virtual void onUpdate();
	virtual void onVeticalDirectionPressed(Direction dir);
	virtual void onVeticalDirectionReleased();
	void onMovePressed(Direction d);
	void onMoveReleased(Direction d);
	virtual void onDead();
private:
	int count;
	int nHoldFrames;
	bool isMoving;

};