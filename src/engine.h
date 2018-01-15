//engine.h

//#ifndef ENGINE_H
//#define ENGINE_H

#include "player.h"
#include "enemy.h"
#include "stdlib.h"

class Engine{
	private:
	Player firstPlayer;
	Enemy* listOfEnemies[10];

	public:
	Engine(Player playerOne);

	void createEnemies();
	void draw();
	void drawHUD();



};


