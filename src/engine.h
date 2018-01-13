//engine.h

//#ifndef ENGINE_H
//#define ENGINE_H

#include "player.h"
#include "stdlib.h"

class Engine{
	private:
	Player firstPlayer;

	public:
	Engine(Player playerOne);
	void draw();
	void drawHUD();



};


