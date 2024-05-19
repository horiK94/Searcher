#pragma once
#include "State.h"
#include "CharacterPutStyleBase.h"
#include "SquaresPut.h"

class Game : public State
{
private:
	int correctCount;
	int wrongCount;
	const float TIME_LIMIT = 60.0f;

	int questionTextIndex = 0;
	int correctIndex = 0;

	void decideScreenSize();
	void decideUseCharacter();
	void decidePutInfo();

	const std::vector<String> searchCharacters = {
		U"😦😲😯😧",
		U"🐫🐪🐆🐈🐕",
		U"😘😗😚😙",
	};
	const std::vector<std::vector<int>> characterSize = {
		{60, 60, 60, 60},
		{70, 70, 70, 70, 70},
		{60, 60, 60, 60},
	};
	const Vec2 screenSize[5] = {
	{300, 300},
	{200, 350},
	{300, 250},
	{200, 250},
	{260, 200},
	};

	std::vector<std::vector<Texture>> textureCacheList;

	std::vector<Vec2> texturePosList;
	std::vector<int> textureIndexList;
	Circle correctCircle;

	void createTexture();
	void setTheme();

	Size fullScreenSize = Size{0, 0};
public:
	Game(StateController* controller);
	void Initialize() override;
	void Update() override;
};
