/* 
 * File:   main.c
 * Author: Lionel Ponce
 * Title: LCD 16x2
 * Created on 6 de noviembre de 2015, 18:36
 */

#define _XTAL_FREQ 4000000
#define LCDEN PORTAbits.RA0
#define LCDRW PORTAbits.RA1
#define LCDRS PORTAbits.RA2
#define LCDPORT PORTB

#include <xc.h>
#include "fuses.h"
#include "mine_lcd.h"

void init(){
    PCONbits.OSCF=1; // INTOSC at 4 Mhz
    CMCONbits.CM=0b111; // All Comparators Off (All Pins are Digital)
    TRISA=0b00100000;
    TRISB=0b00000000;
    PORTA=0x00;
    PORTB=0x00;
}

void main() {
    init();
    lcdInit();
    lcdCommand(0x01);
    lcdString("CASINO MELINCUE");
    lcdCommand(0xC0);
    lcdString("& RESORT");
    while(1){}
}

