#include "stdafx.h"
#include "StateController.h"

#include "Title.h"
#include "Game.h"

void StateController::ChangeState(GameState state)
{
	if (currentState == state)
	{
		//変更なし
		return;
	}

	currentState = state;
	stateInstance[currentState]->Intialize();
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

	//最初だけ明示的に実行する
	stateInstance[currentState]->Intialize();
}
