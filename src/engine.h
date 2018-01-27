//engine.h

//#ifndef ENGINE_H
//#define ENGINE_H
extern struct JoY JoYAct;

#include "player.h"
#include "enemy.h"
#include "stdlib.h"
#include "bullet.h"
class Engine{
	private:
	Player firstPlayer;
	Enemy* listOfEnemies[10];
	Bullet* listOfBullets[10];

	public:
	Engine(Player playerOne);
	int bulletCounter = -1;

	void createEnemies();
	void draw(unsigned long* GRAPH);
	void drawHUD(unsigned long* GRAPH);
	void move();
	void playerShoot();
	void reloading();

};


