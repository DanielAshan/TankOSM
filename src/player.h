//player.h

//#ifndef PLAYER_H
//#define PLAYER_H
extern struct JoY JoYAct;

class Player {
	private:


	public:
	int position[2];
	int collider[20][20][2];
	int lives = 3;
	int direction = 1;
	int reloadTimer = 0;
	bool canShoot = true;


	int sprite[8][8] = {{10000,10000,10000,1000,1000,10000,10000,10000},
						{10000,10000,10000,1000,1000,10000,10000,10000},
						{10000,10000,10000,1000,1000,10000,10000,10000},
						{10000,10000,100,100,100,100,10000,10000},
						{10000,10000,100,100,100,100,10000,10000},
						{10000,10000,10000,10000,10000,10000,10000,10000},
						{10000,10000,10000,10000,10000,10000,10000,10000},
						{10000,10000,10000,10000,10000,10000,10000,10000}};


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
	void draw(unsigned long* GRAPH);
	void reloading();
	bool shoot();


};
