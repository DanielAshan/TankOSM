#include "engine.h"



Engine::Engine(Player playerOne)
{
	firstPlayer = playerOne;

}

void Engine::createEnemies(){

	for(int i = 0; i <= 9; i++) {
			this->listOfEnemies[i] = new Enemy(i, 1, 1, 50, rand()%600, rand()%440, 1+rand()%4);
	}
}

void Engine::draw()
{
	firstPlayer.draw();
	for(int i = 0; i <= 9; i++) {
		this->listOfEnemies[i]->draw();
	}
}
