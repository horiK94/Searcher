#include "stdafx.h"
#include "StateController.h"

#include "Title.h"
#include "Game.h"
#include "Result.h"

void StateController::ChangeState(GameState state)
{
	if (currentState == state)
	{
		//変更なし
		return;
	}

	currentState = state;
	stateInstance[currentState]->Initialize();
}

void StateController::Update()
{
	stateInstance[currentState]->Update();
}

StateController::StateController()
{
	currentState = TITLE;

	stateInstance[TITLE] = new Title(this);
	stateInstance[GAME] = new Game(this);
	stateInstance[RESULT] = new Result(this);

	//最初だけ明示的に実行する
	stateInstance[currentState]->Initialize();
}

GameData& StateController::GetGameData()
{
	return gameData;
}
