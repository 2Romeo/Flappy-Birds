#include "FlappyBirds.h"
#include <SFML/Graphics.hpp>

FlappyBirds::FlappyBirds()
{	
	initGUI();
	initFereastra();
	jucator->initPawn();
	fereastra->display();
	initBackground();
	deseneazaFrame();
	initGameOverText();
}


bool FlappyBirds::StartPressed()
{
	sgs.setSpritePos((fereastra->getSize().x - sgs.getMargini().width) / 2.f,
		(fereastra->getSize().y - sgs.getMargini().height) / 2.f);
//	sgs.setSpritePos(0.f, 0.f);
	auto poz_mouse = sf::Mouse::getPosition();//Vector2i
	auto poz_mouse_reala = fereastra->mapPixelToCoords(poz_mouse);//pozitia in pixeli pentru fereastra
//	if (sgs.getMargini().contains((sf::Vector2f)poz_mouse))
	/*if (poz_mouse.x <= fereastra->getSize().x / 2.f - GameOverText.getGlobalBounds().width / 2.f &&
		poz_mouse.y <= fereastra->getSize().y / 2.f - GameOverText.getGlobalBounds().height / 2.f)*/
if(poz_mouse_reala.x<1050.f&&poz_mouse_reala.x>900.f)
	if(poz_mouse_reala.y<600.f&&poz_mouse_reala.y>550.f)
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			return true;
return false;
}
FlappyBirds::~FlappyBirds()
{
	for (auto* i : obstacole)
	{
		delete i;
	}
}

void FlappyBirds::ruleaza()
{	
	
		while (fereastra->isOpen())

			if (coliziuniObstacole() == false)
			{
				EventsUpdate();
				updateObstacole();
				updateGUI();
				updateColision();
				updateInput();
				jucator->gravitatie();
				jucator->updateCooldown();
				StergeObstacole();
				checkIfVisible();//background in fereastra vizibila
				moveBackground();
				deseneazaFrame();
			}


}

void FlappyBirds::deseneazaSGmState()
{
	sgs.deseneazaSGmState(fereastra);
}
void FlappyBirds::deseneazaFrame()
{
	
	fereastra->clear();
	deseneazaBackground();
	deseneazaGUI();
	jucator->deseneazaJucator(fereastra);
	for (auto* i : obstacole)
	{
		i->deseneazaObstacol(fereastra);
	}

	if (coliziuniObstacole() == true)
	{
		GOS.setTextPos(fereastra->getSize().x / 2.f - GameOverText.getGlobalBounds().width / 2.f,
			fereastra->getSize().y / 2.f - GameOverText.getGlobalBounds().height / 2.f);
		GOS.deseneazaGmOvState(fereastra);
	}
	fereastra->display();
}


void FlappyBirds::initGameOverText()
{
	if(this->GameOverFont.loadFromFile("Font/LeagueSpartan-Bold.otf")==false)
		std::cout << "font error not loaded\n";
	else
	{
		GameOverText.setFont(GameOverFont);
		GameOverText.setCharacterSize(70);
		GameOverText.setFillColor(sf::Color::Red);
		GameOverText.setString("GAME OVER Romeo");
		GameOverText.setPosition
		(
			fereastra->getSize().x / 2.f - GameOverText.getGlobalBounds().width / 2.f,
			fereastra->getSize().y / 2.f - GameOverText.getGlobalBounds().height / 2.f
		);
	}
}

void FlappyBirds::EventsUpdate()
{
	sf::Event x;
	while (this->fereastra->pollEvent(x));	{
		if (x.type == sf::Event::Closed)
			fereastra->close();
		if (x.KeyPressed != 0 && x.Event::key.code == sf::Keyboard::Escape)
			fereastra->close();
	}
}

sf::RenderWindow* FlappyBirds::getfereastra()
{
	return fereastra;
}

void FlappyBirds::initGUI()
{
	if (this->GUIfont.loadFromFile("Font/LeagueSpartan-Bold.otf") == false)
		std::cout << "font error not loaded\n";
	//puncte
	GUItext.setPosition(600.f, 25.f);
	GUItext.setFont(GUIfont);
	GUItext.setCharacterSize(30);
	GUItext.setFillColor(sf::Color::White);
}

void FlappyBirds::deseneazaGUI()
{
	fereastra->draw(GUItext);
}

void FlappyBirds::updateGUI()
{
	std::stringstream ss;
	ss << "Puncte: " << puncte;
	GUItext.setString(ss.str());
}

sf::FloatRect FlappyBirds::getBackgroundMargini()
{
	return backgrounds[0].getGlobalBounds();
}

