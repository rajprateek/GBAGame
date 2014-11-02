// NAME : RAJ PRATEEK KOSARAJU

typedef struct block{	//The white blocks - decreases score by 75 upon collision
	int c;
	int r;
	int width;
	int height;	
} Block;

void moveHideB(Block* walls);

