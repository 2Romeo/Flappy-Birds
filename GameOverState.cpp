#include "GameOverState.h"
#include <iostream>
GameOverState::GameOverState()
{
	initGameOState();
}

void GameOverState::initGameOState()
{
	background.setSize(sf::Vector2f(900.f, 700.f));
	background.setFillColor(sf::Color(25, 25, 25, 200));
	background.setPosition(0.f, 0.f);
	if (this->GameOverFont.loadFromFile("Font/LeagueSpartan-Bold.otf") == false)
		std::cout << "font error not loaded\n";
	else
	{
		GameOverText.setFont(GameOverFont);
		GameOverText.setCharacterSize(70);
		GameOverText.setFillColor(sf::Color::Red);
		GameOverText.setString("Game Over Romeo");
	}
}

void GameOverState::setTextPos(float x, float y)
{
	GameOverText.setPosition(x, y);
	
}

void GameOverState::deseneazaGmOvState(sf::RenderTarget* aux)
{
	aux->draw(background);
	aux->draw(GameOverText);
}

	