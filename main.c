// NAME : RAJ PRATEEK KOSARAJU


#include <stdlib.h>
#include <stdio.h>

#define SCREENMAXHEIGHT 149

#include "mylib.h"
#include "text.h"
#include "splash2.h"
#include "winScreen.h"
#include "loseScreen.h"
#include "border.h"
#include "player.h"
#include "block.h"
#include "fire.h"

enum {SPLASH, GAME, WIN, LOSE};

// Prototypes
int splash();
int game();
void win();
void lose();






void update(int,int);
//void moveBlock(Block*);
Player drawPlay(Player);
void hidePlay(Player);
int score;
int main()
{
	
	int state = SPLASH;
	
	while(1)
	{
		switch(state)
		{
		case SPLASH:
			splash();
			state = GAME;
			break;
		case GAME:
			state = game();
			break;
		case WIN:
			win();
			state = SPLASH;
			break;
		case LOSE:
			lose();
			state = SPLASH;
			break;
		default:
			// handle error
			break;
		} // switch
	} // while
}		
int splash()
{
	
	REG_DISPCNT = MODE3 | BG2_ENABLE;
	int bal =1;	
	drawPicture(splashp);
	
	char scores[50];
	char any[50];
	
	sprintf(scores,"%s","WELCOME TO DODGE WALL!");
	sprintf(any,"%s","PRESS START TO CONTINUE.");
	
	
	
	
	while(1) {						//The while loop for the splash screen
		
		
		if(bal==1) {
			drawString(70,50,scores,MAGENTA);
			drawString(90,50,any,RED);
			bal=0;
		}
		else {
			drawString(70,50,scores,RED);
			drawString(90,50,any,MAGENTA);
			bal=1;
		}
		if (KEY_DOWN_NOW(BUTTON_START)) {
			break;
		}
			
	}
	
}		
void win()
{
	drawPicture(winscreen);
	char any[50];
	char scoreno[50];
	char cont[50];
	
	

	sprintf(any,"%s","YOU HAVE WON :D YOUR SCORE WAS:" );
	sprintf(scoreno,"%d",score);
	sprintf(cont,"%s","PRESS ENTER TO PLAY AGAIN" );
	drawString(70,30,any,BROWN);
	drawString(90,100,scoreno,BLACK);
	drawString(110,50,cont,MAGENTA);

	
	while(!KEY_DOWN_NOW(BUTTON_START));
	while(KEY_DOWN_NOW(BUTTON_START));
}

