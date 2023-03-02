#pragma once
#include <SFML/Graphics.hpp>
class Obstacol
{
public:
	Obstacol();
	const sf::FloatRect& getLowerBounds();
	const sf::FloatRect& getUpperBounds();
	//float getLowerBounds();//marginea de jos a obsSus
	//float getUpperBounds();//marginea de sus o obsJos
	void initObstacol();
	void miscaObstacol();
	void deseneazaObstacol(sf::RenderTarget *x);

const sf::FloatRect& getMargini();

private:
	sf::Sprite obsJos;
	sf::Sprite obsSus;
	sf::Texture textura;
};

