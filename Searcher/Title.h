#pragma once
#include "State.h"

class Title : public State
{
private:
	const Font font{ FontMethod::MSDF, 48, Typeface::Bold };
	const String text = U"ウィンドウ宝探し";
	const float moveDelay = 5;
	const float fallDuration = 0.2f;
	const float fallTime = 0.4f;
	Vec2 textMoveVec[8];
	float passedTime = 0;
public:
	void Intialize();
	void Update();
	Title(StateController* controller);
};

