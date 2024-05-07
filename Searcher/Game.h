#pragma once
#include "State.h"

class Game : public State
{
private:
	int correctCount;
	int wrongCount;
	const float TIME_LIMIT = 60.0f;

	int questionTextIndex = 0;
	int correctIndex = 0;

	void decideScreenSize();
	void decideCharacter();

	const std::vector<String> searchCharacters = {
	U"😦😲😯😧",
	U"🐫🐪🐆🐈🐕",
	U"😘😗😚😙",
	};

	void setTheme();
public:
	Game(StateController* controller);
	void Intialize();
	void Update();
};

