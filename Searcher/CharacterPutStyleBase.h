#pragma once
class CharacterPutStyleBase
{
protected:
	String character;
	int purposeIndex;
public:
	CharacterPutStyleBase(String charcter, int _purposeIndex);
	virtual std::vector<Vec2> DecidePosition() = 0;
};

