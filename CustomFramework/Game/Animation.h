#pragma once
#include "Sprite.h"
#include "SpriteFactory.h"
#include <vector>
#include <map>

class Animation
{
private:
	int totalFrames;						// Tổng số Frame ( size_of Sprites tạo nên Animation )
	int timePerFrame;						// Thời gian tồn tại mỗi frame trước khi chuyển
	int curFrameTime;						// Thời gian hiện tại của Frame đang xét
	std::vector<Sprite*> sprites;			// Các Sprite (Frame) để tạo nên Animation

public:
	Animation() {};
	~Animation();
	Animation(Tag tag, int index);
	Animation(Tag tag, int firstIndex, int lastIndex, int timePerFrame = DEFAULT_TPF);			
	void Render(float x, float y, float translateX = 0, float translateY = 0);
	void Update(float dt);

	int CurFrameIndex;						// Sprite (Frame) hiện tại đang dùng default 0
	bool isLastFrame;						// Sprite (Frame) cuối cùng
	bool isReverse;							// Lật sprite
	Sprite* GetSprite(int index);
};