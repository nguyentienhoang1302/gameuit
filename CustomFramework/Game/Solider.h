#pragma once
#include"Enemy.h"

class Solider : public Enemy
{
private:
	Rect curGroundBound;

public:
	bool isOnGround;
	float activeDistance;
	Solider();
	void DetectCurGround(std::unordered_set<Rect*> grounds);
	void UpdateDistance(float dt);
	void ChangeState(State StateName);
};