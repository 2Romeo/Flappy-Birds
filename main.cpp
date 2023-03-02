#include  <SFML/Graphics.hpp> 
#include "FlappyBirds.h"
#include <iostream>
#include "Obstacol.h"
int main()//masina de stari si starile si input-ul fac parte din motorul jocului
{
    srand(static_cast<unsigned>(0));
    FlappyBirds game;
    Obstacol x;  
       
     game.ruleaza();

    return 1;
}