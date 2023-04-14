#ifndef __TEXT_BITMAP_H__
#define __TEXT_BITMAP_H__

#include "../Const.h"
#include "Sprite.h"

US_FRAMEWORK

class TextBitmap
{
public:
	TextBitmap();
	~TextBitmap();

private:
	Sprite* _bitmapFile;
};

#endif // !__TEXT_BITMAP_H__
