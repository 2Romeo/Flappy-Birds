#include "FlappyBirds.h"
#include <SFML/Graphics.hpp>

FlappyBirds::FlappyBirds()
{
	
	jucator->initPawn();
	initFereastra();
	initBackground();
	initGameOverText();
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
	while (fereastra->isOpen()) {
		if (coliziuniObstacole() == false)
		{
			updateObstacole();
			updateColision();
			updateInput();
			EventsUpdate();
			jucator->gravitate();
			StergeObstacole();
			deseneazaFrame();
		}
		else
		{
			fereastra->draw(GameOverText);
			fereastra->display();
		}
	}

}

void FlappyBirds::deseneazaFrame()
{

	fereastra->clear();
	deseneazaBackground();
	for (auto* i : obstacole)
	{
		i->deseneazaObstacol(fereastra);
	}
	jucator->deseneazaJucator(fereastra);
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

void FlappyBirds::deseneazaBackground()
{
	moveBackground();
	fereastra->draw(Background);
}

void FlappyBirds::moveBackground()
{
	Background.move(-1.f, 0.f);
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
		if (i->getLowerBounds().contains(jucator->getMargini().left + jucator->getMargini().width, jucator->getMargini().top + jucator->getMargini().width))
		{
			return true;
			fereastra->draw(GameOverText);
		}
	}
	return false;
}
void FlappyBirds::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		jucator->updateJucator();
}
void FlappyBirds::EventsUpdate()
{
	sf::Event x;//orice eveniment ce se intampal cu fereastra de ex: inchidere fereastra, miscare mouse
	while (this->fereastra->pollEvent(x));//metoda pollEvent returneaza evenimentul din varful stivei de evenimente,daca exista, si il salveaza in variabila sf::event data ca parametru
	//verificam ce eveniment am salvat in variabila
	{
		if (x.type == sf::Event::Closed)//verificam daca evenimentul a fost inchiderea ferestrei, impropriu spus, deoarece evenimentul se refera doar la apasarea butonului de inchidere
			fereastra->close();//implementam inchiderea reala a ferestrei
		if (x.KeyPressed != 0 && x.Event::key.code == sf::Keyboard::Escape)//daca evenimentul este de apasare a butonului si butonul apasat este ESC
			fereastra->close();
	}
}


void FlappyBirds::updateJucator()
{
	jucator->updateJucator();
}

void FlappyBirds::initFereastra()
{
	fereastra = new sf::RenderWindow(sf::VideoMode(800, 600), "flappy burb", sf::Style::Close | sf::Style::Titlebar);
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
}


void FlappyBirds::SpawneazaObstacole()
{
	if (SpawnCoold >= SpawnCooldMax)
	{
		SpawnCoold = 0;
		obstacole.push_back(new Obstacol());

	}
	else
		SpawnCoold += 0.1;
	
}
