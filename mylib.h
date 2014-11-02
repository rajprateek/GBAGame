typedef unsigned short u16;
typedef unsigned int u32;
typedef volatile unsigned short vu16;

#define OFFSET(r,c,numcols) ((r)*(numcols)+c)
#define TRUE 1
#define FALSE 0


#define REG_DISPCNT  *(unsigned short *) 0x4000000


#define RGB(r,g,b) ((r) + ((g) << 5) + ((b) << 10))

#define BG2_ENABLE  (1<<10)
#define REG_VCOUNT *(u16*)0x04000006

#define SCANLINECOUNTER *(volatile unsigned short *)0x4000006

#define BLACK   RGB(0,0,0)
#define WHITE   RGB(31, 31, 31)
#define RED     RGB(31,0,0)
#define GREEN   RGB(0, 31, 0)
#define BLUE    RGB(0,0,31)
#define YELLOW  RGB(31,31,0)
#define CYAN    RGB(0,31,31)
#define MAGENTA RGB(31,0,31)
#define GREY    RGB(25, 25, 25)
#define BROWN 	RGB(25,16,8)


#define MODE3 3

// Buttons
#define BUTTONS (*(unsigned int *)0x4000130)

#define BUTTON_A	(1<<0)
#define BUTTON_B	(1<<1)
#define BUTTON_SELECT	(1<<2)
#define BUTTON_START	(1<<3)
#define BUTTON_RIGHT	(1<<4)
#define BUTTON_LEFT	(1<<5)
#define BUTTON_UP	(1<<6)
#define BUTTON_DOWN	(1<<7)
#define BUTTON_R	(1<<8)
#define BUTTON_L	(1<<9)
#define KEY_DOWN_NOW(key)  (~(BUTTONS) & key)
/* DMA */

typedef struct
{								// ***********************************************************
	 const volatile void *src;	// We mark this as const which means we can assign it const
	 volatile void *dst;		// things without the compiler yelling but we can also pass it
	 volatile u32 cnt;		// things that are not const!
								// ***********************************************************
} DMAREC;

#define DMA ((volatile DMAREC *)0x040000B0)

#define DMA_DESTINATION_INCREMENT (0 << 21)
#define DMA_DESTINATION_DECREMENT (1 << 21)
#define DMA_DESTINATION_FIXED (2 << 21)
#define DMA_DESTINATION_RESET (3 << 21)

#define DMA_SOURCE_INCREMENT (0 << 23)
#define DMA_SOURCE_DECREMENT (1 << 23)
#define DMA_SOURCE_FIXED (2 << 23)

#define DMA_REPEAT (1 << 25)

#define DMA_16 (0 << 26)
#define DMA_32 (1 << 26)

#define DMA_NOW (0 << 28)
#define DMA_AT_VBLANK (1 << 28)
#define DMA_AT_HBLANK (2 << 28)
#define DMA_AT_REFRESH (3 << 28)

#define DMA_IRQ (1 << 30)
#define DMA_ON (1 << 31)

#define START_ON_FIFO_EMPTY 0x30000000


void drawRect2(int row, int col, int width, int height, volatile unsigned short color) ;
void setPixel(int row, int col, u16 color);
void drawRect(int r, int c, int width, int height, u16 color);
void delay(int n);
void drawHollowRect(int r, int c, int width, int height, u16 color);
void drawTriangle(int r, int c, int height, u16 color);
void waitforVBlank() ;
void fillScreen(u16);
void drawPicture(const unsigned short arr[]);
void drawImage3(int row, int col, int width, int height, const u16* image);

