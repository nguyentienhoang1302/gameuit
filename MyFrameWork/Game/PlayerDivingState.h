#pragma once
#include "PlayerState.h"


// trạng thái lặn
class PlayerDivingState : public PlayerState
{
public:
	~PlayerDivingState() {}
	PlayerDivingState(PlayerData* data);

	void onMovePressed(Direction d);
	void onUpdate();
	void onVeticalDirectionPressed(Direction d);
	void onVeticalDirectionReleased();
	void onFirePressed();
	virtual void onDead();

};