#include <8051.h>
//#include "reg51.h"
//#include "intrins.h"
#include "stc8.h"
#define FOSC 11059200UL

// a bit handled special by the compiler
#define bool __bit
// an 8 bit integer
#define tinyint unsigned char

#define ON 0
#define OFF 1


void  delay_ms(unsigned int ms)
{
	unsigned int i;

	if(ms<1)return;
	do{
		i = FOSC / 18000;//19520=922ms;//18732=961ms;//  2*13000;//26000=694ms
		while(--i)    ;   //14T per loop
	}while(--ms);
}

void blinkshort(){
	P33=ON;
	delay_ms(200);
	P33=OFF;
	delay_ms(250);
}

void blinklong(){
	P33=ON;
	delay_ms(400);
	P33=OFF;
	delay_ms(250);
}
void pause(){
	delay_ms(600);
}

void main()
{
	tinyint x;
	P3M0=0x8; // p33 output rest input
	P3M1=0;	  //
		
	P33=ON;
	delay_ms(1000);
	P33=OFF;
	delay_ms(1000);
	
	//infinitive loop, sending SOS in morse code
	while(1){
		for(x=0;x<3;x++) blinkshort();		
		pause();
		for(x=0;x<3;x++) blinklong();
		pause();
		for(x=0;x<3;x++) blinkshort();
		pause();
		pause();		
	}
}

