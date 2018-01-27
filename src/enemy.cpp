//enemy.cpp
#include "enemy.h"
#include <stdlib.h>
#include "peripherals.h"



Enemy::Enemy(int id, int hp, int type, int score, int x, int y, int dir)
{
	this->id = id;
	this->hp = hp;
	this->type = type;
	this->score = score;
	this->position[0] = x;
	this->position[1] = y;
	this->direction = dir;
}


void Enemy::setNewPosition(int x, int y)
{
	this->position[0] = x;
		this->position[1] = y;
}

void Enemy::setDirection(int dir)
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

void Enemy::setCollider()
{
	for(int i = 0; i <= 39;i++){
		for(int j = 0; j <= 39 ; j++){
			this->collider[i][j][0] = this->position[0] + i;
			this->collider[i][j][1] = this->position[1] + j;
		}
	}

}

void Enemy::draw(unsigned long* GRAPH)
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
