#include  <SFML/Graphics.hpp> 
#include "FlappyBirds.h"
#include <iostream>
#include "Obstacol.h"
#include "StartGameState.h"
int main()//masina de stari si starile si input-ul fac parte din motorul jocului
{
    srand(static_cast<unsigned>(0));
    FlappyBirds game;
  //  StartGameState* sgs=new StartGameState(game.getfereastra());
   // game.getfereastra()->display();
   // game.getfereastra()->display();
 //   sgs.deseneazaSGmState(game.getfereastra());
    while (game.StartPressed() == false)
    {
        game.StartPressed();
        game.deseneazaBackground();
        game.deseneazaSGmState();
        game.fereastra->display();
    }
    if(game.StartPressed()==true)
     game.ruleaza();

    return 1;
}