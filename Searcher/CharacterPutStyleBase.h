#pragma once
class CharacterPutStyleBase
{
protected:
	String character;
	int purposeIndex;
	Size fullScreenSize;
	virtual ~CharacterPutStyleBase(){};
public:
	enum ePutStyle
	{
		SquaresPut,
	};

	CharacterPutStyleBase(Size fullScreenSize, String charcter, int _purposeIndex);
	virtual std::vector<Vec2> CreatePosition() = 0;
};

