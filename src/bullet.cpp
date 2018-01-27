#include "bullet.h"
#include <stdlib.h>
#include "peripherals.h"


Bullet::Bullet(int x, int y, int direction, int owner){
	this->position[0] = x;
	this->position[1] = y;
	this->direction = direction;
	this->owner = owner;
}

void Bullet::move(){
	switch(this->direction){
	case 1:
		this->position[0] -= 1;
			break;
	case 2:
		this->position[1] -= 1;
			break;
	case 3:
		this->position[0] += 1;
			break;
	case 4:
		this->position[1] += 1;
			break;
	}


}
bool Bullet::shouldExist(){
	if(((this->position[0]-1) < 0) || ((this->position[0]+1) > 480) || ((this->position[1]-1 )< 0) || ((this->position[1]+1) > 640)){
		return false;
	} else {
		return true;
	}

}

void Bullet::draw(unsigned long* GRAPH){

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
