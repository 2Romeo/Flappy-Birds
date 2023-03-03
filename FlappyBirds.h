#pragma once
#include "Obstacol.h"
#include "DefaultPawn.h"
#include <iostream>
class FlappyBirds
{

private:
	float SpawnCooldMax=10.f;
	float SpawnCoold=SpawnCooldMax;
	std::vector<Obstacol*> obstacole;
	DefaultPawn *jucator = new DefaultPawn();
	sf::Text GameOverText;
	sf::Font GameOverFont;
	sf::Sprite Background;
	sf::Texture texturaBackground;
	std::vector<Background*> backgrounds
public:
	void deseneazaBackground();
	void moveBackground();
	void initBackground();
	void updateObstacole();
	bool coliziuniObstacole();
	void initGameOverText();
	//void updateObstacole();
	void updateInput();
	void EventsUpdate();
	void updateJucator();
	void deseneazaFrame();
	void initFereastra();
	void deseneazaInamici();
	sf::RenderWindow* fereastra;// = new sf::RenderWindow(sf::VideoMode(800, 600), "flappy burb", sf::Style::Close | sf::Style::Titlebar);
	FlappyBirds();
	~FlappyBirds();
	void ruleaza();//updateaza si deseneaza
	void SpawneazaObstacole();
	void updateColision();
	
	
	void IntersectieActor();
	void StergeObstacole();
};

