#pragma once
#include "State.h"
#include <map>

class State;

class StateController
{
public:
	enum GameState
	{
		TITLE,
		GAME,
	};
	void ChangeState(GameState state);
	void Update();
	StateController();
private:
	GameState currentState;
	std::map<GameState, State*> stateInstance;
};

