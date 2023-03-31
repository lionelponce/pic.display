/* 
 * File:   mine_lcd.h
 * Author: Lionel Ponce
 * Title: Funciones para Manejo de LCD 16x1 a 16x4.
 * Created on 6 de noviembre de 2015, 19:59
 */

void lcdCommand(char Data){
	LCDRS=0;
        LCDEN=1;
	LCDPORT=Data;
        __delay_ms(20);
        LCDEN=0;
	LCDRS=0;
        LCDPORT=0x00;
}

void lcdData(char Data){
	LCDRS=1;
        LCDEN=1;
	LCDPORT=Data;
        __delay_ms(20);
        LCDEN=0;
	LCDRS=0;
	LCDPORT=0x00;
}

void lcdString(char Mensaje[]){
    char i;
    for(i=0; Mensaje[i]!= 0; i++) lcdData(Mensaje[i]);
}

void lcdInit(){
    lcdCommand(0x38); //8 Bits and 8x5 dots Character
    lcdCommand(0x0C); //Show Display and Cursor Off
    lcdCommand(0x06); //Increment DD Addres and Move Cursor to Right
    lcdCommand(0x01); //Clear Screen and Cursor Home
}
