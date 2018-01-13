#include "engine.h"




Engine::Engine(Player playerOne)
{
	firstPlayer = playerOne;
}


void Engine::draw()
{
	firstPlayer.draw();
}