void lose()
{	drawPicture(losescreen);
	char any[50];
	char scoreno[50];
	char cont[50];
	

	sprintf(any,"%s","YOU HAVE LOST :( YOUR SCORE WAS:");		//Printing to the screen if player lost.
	sprintf(scoreno,"%d",score);
	sprintf(cont,"%s","PRESS ENTER TO PLAY AGAIN" );
	drawString(70,30,any,RED);
	drawString(90,100,scoreno,GREEN);
	drawString(110,50,cont,GREEN);
	
	while(!KEY_DOWN_NOW(BUTTON_START));
	while(KEY_DOWN_NOW(BUTTON_START));
	
	
}
int game()
{
	REG_DISPCNT = MODE3 | BG2_ENABLE;
	int r = 20;
	Block walls[7];
	Fire fire[5];
	Player p = {5,10,7,BROWN};
	int i;
	int wndx;
	int fndx;
	 
	i=48;
	wndx=0;
	fndx=0;
	score =50;
	int live = 3;
	
	drawTriangle(5,25,7,BROWN);
	
	drawHollowRect(r,i,24/2,10,RED);			//Initializing the 12 different types of blocks.
	Fire a = {r,i,48/4,20/2};
	fire[fndx] =a;
	fndx++;

	drawHollowRect(r-20,i+72,48/4,20/2,GREY);
	Block b = {r-20,i+72,48/4,20/2};
	walls[wndx] = b;
	wndx++;

	drawHollowRect(r+40,i,48/4,20/2,GREY);
	Block c = {r+40,i,48/4,20/2};
	walls[wndx] = c;
	wndx++;

	drawHollowRect(r+20,i+72,48/4,20/2,RED);
	Fire d = {r+20,i+72,48/4,20/2};
	fire[fndx] = d;
	fndx++;

	drawHollowRect(r+80,i,48/4,20/2,GREY);
	Block e = {r+80,i,48/4,20/2};
	walls[wndx] = e;
	wndx++;

	drawHollowRect(r+60,i+72,48/4,20/2,GREY);
	Block f = {r+60,i+72,48/4,20/2};
	walls[wndx] = f;
	wndx++;

	drawHollowRect(r+120,i,48/4,20/2,RED);
	Fire g = {r+120,i,48/4,20/2};
	fire[fndx] = g;
	fndx++;

	drawHollowRect(r+100,i+72,48/4,20/2,GREY);
	Block h = {r+100,i+72,48/4,20/2};
	walls[wndx] = h;
	wndx++;
	
	
	drawHollowRect(r,i+144,24/2,10,GREY);
	Block z = {r,i+144,48/4,20/2};
	walls[wndx] = z;
	wndx++;

	drawHollowRect(r+40,i+144,24/2,10,RED);
	Fire j = {r+40,i+144,48/4,20/2};
	fire[fndx] = j;
	fndx++;

	drawHollowRect(r+80,i+144,24/2,10,GREY);
	Block k = {r+80,i+144,48/4,20/2};
	walls[wndx] = k;
	wndx++;

	drawHollowRect(r+120,i+144,24/2,10,RED);
	Fire l = {r+120,i+144,48/4,20/2};
	fire[fndx] = l;
	fndx++;
	
	fillScreen(BLACK);
	int timer=0;
	while(score>=0 && score<500 && live>=0)
	{	
		score++;
		if (timer>0)
			timer++;
		if (timer==20){
			drawRect(132,100,160,7,BLACK);
			timer=0;
		}
		char scores[15];
		char lives[15];

		sprintf(scores,"%s","SCORE:"); 
		drawString(12,185,scores,BLUE);

		sprintf(lives,"%s","LIVES:"); 
		drawString(32,190,lives,GREEN);

		update(score,live);
		moveHideB(walls);
		moveHideF(fire);
		moveHideB(walls);
		moveHideF(fire);
		
		waitforVBlank(); 
		
		if (KEY_DOWN_NOW(BUTTON_DOWN)) {			//If conditions to move the player triangle up or down.
			hidePlay(p);
			if (p.c<147)
				p.c = p.c+2;
			p=drawPlay(p);
			
		}

		else if (KEY_DOWN_NOW(BUTTON_UP)) {
			hidePlay(p);
			if (p.c>5)
				p.c = p.c-2;
			p=drawPlay(p);
			
		}
		else if (KEY_DOWN_NOW(BUTTON_RIGHT)) {
			hidePlay(p);
			if (p.r<220)
				p.r = p.r+1;
			p=drawPlay(p);
		}
		else if (KEY_DOWN_NOW(BUTTON_LEFT)) {
			hidePlay(p);
			if (p.r>15)
				p.r = p.r-1;
			p=drawPlay(p);
		}
		else if (KEY_DOWN_NOW(BUTTON_SELECT)) {
			return SPLASH;
		}
			


		char consoles[50];

		for(int g=0; g<7;g++){								//For loop to check for collision with the GRAY blocks.
			Block w = walls[g];
			if ((w.r==p.r+p.height-5 && p.c>=w.c && p.c<=(w.c+w.height)))		//Condition for collision
			{
				p.color = GREY;
				drawPlay(p);
				drawRect(132,100,160,7,BLACK);
				sprintf(consoles,"%s","COLLISION!-75");
 				timer=1;
				drawString(132,160,consoles,BROWN);
				delay(2);
				p.color = BROWN;
				score-=75;
				
			}
		}
		
		for(int i=0 ; i<5 ; i++) {							//For loop to check for collision with the RED blocks
			Fire f = fire[i];
				
			if( (p.r<f.r+f.width) && (p.c<f.c+f.height) && (p.r+p.height-2>f.r) && (p.c+p.height>f.c))  //Condition for collision
			{	p.color = RED;
				drawPlay(p);
				drawRect(132,100,160,7,BLACK);
				sprintf(consoles,"%s","COLLISION! -1 LIFE");
				live--;
 				timer=1;
				drawString(132,110,consoles,RED);
				delay(2);
				hidePlay(p);
				p.r=10;
				p.c=5;
				p.color = BROWN;	
			}
	
		}
		drawImage3(0,0,15,160,border);
		drawPlay(p);

	}
	
	if(score>0 && live>=0) {								//To check if player has won.
		
		return WIN;
	}
	else {
		return LOSE;
	}

	
}
	
	

void update(int score,int live){				//Function to hide the old block and make a new block. Called in the main while loop.
	
	char scoreno[15];
	char liveno[15]; 
	sprintf(liveno,"%d",live); 
	drawRect2(32,230,8,7,BLACK);
	drawString(32,230,liveno,RED);
	if (score%5==0){
		sprintf(scoreno,"%d",score);
		drawRect2(12,220,20,7,BLACK); 
		drawString(12,220,scoreno,RED);
	}	

}


