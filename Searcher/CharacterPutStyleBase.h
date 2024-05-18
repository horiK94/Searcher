#pragma once
class CharacterPutStyleBase
{
protected:
	String character;
	int purposeIndex;
	virtual ~CharacterPutStyleBase(){};
public:
	enum ePutStyle
	{
		SquaresPut,
	};

	CharacterPutStyleBase(String charcter, int _purposeIndex);
	virtual std::vector<Vec2> CreatePosition() = 0;
};

