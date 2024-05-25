﻿#include "stdafx.h"
#include "Game.h"
#include <Siv3D.hpp>
#include <vector>

void Game::decideScreenSize()
{
	int decideSizeIndex = sizeof(screenSize) / sizeof(screenSize[0]) * Random();
	Window::ResizeVirtual(screenSize[decideSizeIndex].x, screenSize[decideSizeIndex].y);
}

void Game::decideUseCharacter()
{
	questionTextIndex = Random() * searchCharacters.size();
	correctIndex = Random() * searchCharacters[questionTextIndex].size();
}

void Game::decidePutInfo()
{
	CharacterPutStyleBase* putStyle = new SquaresPut(fullScreenSize, searchCharacters[questionTextIndex], correctIndex, 5, Point{ 3, 3 });
	texturePosList = putStyle->CreatePosition();		//0番目の要素が正解の位置

	//正解のボタンのサイズを設定
	correctCircle = Circle{ texturePosList[0], characterSize[questionTextIndex][correctIndex] };

	//表示する画像を決定
	textureIndexList = std::vector<int>(texturePosList.size());
	textureIndexList[0] = correctIndex;
	for (int i = 1; i < searchCharacters.size(); i++)
	{
		int dummyIndex = Random() * (searchCharacters[questionTextIndex].size() - 1);
		if(dummyIndex >= correctIndex)
		{
			dummyIndex++;
		}
		textureIndexList[i] = dummyIndex;
	}
}

void Game::setTheme()
{
	decideScreenSize();
	decideUseCharacter();
	decidePutInfo();
}

Game::Game(StateController* ctr) : State::State(ctr)
{
}

void Game::createTexture()
{
	for (int i = 0; i < searchCharacters.size(); ++i)
	{
		std::vector<Texture> textureList;

		String str = searchCharacters[i];
		for (int j = 0; j < str.size(); ++j)
		{
			String character = String{ str[j] };
			Emoji emoji{ character };

			Texture tex{ emoji };
			textureList.push_back(tex);
		}

		textureCacheList.push_back(textureList);
	}
}

void Game::Initialize()
{
	Window::SetStyle(WindowStyle::Fixed);
	Window::SetToggleFullscreenEnabled(false);		//フルスクリーン切り替えを無効にする

	MonitorInfo programWindow = System::EnumerateMonitors()[System::GetCurrentMonitorIndex()];
	fullScreenSize = programWindow.fullscreenResolution;

	createTexture();
	setTheme();
}

void Game::Update()
{
	Vec2 screenPos = Window::GetPos();

	for (int i = 0; i < texturePosList.size(); ++i)
	{
		Vec2 texturePos = texturePosList[i] - screenPos;

		textureCacheList[questionTextIndex][textureIndexList[i]].drawAt(texturePos);
	}

	correctCircle.setPos(texturePosList[0]);
	if (MouseL.down())
	{
		Vec2 mousePos = Cursor::Pos();
		if (mousePos.x < 0 || mousePos.x > fullScreenSize.x
			|| mousePos.y < 0 || mousePos.y > fullScreenSize.y)
		{
			return;
		}

		if (correctCircle.leftClicked())
		{
			setTheme();
		}
		else
		{
			Print << U"間違い";
		}
	}
}
