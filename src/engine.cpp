#include "engine.h"
#include "peripherals.h"


Engine::Engine(Player playerOne)
{
	firstPlayer = playerOne;

}

void Engine::createEnemies(){

	for(int i = 0; i <= 9; i++) {
			this->listOfEnemies[i] = new Enemy(i, 1, 1, 50, rand()%600, rand()%440, 1+rand()%4);
	}
}

void Engine::move()
{
	this->firstPlayer.move();
	for(int i = 0; i <= this->bulletCounter; i++) {
			this->listOfBullets[i]->move();
			if(! this->listOfBullets[i]->shouldExist()) {
				delete this->listOfBullets[i];
			}
	}

}
void Engine::playerShoot(){
	if (JoYAct.ButtonStates & BUTTON_1) {
		if(this->firstPlayer.shoot() && bulletCounter < 9) {
			this->bulletCounter++;
			this->listOfBullets[this->bulletCounter] = new Bullet(
					this->firstPlayer.position[0],
					this->firstPlayer.position[1],
					this->firstPlayer.direction,
					1
			);

		}
	}
}

void Engine::reloading(){
	this->firstPlayer.reloading();
}

void Engine::draw(unsigned long* GRAPH)
{
	firstPlayer.draw(GRAPH);
	for(int i = 0; i <= 9; i++) {
		this->listOfEnemies[i]->draw(GRAPH);
	}
	for(int i = 0; i <= this->bulletCounter; i++) {
		this->listOfBullets[i]->draw(GRAPH);
	}
}
