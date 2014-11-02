// NAME : RAJ PRATEEK KOSARAJU


#include "mylib.h"
#include "player.h"

Player drawPlay(Player play){						//Function to draw the player. Called in the main while loop.
	drawTriangle(play.c,play.r,play.height, play.color);
	return play;
}
void hidePlay(Player play){
	drawTriangle(play.c,play.r,play.height, BLACK);			//Function to hide the player. Called in the main while loop.
}

