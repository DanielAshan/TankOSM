//enemy.h

class Enemy {
private:
	int id;
	int hp;
	int type;
	int score;
	int direction;
	int position[2];
	int sprite[8][8] = {{20000,20000,10000,1000,1000,10000,20000,20000},
						{20000,20000,10000,1000,1000,10000,20000,20000},
						{20000,20000,10000,1000,1000,10000,20000,20000},
						{20000,20000,100,100,100,100,20000,20000},
						{20000,20000,100,100,100,100,20000,20000},
						{20000,20000,10000,10000,10000,10000,20000,20000},
						{20000,20000,10000,10000,10000,10000,20000,20000},
						{20000,20000,10000,10000,10000,10000,20000,20000}};

public:
	int collider[40][40][2];

	Enemy(int id, int hp, int type, int score, int x, int y, int dir);
	int getId();
	int getHp();
	int getScore();

	void setNewPosition(int x, int y);
	void setDirection(int dir);
	void setCollider();
	void move();
	void draw(unsigned long* GRAPH);
};
