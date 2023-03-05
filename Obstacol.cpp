#include "Obstacol.h"
#include <iostream>
Obstacol::Obstacol()
{
	initObstacol();
}
const sf::FloatRect& Obstacol::getLowerBounds()
{
	return obsJos.getGlobalBounds();
}

const sf::FloatRect& Obstacol::getUpperBounds()
{
	return obsSus.getGlobalBounds();
}


void Obstacol::initObstacol()
{
	
	
	if (!textura.loadFromFile("Texturi/cilindruJos.png"))
		std::cout << "eroare load file\n";
	else
	{
		obsJos.setTexture(textura);
		obsJos.setScale(0.2f, 0.5f);
		obsJos.setPosition(900.f, rand()%(600-300+1)+300);
		obsSus = obsJos;
		textura1.loadFromFile("Texturi/cilindruSus.png");
		obsSus.setTexture(textura1);
		obsSus.setPosition(obsSus.getPosition().x, obsSus.getPosition().y - 200.f- obsSus.getGlobalBounds().height);
		
	}
}
void Obstacol::miscaObstacol()
{
	obsSus.move(-1.f,0.f);
	obsJos.move(-1.f, 0.f);
}

void Obstacol::deseneazaObstacol(sf::RenderTarget *x)
{
	x->draw(obsSus);
	x->draw(obsJos);
}
