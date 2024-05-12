#include "stdafx.h"
#include "SquaresPut.h"
#include "Siv3D.hpp"
#include <set>

SquaresPut::SquaresPut(String character, int purposeIndex, int dummyCount, Point purCount) : CharacterPutStyleBase::CharacterPutStyleBase(character, purposeIndex)
, dummyCount(dummyCount), purCount(purCount)
{
}

std::vector<Vec2> SquaresPut::DecidePosition()
{
	std::vector<std::vector<bool>> isPut;
	for (int y = 0; y < purCount.y; y++)
	{
		std::vector<bool> tmpVector;
		for (int x = 0; x < purCount.x; x++)
		{
			tmpVector.push_back(false);
		}
		isPut.push_back(tmpVector);
	}

	std::vector<std::pair<int, int>> rand;
	for (int i = 0; i < purCount.x * purCount.y; i++)
	{
		rand.push_back(std::make_pair(i, Random()));
	}

	sort(rand.begin(), rand.end(), [](std::pair<int, int> a, std::pair<int, int> b)
		{
			return a.second < b.second;
		});

	//正しい位置の決定
	Point correctPoint = Point{ rand[0].first % purCount.x, rand[0].first / purCount.x };

	//ダミーの位置決定
	std::vector<Point> putPoint;
	putPoint.push_back(correctPoint);
	for (int i = 1; i < std::min(purCount.x * purCount.y, dummyCount); i++)
	{
		putPoint.push_back(Point{ rand[i].first % purCount.x, rand[i].first / purCount.x });
	}

	Vec2 screenSize = Scene::Size();
	//端っこに置かないように(purCount.x + 1, purCount.y + 1)個で分割する
	Vec2 durationSize = screenSize / Vec2{ purCount.x + 1 , purCount.y + 1 };

	std::vector<Vec2> putPosition;
	for (int i = 1; i < putPoint.size(); i++)
	{
		putPosition.push_back(putPoint[i] * durationSize);
	}
	return putPosition;
}
