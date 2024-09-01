/*
 * LCD_Program.c
 *
 *  Created on: Aug 1, 2024
 *      Author: Ahmed Saber
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/DIO/DIO_Config.h"
#include <util/delay.h>

#include "LCD_Interface.h"
#include "LCD_Private.h"
#include "LCD_Config.h"


void vLCD_init(void)
{
	/*1- initialize dio pins */
	vSet_Port_Direction(DATA_PORT,OUTPUT);
	vSet_Pin_Direction(RS_PORT,RS_PIN,OUTPUT);
	vSet_Pin_Direction(R_W_PORT,R_W_PIN,OUTPUT);
	vSet_Pin_Direction(E_PORT,E_PIN,OUTPUT);

	/*2- delay 30ms */
	_delay_ms(30);

	/*3- send command of function set*/
	/*
	 *
	 *
	 * N = 1, F = 0*/
	vLCD_sendCOMMAND(0b00111000);


	/*4- delay 40us*/
	_delay_ms(1);

	/*5- send command of Display ON/OFF control*/
	vLCD_sendCOMMAND(0b00001111);


	/*6- delay 40us*/
	_delay_ms(1);


	/*7- send command od Display CLear*/
	vLCD_sendCOMMAND(0b00000001);


	/*8- delay 2ms*/
	_delay_ms(3);


	/*9- send command entry mode settings*/
	vLCD_sendCOMMAND(0b00000110);

}

void vLCD_sendCOMMAND(u8 command)
{
	/*1- set RS pin to 0*/
	vSet_Pin_OUTPUTvalue(RS_PORT,RS_PIN,LOW);

	/*2- set R/W pin to 0*/
	vSet_Pin_OUTPUTvalue(R_W_PORT,R_W_PIN,LOW);


	/*3- add command to data port to be sent*/
	vSet_Port_OUTPUTvalue(DATA_PORT,command);


	/*4- trigger enable pin*/

	vSet_Pin_OUTPUTvalue(E_PORT,E_PIN,HIGH);
	_delay_ms(1);
	vSet_Pin_OUTPUTvalue(E_PORT,E_PIN,LOW);
	_delay_ms(1);
}

void vLCD_sendDATA(u8 data)
{
	/*1- set RS pin to 1*/
	vSet_Pin_OUTPUTvalue(RS_PORT,RS_PIN,HIGH);

	/*2- set R/W pin to 0*/
	vSet_Pin_OUTPUTvalue(R_W_PORT,R_W_PIN,LOW);


	/*3- add command to data port to be sent*/
	vSet_Port_OUTPUTvalue(DATA_PORT,data);


	/*4- trigger enable pin*/

	vSet_Pin_OUTPUTvalue(E_PORT,E_PIN,HIGH);
	_delay_ms(1);
	vSet_Pin_OUTPUTvalue(E_PORT,E_PIN,LOW);
	_delay_ms(1);
}

void vLCD_Send_String(u8 * str)
{
	u32 i=0;

	while(str[i] != '\0')
	{
		vLCD_sendDATA(str[i]);
		i++;
	}

}

void vLCD_SendINTNumber(s32 n){
    u8 str[10] ;
    u16 i=0, negativeFlag = 0;
    if(n<0){
        negativeFlag=1;
        n = -n;
    }
    do{
        str[i]= n % 10 +'0';
        i++;
        n/=10;
    }while(n>0);

    if(negativeFlag==1){
        str[i] = '-';
        i++;
    }
    //reverse the string
    for(int j=0; j<i/2; j++){
        char temp = str[j];
        str[j] = str[i-j-1];
        str[i-j-1] = temp;
    }
    str[i] ='\0';
    vLCD_Send_String(str);
}

void vLCD_Clear()
{
	vLCD_sendCOMMAND(0b00000001);
	_delay_ms(3);
}

void vLCD_GO_TO(u8 line ,u8 position )
{
	if(line==1)
	{
		vLCD_sendCOMMAND(0x80+position);
	}
	if(line==2)
	{
		vLCD_sendCOMMAND(0x80+0x40+position);
	}
}

void LCD_SendFloatNumber(f32 n, u16 ndigit ){
	u16 firstPart = n;
	f32 secondPart = n - (f32) firstPart;
	while(ndigit){
		secondPart *=10;
		ndigit--;
	}
	vLCD_SendINTNumber(firstPart);
	vLCD_sendDATA('.');
	vLCD_SendINTNumber(secondPart);

}

void displayOption(u8 option) {
	vLCD_Clear();
    switch (option) {
        case 1:
        	vLCD_Send_String("1) Control 2 LEDs");
            break;
        case 2:
        	vLCD_Send_String("2) Control LED intensity");
            break;
        case 3:
        	vLCD_Send_String("3) Control servo motor");
            break;
        case 4:
        	vLCD_Send_String("4) DC motor");
            break;
        case 5:
        	vLCD_Send_String("5) Potentiometer");
            break;
    }
}
void confirmSelection(u8 option) {
	vLCD_Clear();
	vLCD_Send_String("Selected Option: ");
	vLCD_Send_String(option + '0'); // Convert option to char and display
}
