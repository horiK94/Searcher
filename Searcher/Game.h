#pragma once
#include "State.h"

class Game : public State
{
public:
	Game(StateController* controller);
	void Intialize();
	void Update();
};

