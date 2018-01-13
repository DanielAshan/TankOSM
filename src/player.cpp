#include "player.h"
#include <stdlib.h>
#include "peripherals.h"

extern unsigned long SCREENBUF[640 * 480];
unsigned long* GRAPH = SCREENBUF;

Player::Player(int x, int y)
{
	position[0] = x;
	position[1] = y;
	canShoot = true;
	direction = 1;
	lives = 3;
}

int* Player::getPosition()
{
	return this->position;
}

int** Player::getSprite()
{
	return (int**) this->sprite;
}

int Player::getLives()
{
	return this->lives;
}

int Player::getDirection()
{
	return this->direction;
}

void Player::draw()
{
	for(int i=0; i<=39; i++) {
			for(int j=0; j<=39; j++) {
				if (this->sprite[i/5][j/5] > 0) {
					SetPixel(GRAPH, i, j, 1000)
				}
			}
		}
}