void FlappyBirds::deseneazaBackground()
{
	fereastra->draw(Background);
	fereastra->draw(Background1);
	fereastra->draw(Background2);
	fereastra->draw(Background3);

}
void FlappyBirds::checkIfVisible()
{
	if (Background.getGlobalBounds().left + Background.getGlobalBounds().width < 0.f)
		Background.setPosition(Background.getGlobalBounds().left + Background.getGlobalBounds().width * 4.f,0.f);

	if (Background1.getGlobalBounds().left + Background.getGlobalBounds().width < 0.f)
		Background1.setPosition(Background1.getGlobalBounds().left + Background.getGlobalBounds().width * 4.f, 0.f);
	
	if (Background2.getGlobalBounds().left + Background.getGlobalBounds().width < 0.f)
		Background2.setPosition(Background2.getGlobalBounds().left + Background.getGlobalBounds().width * 4.f, 0.f);

	if (Background3.getGlobalBounds().left + Background.getGlobalBounds().width < 0.f)
		Background3.setPosition(Background3.getGlobalBounds().left + Background.getGlobalBounds().width * 4.f, 0.f);

}

void FlappyBirds::moveBackground()
{
	Background.move(-3.f, 0.f);
	Background1.move(-3.f, 0.f);
	Background2.move(-3.f, 0.f);
	Background3.move(-3.f, 0.f);
}


void FlappyBirds::initBackground()
{
	if (texturaBackground.loadFromFile("Texturi/background.png") == false)
		std::cout << "load texture failed \n";
	else
	{
		Background.setTexture(texturaBackground);
		Background.setPosition(0.f, 0.f);
		Background.setScale(0.8f, 0.8f);

		Background1 = Background;
		Background1.setPosition(Background.getGlobalBounds().left+ Background.getGlobalBounds().width, 0.f);
		
		Background2 = Background;
		Background2.setPosition(Background1.getGlobalBounds().left + Background.getGlobalBounds().width, 0.f);

		Background3 = Background;
		Background3.setPosition(Background2.getGlobalBounds().left + Background.getGlobalBounds().width, 0.f);

	
	}
}

void FlappyBirds::updateObstacole()
{
	SpawneazaObstacole();
	for (auto* i : obstacole)
		i->miscaObstacol();

}
bool FlappyBirds::coliziuniObstacole()
{
	for (auto* i : obstacole)
	{
		if (i->getUpperBounds().contains(jucator->getMargini().left + jucator->getMargini().width, jucator->getMargini().top))//left==jucator->getMargini().left+jucator->getMargini().width)
		{
			return true;
			fereastra->draw(GameOverText);
		}
		else

			if (i->getLowerBounds().contains(jucator->getMargini().left + jucator->getMargini().width, jucator->getMargini().top + jucator->getMargini().height))
			{
				return true;
				fereastra->draw(GameOverText);
			}
//daca nu s-a returnat nimic continuam cu calculul de puncte calculate in functie de "air time between pipes"
		if (i->getUpperBounds().intersects(jucator->getMargini()))
			puncte++;
	}
	return false;
}
void FlappyBirds::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&jucator->poateZbura())
		jucator->updateJucator();
}

void FlappyBirds::updateJucator()
{
	jucator->updateJucator();
}

void FlappyBirds::initFereastra()
{
	fereastra = new sf::RenderWindow(sf::VideoMode(900, 700), "flappy burb", sf::Style::Close | sf::Style::Titlebar);
	fereastra->setFramerateLimit(120);
	fereastra->setVerticalSyncEnabled(0);
}

void FlappyBirds::updateColision()
{
	//coliziunea din partea de sus a consolei
	if (jucator->getMargini().top < 0.f)
		jucator->setPozitie(jucator->getMargini().left, 0.f);

	//coliziunea din partea de jos
	if (jucator->getMargini().top + jucator->getMargini().height >= fereastra->getSize().y) //marginea din stanga a jucatorului + latimea jucatorului = marginea din dreapta
		jucator->setPozitie(jucator->getMargini().left, fereastra->getSize().y - jucator->getMargini().height);//marginea din dreapta a ferestrei - latimea obiectului = marginea din dreapta suprapusa cu marginea din dreapta a ferestre,

}

void FlappyBirds::StergeObstacole() 
{
	int aux = 0;
	for (auto* i : obstacole)
	{
		if (i->getUpperBounds().left + i->getUpperBounds().width < 0.f)
		{
			delete i;
			obstacole.erase(obstacole.begin() + aux);
		}
		aux++;
	}
	for (int i = 0; i < backgrounds.size(); i++)
	{
		if (backgrounds[i].getGlobalBounds().left + backgrounds[i].getGlobalBounds().width <= 0.f)
			backgrounds.erase(backgrounds.begin() + i);
	}
}


void FlappyBirds::SpawneazaObstacole()
{
	if (SpawnCoold >= SpawnCooldMax)
	{
		SpawnCoold = 0;
		obstacole.push_back(new Obstacol());

	}
	else
		SpawnCoold += 0.05;
	
}
