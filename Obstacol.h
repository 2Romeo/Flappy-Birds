#pragma once
#include <SFML/Graphics.hpp>
class Obstacol
{
public:
	Obstacol();
	const sf::FloatRect& getLowerBounds();
	const sf::FloatRect& getUpperBounds();
	void initObstacol();
	void miscaObstacol();
	void deseneazaObstacol(sf::RenderTarget *x);

private:
	sf::Sprite obsJos;
	sf::Sprite obsSus;
	sf::Texture textura;
	sf::Texture textura1;
};

