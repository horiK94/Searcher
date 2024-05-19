#pragma once
#include "CharacterPutStyleBase.h"

class SquaresPut :
	public CharacterPutStyleBase
{
private:
	int dummyCount = 0;
	Point purCount;
public:
	SquaresPut(Size fullScreenSize, String character, int purposeIndex, int dummyCount, Point purCount);
	std::vector<Vec2> CreatePosition();
};

