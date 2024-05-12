#pragma once
#include "CharacterPutStyleBase.h"

class SquaresPut :
	public CharacterPutStyleBase
{
private:
	int dummyCount = 0;
	Point purCount;
public:
	SquaresPut(String charcter, int _purposeIndex, int dummy, Point purCount);
	std::vector<Vec2> DecidePosition();
};

