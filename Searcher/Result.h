#pragma once
#include "State.h"
#include "Siv3D.hpp"

class Result : public State
{
private:
	Font resultFont;
	Font detailFont;
	const float correntNumShowTime = 0.8f;
	const float wrongNumShowTime = 1.6f;
	const float scoreShowTime = 2.4f;

	float passedTime = 0;
	GameData gameData;

	const int32 CORRECT_POINT = 100;
	const int32 WRONG_POINT = -10;
	int32 resultPoint = 0;
public:
	void Initialize() override;
	void Update() override;
	Result(StateController* controller);
};
