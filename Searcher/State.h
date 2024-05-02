#pragma once
#include "StateController.h"

class StateController;

class State
{
protected:
	StateController* controller;
public:
	virtual void Intialize() {};
	virtual void Update() {};
};

