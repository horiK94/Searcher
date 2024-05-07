#pragma once
#include "State.h"

class Title : public State
{
private:
	const Font titleFont{ FontMethod::MSDF, 48, Typeface::Bold };
	const Font toGameFont{ FontMethod::MSDF, 30 };
	const String titleText = U"ウィンドウ宝探し";
	const String toGameText = U"クリックでゲーム開始";
	const float moveDelay = 5;
	const float fallDuration = 0.2f;
	const float fallTime = 0.4f;
	Vec2 textMoveVec[8];
	float passedTime = 0;

	void moveTitleWord(int index, float curentTime);
	void showClickToGameText(float curentTime);
public:
	void Intialize();
	void Update();
	Title(StateController* controller);
};

