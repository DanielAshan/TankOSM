//player.h

//#ifndef PLAYER_H
//#define PLAYER_H

class Player {
	private:
	int position[2];
	int lives = 3;
	int direction = 1;
	int collider[20][20];
	bool canShoot;


	int sprite[8][8] = {{10000,10000,10000,10000,10000,10000,10000,10000},
						{10000,10000,10000,10000,10000,10000,10000,10000},
						{10000,10000,10000,10000,10000,10000,10000,10000},
						{10000,10000,10000,10000,10000,10000,10000,10000},
						{10000,10000,10000,10000,10000,10000,10000,10000},
						{10000,10000,10000,10000,10000,10000,10000,10000},
						{10000,10000,10000,10000,10000,10000,10000,10000},
						{10000,10000,10000,10000,10000,10000,10000,10000}};

	public:
	Player() = default;
	Player(int x, int y);
	int* getPosition();
	int** getSprite();
	int getLives();
	int getDirection();

	void move();
	void draw();

};
