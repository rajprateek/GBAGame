// NAME : RAJ PRATEEK KOSARAJU

#include "mylib.h"
#include "fire.h"


void moveHideF(Fire* fire) {
	for(int i=0 ; i<5 ; i++) {
		Fire f = fire[i];
		if (f.r<1) 
			f.r = 240; 
		
			drawRect(f.c-1,f.r+f.width,1,f.height+1+1, BLACK);
			drawRect(f.c+1,f.r,1,f.height-1, BLACK);
			drawRect(f.c,f.r-1,1,f.height+1, RED);
			drawRect(f.c,f.r+f.width-1,1,f.height+1, RED);
		
		f.r = f.r -1;
		fire[i] = f;
		
		
		
	}
}
