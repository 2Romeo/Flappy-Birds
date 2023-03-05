#include "StartGameState.h"

sf::FloatRect StartGameState::getMargini()
{
	return buton.getGlobalBounds();
}

sf::FloatRect StartGameState::getMarginiBackground()
{
	return background.getGlobalBounds();
}

StartGameState::StartGameState()
{
	initStartGame();
}

StartGameState::StartGameState(sf::RenderWindow* aux)
{
	initStartGame();
	deseneazaSGmState(aux);
}

void StartGameState::initStartGame()
{
	buton.setPosition(0.f, 0.f);
	buton.setScale(0.2f, 0.2f);
	if (this->textura.loadFromFile("Texturi/buton.png") == false)
		std::cout << "font error not loaded\n";
	else
		buton.setTexture(textura);
	
	background.setSize(sf::Vector2f(900.f, 700.f));
	background.setScale(2.f, 2.f);
	background.setFillColor(sf::Color(25, 25, 25, 200));
	background.setPosition(0.f, 0.f);
}

void StartGameState::setSpritePos(float x, float y)
{
	buton.setPosition(x, y);
}

void StartGameState::deseneazaSGmState(sf::RenderTarget* aux)
{
	aux->draw(background);
	aux->draw(buton);
}
