#pragma once
#include <SFML/Graphics.hpp>
class GameOverState
{
private:
	sf::RectangleShape background;
	sf::Text GameOverText;
	sf::Font GameOverFont;
	sf::Texture textura;
public:
	GameOverState();
	void initGameOState();
	void setTextPos(float, float);
	void deseneazaGmOvState(sf::RenderTarget* aux);
};
