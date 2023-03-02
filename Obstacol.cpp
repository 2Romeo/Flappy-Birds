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
	//ObsSus.setPosition(ObsSus.getGlobalBounds().left, ObsSus.getGlobalBounds().left + ObsSus.getGlobalBounds().width);

	
	if (!textura.loadFromFile("Texturi/cilindru.png"))
		std::cout << "eroare load file\n";
	else
	{
		obsJos.setTexture(textura);
		obsJos.setScale(0.2f, 0.5f);
		obsJos.setPosition(900.f, rand()%600);

		obsSus = obsJos;
		obsSus.setPosition(obsSus.getPosition().x, obsSus.getPosition().y - 200.f- obsSus.getGlobalBounds().height);
		
	}
}
void Obstacol::miscaObstacol()
{
	obsSus.move(-2.f,0.f);
	obsJos.move(-2.f, 0.f);
}

void Obstacol::deseneazaObstacol(sf::RenderTarget *x)
{
	x->draw(obsSus);
	x->draw(obsJos);
}

//sf::FloatRect Obstacol::getMargini()
//{
//	return obsJos.getGlobalBounds();//noi frem doar partea din stanga a obiectului
//									// deci nu avem nevoi si de marginile obsJos deoarece le despawnam pe ambele can obsSus iese din consola
//}
