#include "stdafx.h"
#include "Game.h"
#include <Siv3D.hpp>
#include <vector>

void Game::decideScreenSize()
{
	const Vec2 screenSize[5] = {
		{200, 200},
		{150, 250},
		{200, 150},
		{150, 150},
		{160, 100},
	};

	int decideSizeIndex = sizeof(screenSize) / sizeof(screenSize[0]) * Random();
	Window::ResizeVirtual(screenSize[decideSizeIndex].x, screenSize[decideSizeIndex].y);
}

void Game::decideCharacter()
{
	questionTextIndex = Random() * searchCharacters.size();
	correctIndex = Random() * searchCharacters[questionTextIndex].size();
}

void Game::setTheme()
{
	decideScreenSize();

	decideCharacter();

}

Game::Game(StateController* ctr)
{
	controller = ctr;
}

void Game::Intialize()
{
	Window::SetStyle(WindowStyle::Fixed);
	setTheme();
}

void Game::Update()
{

}
