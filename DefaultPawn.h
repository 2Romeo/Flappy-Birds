#pragma once
#include <SFML/Graphics.hpp>
class DefaultPawn
{
	private:
		sf::Texture textura;
		sf::Sprite obiect;

public:
	DefaultPawn();
	void initPawn();
	void gravitate();
	void updateJucator();
	void setPozitie(float, float);
	sf::Vector2f getPoz();
	void deseneazaJucator(sf::RenderTarget*);
	const sf::FloatRect& getMargini();


};

