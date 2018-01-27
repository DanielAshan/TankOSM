#include "player.h"
#include <stdlib.h>
#include "peripherals.h"



Player::Player(int x, int y)
{
	this->position[0] = x;
	this->position[1] = y;
	this->canShoot = true;
	this->direction = 1;
	this->lives = 3;
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


void Player::setNewPosition(int x, int y)
{
	this->position[0] = x;
	this->position[1] = y;
}

void Player::setDirection(int dir)
{
	switch(dir)
	{
	case 1:
		this->direction = 1;
		break;
	case 2:
		this->direction = 2;
		break;
	case 3:
		this->direction = 3;
		break;
	case 4:
		this->direction = 4;
		break;
	default:
		break;
	}
}

void Player::setCollider()
{
	for(int i = 0; i <= 39;i++){
		for(int j = 0; j <= 39 ; j++){
			this->collider[i][j][0] = this->position[0] + i;
			this->collider[i][j][1] = this->position[1] + j;
		}
	}
}

void Player::draw(unsigned long* GRAPH)
{
	for(int i=0; i<=39; i++) {
			for(int j=0; j<=39; j++) {
				if (this->sprite[i/5][j/5] > 0) {
					switch(this->direction)
						{
						case 1:
							SetPixel(GRAPH, (this->position[0]+i),  (this->position[1]+j), sprite[i/5][j/5]);
							break;
						case 2:
							SetPixel(GRAPH, (this->position[0]+i), (this->position[1]+j), sprite[j/5][i/5]);
							break;
						case 3:
							SetPixel(GRAPH, (this->position[0]+i), (this->position[1]+j), sprite[7-i/5][7-j/5]);
							break;
						case 4:
							SetPixel(GRAPH, (this->position[0]+i), (this->position[1]+j), sprite[7-j/5][7-i/5]);
							break;
						default:
							break;
						}

				}
			}
		}
}

void Player::move()
{
			if((int) JoYAct.AxisX/100 > 0){
				this->setDirection(3);
				this->position[0] += (int) JoYAct.AxisX/100;
			} else if((int) JoYAct.AxisX/100 < 0){
				this->setDirection(1);
				this->position[0] += (int) JoYAct.AxisX/100;
			} else if((int) JoYAct.AxisY/100 > 0){
				this->setDirection(4);
				this->position[1] += (int) JoYAct.AxisY/100;
			} else if((int) JoYAct.AxisY/100 < 0){
				this->setDirection(2);
				this->position[1] += (int) JoYAct.AxisY/100;
			}

}
void Player::reloading(){
	if (this->reloadTimer > 0) {
		this->reloadTimer -= 1;
		if(this->reloadTimer == 0) {
			this->canShoot = true;
		}
	}

}
bool Player::shoot(){
	if(this->canShoot){
		this->reloadTimer = 100;
		this->canShoot = false;
		return true;
	} else {
		return false;
	}
}
