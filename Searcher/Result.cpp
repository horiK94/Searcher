#include "stdafx.h"
#include "Result.h"

Result::Result(StateController* controller) : State(controller)
{
}

void Result::Initialize()
{
	resultFont = Font{ 50 };
	detailFont = Font{ 30 };

	Window::SetStyle(WindowStyle::Sizable);
	Window::ResizeVirtual(600, 600);

	gameData = controller->GetGameData();
	resultPoint = gameData.CorrectCount * CORRECT_POINT + gameData.WrongCount * WRONG_POINT;
	std::to_string(resultPoint);
}

void Result::Update()
{
	passedTime += Scene::DeltaTime();

	resultFont(U"Result").drawAt(300, 100);

	if (passedTime >= correntNumShowTime)
	{
		detailFont(U"正解数: {0}"_fmt(gameData.CorrectCount)).drawAt(300, 340);
	}

	if(passedTime >= wrongNumShowTime)
	{
		detailFont(U"不正解数: {0}"_fmt(gameData.WrongCount)).drawAt(300, 400);
	}

	if (passedTime >= scoreShowTime)
	{
		resultFont(U"Point: {0}"_fmt(resultPoint)).drawAt(300, 500);
	}
}
