//player.h

//#ifndef PLAYER_H
//#define PLAYER_H

extern unsigned long* GRAPH;

class Player {
	private:

	int lives = 3;
	int direction = 1;
	bool canShoot;


	int sprite[8][8] = {{10000,10000,10000,1000,1000,10000,10000,10000},
						{10000,10000,10000,1000,1000,10000,10000,10000},
						{10000,10000,10000,1000,1000,10000,10000,10000},
						{10000,10000,100,100,100,100,10000,10000},
						{10000,10000,100,100,100,100,10000,10000},
						{10000,10000,10000,10000,10000,10000,10000,10000},
						{10000,10000,10000,10000,10000,10000,10000,10000},
						{10000,10000,10000,10000,10000,10000,10000,10000}};

	public:
	int position[2];
	int collider[20][20][2];

	Player() = default;
	Player(int x, int y);
	int* getPosition();
	int** getSprite();
	int getLives();
	int getDirection();

	void setNewPosition(int x, int y);
	void setDirection(int dir);
	void setCollider();
	void move();
	void draw();

};
