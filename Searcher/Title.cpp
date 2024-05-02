#include "stdafx.h"
#include "Title.h"
#include <Siv3D.hpp>

void Title::Intialize()
{
	Window::SetStyle(WindowStyle::Sizable);
	Window::ResizeVirtual(600, 600);

	for (int i = 0; i < text.size(); i++)
	{
		textMoveVec[i] = RandomVec2();
	}

	passedTime = 0;
}

void moveTitleWord(int index, String text, Font font, float curentTime, float fallDuration, float fallTime, float moveDelay, Vec2 moveDir);

void Title::Update()
{
	ClearPrint();
	Print << Cursor::Pos();

	for (unsigned long long i = 0; i < text.size(); i++)
	{
		moveTitleWord(i, text.values_at({ i }), font, passedTime, fallDuration, fallTime, moveDelay, textMoveVec[i]);
	}

	if (MouseL.down())
	{
		controller->ChangeState(StateController::GAME);
	}

	passedTime += Scene::DeltaTime();
}

Title::Title(StateController* ctr)
{
	controller = ctr;
}

void moveTitleWord(int index, String text, Font font, float curentTime, float fallDuration, float fallTime, float moveDelay, Vec2 moveDir)
{
	float fallStart = index * fallDuration;
	assert(fallStart + fallTime < moveDelay);

	Vec2 centerPos = { 120, 100 };
	centerPos += index * Vec2{ 50, 0 };
	if (curentTime < fallStart)
	{
		//移動時刻前. 表示しない
		return;
	}

	if (curentTime > moveDelay)
	{
		const float moveSpeed = 40;

		//散らばり中
		centerPos += (curentTime - moveDelay) * moveSpeed * moveDir;
		font(text).drawAt(centerPos);
		return;
	}

	float fallPassedTime = curentTime - fallStart;
	if (fallPassedTime >= fallTime)
	{
		//落下終了後、散らばり待ち
		font(text).drawAt(centerPos);
		return;
	}

	//落下中
	font(text).drawAt(centerPos - 20 * fallPassedTime / fallTime * Vec2{ 0, 1 });
}
