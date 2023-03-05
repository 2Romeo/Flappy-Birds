#pragma once
#include "Obstacol.h"
#include "DefaultPawn.h"
#include "GameOverState.h"
#include <iostream>
#include "StartGameState.h"
#include <sstream>
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
	sf::Sprite Background1;
	sf::Sprite Background2;
	sf::Sprite Background3;
	sf::Texture texturaBackground;
	std::vector<sf::Sprite> backgrounds;
	int puncte=0;
	GameOverState GOS;
	sf::Font GUIfont;
	sf::Text GUItext;
public:
	StartGameState sgs;
	bool StartPressed();
	sf::RenderWindow* getfereastra();
	void initGUI();
	void deseneazaGUI();
	void updateGUI();
	sf::FloatRect getBackgroundMargini();
	void deseneazaBackground();
	void checkIfVisible();
	void moveBackground();
	void spawnBackgrounds();
	void initBackground();
	void updateObstacole();
	bool coliziuniObstacole();
	void initGameOverText();
	//void updateObstacole();
	void updateInput();
	void EventsUpdate();
	void updateJucator();
	void deseneazaSGmState();
	void deseneazaFrame();
	void initFereastra();
	void deseneazaInamici();
	sf::RenderWindow* fereastra;// = new sf::RenderWindow(sf::VideoMode(800, 600), "flappy burb", sf::Style::Close | sf::Style::Titlebar);
	FlappyBirds();
	~FlappyBirds();
	void ruleaza();//updateaza si deseneaza
	void SpawneazaObstacole();
	void updateColision();
	void StergeObstacole();
};

