#include "DefaultPawn.h"
#include <iostream>

DefaultPawn::DefaultPawn()
{
	initPawn();
}

void DefaultPawn::initPawn()
{
	if (!textura.loadFromFile("Texturi/flappy.jpg"))
		std::cout << "eroare flappy texture\n";
	else
	{
		obiect.setTexture(textura);
		obiect.setPosition(150.f, 300.f);
		obiect.setScale(0.1f, 0.1f);
	}
}

void DefaultPawn::gravitate()
{
	obiect.move(0.f, 0.2f);
}

void DefaultPawn::updateJucator()
{
	obiect.move(0.f, -3.f);
}

void DefaultPawn::setPozitie(float x, float y)
{
	this->obiect.setPosition(x, y);
}

sf::Vector2f DefaultPawn::getPoz()
{	
	return sf::Vector2f(obiect.getPosition().x,obiect.getPosition().y);
}

void DefaultPawn::deseneazaJucator(sf::RenderTarget* fereastra)
{
	fereastra->draw(obiect);
}

const sf::FloatRect& DefaultPawn::getMargini()
{
	return obiect.getGlobalBounds();
}
