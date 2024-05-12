#pragma once
#include "StateController.h"

class StateController;

class State
{
protected:
	StateController* controller;
	virtual ~State() {};
public:
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	State(StateController* controller);
};

