#include "DefaultPawn.h"
#include <iostream>

void DefaultPawn::updateCooldown()
{
	if (SpaceCooldown < SpaceCooldownMax)//daca am asteptat sub sau egal timpul de asteptare creste
		SpaceCooldown += 0.3f;
}

bool DefaultPawn::poateZbura()
{
	if (SpaceCooldown >= SpaceCooldownMax)//daca am asteptat destul pana sa facem din nou click
	{
		SpaceCooldown = 0.f;
		return true;
	}
	return false;
}

DefaultPawn::DefaultPawn()
{
	SpaceCooldown = 10.f;
	SpaceCooldownMax = 10.f;
	initPawn();
}

void DefaultPawn::initPawn()
{
	if (!textura.loadFromFile("Texturi/flappy.png"))
		std::cout << "eroare flappy texture\n";
	else
	{
		obiect.setTexture(textura);
		obiect.setPosition(150.f, 300.f);
		obiect.setScale(0.1f, 0.1f);
	}
}

void DefaultPawn::gravitatie()
{
	obiect.move(0.f, 1.f);
//	obiect.setRotation(0);
}

void DefaultPawn::updateJucator()
{

//	obiect.setRotation(-45);
	obiect.move(0.f, -120.f);

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
