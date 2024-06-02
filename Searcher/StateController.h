#pragma once
#include "State.h"
#include <map>

class State;

struct GameData
{
	int32 CorrectCount = 0;
	int32 WrongCount = 0;
	int32 Score = 0;
};

class StateController
{
public:
	enum GameState
	{
		TITLE,
		GAME,
		RESULT,
	};
	void ChangeState(GameState state);
	void Update();
	StateController();
	GameData& GetGameData();
private:
	GameState currentState;
	std::map<GameState, State*> stateInstance;
	GameData gameData;
};

