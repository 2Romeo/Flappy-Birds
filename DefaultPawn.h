#pragma once
#include <SFML/Graphics.hpp>
class DefaultPawn
{
	private:
		sf::Texture textura;
		sf::Sprite obiect;
		float SpaceCooldown;
		float SpaceCooldownMax;
		

public:
	void updateCooldown();
	bool poateZbura();
	DefaultPawn();
	void initPawn();
	void gravitatie();
	void updateJucator();
	void setPozitie(float, float);
	sf::Vector2i getPoz();
	void deseneazaJucator(sf::RenderTarget*);
	const sf::FloatRect& getMargini();


};

