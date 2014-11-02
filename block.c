// NAME : RAJ PRATEEK KOSARAJU

#include "mylib.h"
#include "block.h"


void moveHideB(Block* walls){
	for(int g=0; g<7;g++){
		Block w = walls[g];
		if (w.r<1) 
			w.r = 240; 
			drawRect(w.c-1,w.r + w.width,1,w.height+1+1, BLACK);
			drawRect(w.c+1,w.r,1,w.height-1, BLACK);
			drawRect(w.c,w.r-1,1,w.height+1, GREY);
			drawRect(w.c,w.r+w.width-1,1,w.height+1, GREY);
		w.r = w.r -1;
		walls[g] = w;
	}
}
