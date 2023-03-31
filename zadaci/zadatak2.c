// zadatak da dugmicima
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<wiringPi.h>
#include<lcd.h>

const int RS = 3;
const int EN = 14;
const int D0 = 4;
const int D1 = 12;
const int D2 = 13;
const int D3 = 6;

int ReadButton()
{
    if(digitalRead(21) == LOW) // LEVO
        return  1;
    if(digitalRead(22) == LOW) // DESNO
        return  2;
    if(digitalRead(23) == LOW) // GORE
        return  3;
    if(digitalRead(24) == LOW) // DOLE
        return  4;
    return 0;
}

int main(){

    // setup za wiringPi

    if(wiringPiSetup() < 0)
	{
		fprintf(stderr,"Greska pri inicijalizaciji: %s/n",strerror(errno));
		return 1;
	}

    // setup za dugmice

    pinMode(21,INPUT);
    pinMode(22,INPUT);
    pinMode(23,INPUT);
    pinMode(24,INPUT);

    // lcd setup

    int lcd_h;
    lcd_h = lcdInit(2,16,4,RS,EN,D0,D1,D2,D3,D0,D1,D2,D3);

    // setup za pomeranje kursora

    int x = 0;
    int y = 0;
    int taster = 0;
    int taster_old = 0;

    while(1)
    {
        taster = ReadButton();
        if(taster != taster_old || taster != 0)
        {
          /*  if(taster == 1) // LEVO
            {
                x--;
                if( x < 0 )
                    x = 15;
		delay(100);
            }*/
            if(taster == 1) // DESNO
            {
                x++;
                if( x >= 15 )
                    x = 0;
		delay(200);
            }
            if(taster == 2) // GORE
            {
                y++;
                if( y > 1 )
                    y = 0;
		delay(200);
            }
           /* if(taster == 4) // DOLE
            {
                y++;
                if( y > 1 )
                    y = 0;
		delay(100);
            }*/
        }
        taster_old = taster;
	lcdPosition(lcd_h,x,y);
	lcdCursor(lcd_h, 1);
    }

}
