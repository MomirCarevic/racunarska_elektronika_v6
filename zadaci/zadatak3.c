#include<signal.h>
#include<stdlib.h>
#include<stdio.h>
#include<wiringPi.h>
#include<lcd.h>
#include<string.h>
#include<time.h>
#include<unistd.h>

char slovo0[8] = {0b01000,0b11110,0b01000,0b01000,0b01111,0b01001,0b01001,0b00000}; // slovo ć
char slovo1[8] = {0b10101,0b10101,0b10101,0b01110,0b10101,0b10101,0b10101,0b00000}; // slovo ž

#define COLUMNS 16
#define LCD_RS 3
#define LCD_E 14
#define LCD_D4 4
#define LCD_D5 12
#define LCD_D6 13
#define LCD_D7 6

void memory(void);
void volume(void);
void scrollText(void);

int count = 0;
int j = 0;
FILE *mem_file;
char*temp;
int lcd;

int main()
{
	wiringPiSetup();
	
	if(lcd = lcdInit(2,16,4,LCD_RS,LCD_E,LCD_D4,LCD_D5,LCD_D6,LCD_D7,0,0,0,0))
	{
		printf("lcdInit nije uspeo!!!\n");
		return -1;
	}
	
	int uptimeTimer;

	while(1)
	{
		lcdClear(lcd);
		volume();
		sleep(1);
	}
}



void volume(void)
{
	//Definicija specijalnih karaktera za Volume
	lcdCharDef(lcd,0,slovo0);
	lcdCharDef(lcd,1,slovo1);


	lcdClear(lcd);

	int i;
	lcdPosition(lcd,0,0);
	lcdPuts(lcd,"Cirilicna slova:");
	lcdPosition(lcd,0,1);
	for(i = 0 ; i < 8 ; i++)
	{
		lcdPosition(lcd,i,1);
		lcdPutchar(lcd,i);
		usleep(400000);
	}
}
