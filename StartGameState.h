#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class StartGameState
{
private:
	sf::RectangleShape background;
	sf::Sprite buton;
	sf::Texture textura; 

public:
	sf::FloatRect getMargini();
	sf::FloatRect getMarginiBackground();
	StartGameState();
	StartGameState(sf::RenderWindow* aux);
	void initStartGame();
	void setSpritePos(float, float);
	void deseneazaSGmState(sf::RenderTarget* aux);
};

