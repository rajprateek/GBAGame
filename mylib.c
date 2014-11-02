
#include "mylib.h"

u16* videoBuffer = (u16*)0x6000000;


// A function to set pixel (r, c) to the color passed in.
void setPixel(int row, int col, u16 color)
{
	//if(col<0 || col>240) return;
	//if(row<0 || row>160) return;
	*(videoBuffer + OFFSET(row, col,240)) = color;  		//since it isn't 4 pixels or more
}


//delay
void delay(int n){
	int i;
	volatile int x=0;
	for(i=0; i<n*10000; i++){
		x++;
	}

}
//waitforVblank
void waitforVBlank() {
	while (SCANLINECOUNTER > 160); 			//waitforVBlank
	while (SCANLINECOUNTER < 160);				//waitforVBlank
}
// A function to draw a FILLED rectangle starting at (r, c)

void drawRect(int r, int c, int width, int height, u16 color)
{
	for(int i=r; i<r+height; i++){
			for(int j=c; j<c+width; j++){
				setPixel(i,j,color);
			}
	}
}

void drawRect2(int row, int col, int width, int height, volatile unsigned short color) { 
	int r; 
	for(r=0; r<height; r++) 
	{ 	
	DMA[3].src = &color; 
	DMA[3].dst = &videoBuffer[OFFSET(row+r, col, 240)]; 
	DMA[3].cnt = width | DMA_SOURCE_FIXED | DMA_ON; 
	}
}


// A function to draw a HOLLOW rectangle starting at (r, c)
void drawHollowRect(int r, int c, int width, int height, u16 color)
{	
	
	DMA[3].src = &color;
	DMA[3].dst =  videoBuffer + OFFSET(r,c,240);
	DMA[3].cnt = width | DMA_ON | DMA_SOURCE_FIXED ;

	DMA[3].src = &color;
	DMA[3].dst =  videoBuffer + OFFSET(r+height,c,240);
	DMA[3].cnt = width | DMA_ON | DMA_SOURCE_FIXED ;

	for(int j=r; j<=r+height; ++j){
		setPixel(j,c,color);
		setPixel(j, c+width, color);
	} 
}
// A function to draw a HOLLOW Triangle starting at (r,c)
void drawTriangle(int r, int c, int height, u16 color)
{	int i=0;
	for( i=0; i<height; ++i){
		setPixel(r+i,c-i,color);
		setPixel(r-i , c-i, color);
	}
	drawRect(r-i,c-i,1,2*i+1,color);
	
}

void fillScreen(volatile u16 color)
{
	DMA[3].src = &color;
	DMA[3].dst  = videoBuffer;
	DMA[3].cnt = 240*160|DMA_SOURCE_FIXED | DMA_ON ;
}
	
void drawPicture(const unsigned short arr[])
{
	DMA[3].src = arr;
	DMA[3].dst = videoBuffer;
	DMA[3].cnt = (240*160) | DMA_ON;
}

void drawImage3(int row, int col, int width, int height, const u16* image) {
	 while(height--) { 
		DMA[3].src = image + (width*height); 
		DMA[3].dst = videoBuffer + 240*(row+height) + col; 
		DMA[3].cnt = width | DMA_ON; 
	} 
}
