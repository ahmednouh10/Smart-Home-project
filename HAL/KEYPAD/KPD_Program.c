/*
 * KPD_Program.c
 *
 *  Created on: Aug 1, 2024
 *      Author: Ahmed Saber
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/DIO/DIO_Config.h"
#include "KPD_Interface.h"
#include "KPD_Private.h"
#include "KPD_Config.h"


u8 COL_PORT[4]={COL1_PORT,COL2_PORT,COL3_PORT,COL4_PORT};
u8 COL_PIN[4]={COL1_PIN,COL2_PIN,COL3_PIN,COL4_PIN};


u8 ROW_PORT[4]={ROW1_PORT,ROW2_PORT,ROW3_PORT,ROW4_PORT};
u8 ROW_PIN[4]={ROW1_PIN,ROW2_PIN,ROW3_PIN,ROW4_PIN};


u8 key_p[4][4]={
		{'1','2','3','4'},
		{'5','6','N','C'},
		{'-','-','-','-'},
		{'-','-','-','-'},

};

void vKEYPAD_init()
{
	/*
	u8 i = 0;
	for(i = 0; i < 4; i++)
	{
		vSet_Pin_Direction(COL_PORT[i],COL_PIN[i],OUTPUT);
		vSet_Pin_Direction(ROW_PORT[i],ROW_PIN[i],INPUT);
		vSet_Pin_OUTPUTvalue(COL_PORT[i],COL_PIN[i],HIGH);
		vSet_Pin_OUTPUTvalue(ROW_PORT[i],ROW_PIN[i],HIGH);
	}
	 */
	/*
	for(i = 0; i < 4; i++)
	{
		vSet_Pin_Direction(COL_PORT[i],COL_PIN[i],OUTPUT);
	}

	for(i = 0; i < 4; i++)
	{
		vSet_Pin_Direction(ROW_PORT[i],ROW_PIN[i],INPUT);
	}

	for(i = 0; i < 4; i++)
	{
		vSet_Pin_OUTPUTvalue(COL_PORT[i],COL_PIN[i],HIGH);
	}

	for(i = 0; i < 4; i++)
	{
		vSet_Pin_OUTPUTvalue(ROW_PORT[i],ROW_PIN[i],HIGH);
	}
	 */
	/*Columns are Output*/
	vSet_Pin_Direction(COL1_PORT,COL1_PIN,OUTPUT);
	vSet_Pin_Direction(COL2_PORT,COL2_PIN,OUTPUT);
	vSet_Pin_Direction(COL3_PORT,COL3_PIN,OUTPUT);
	vSet_Pin_Direction(COL4_PORT,COL4_PIN,OUTPUT);

	/*Rows are input*/
	vSet_Pin_Direction(ROW1_PORT,ROW1_PIN,INPUT);
	vSet_Pin_Direction(ROW2_PORT,ROW2_PIN,INPUT);
	vSet_Pin_Direction(ROW3_PORT,ROW3_PIN,INPUT);
	vSet_Pin_Direction(ROW4_PORT,ROW4_PIN,INPUT);

	/*ALL Columns written to 1*/
	vSet_Pin_OUTPUTvalue(COL1_PORT,COL1_PIN,HIGH);
	vSet_Pin_OUTPUTvalue(COL2_PORT,COL2_PIN,HIGH);
	vSet_Pin_OUTPUTvalue(COL3_PORT,COL3_PIN,HIGH);
	vSet_Pin_OUTPUTvalue(COL4_PORT,COL4_PIN,HIGH);

	/*Enable internal Pull up resistor*/
	vSet_Pin_OUTPUTvalue(ROW1_PORT,ROW1_PIN,HIGH);
	vSet_Pin_OUTPUTvalue(ROW2_PORT,ROW2_PIN,HIGH);
	vSet_Pin_OUTPUTvalue(ROW3_PORT,ROW3_PIN,HIGH);
	vSet_Pin_OUTPUTvalue(ROW4_PORT,ROW4_PIN,HIGH);
}


u8 u8KEY_PRESSED()
{
	u8 KEY= NO_KEY;

	/*u8 flag = 0;*/

	for(u8 col=0;col<4;col++)
	{
		vSet_Pin_OUTPUTvalue(COL_PORT[col],COL_PIN[col],LOW);
		for(u8 row=0;row<4;row++)
		{
			if(vGIT_PIN(ROW_PORT[row],ROW_PIN[row])==0)
			{
				KEY=key_p[row][col];
				/*flag = 1;*/
			}
			while(vGIT_PIN(ROW_PORT[row],ROW_PIN[row])==0);
		}

		vSet_Pin_OUTPUTvalue(COL_PORT[col],COL_PIN[col],HIGH);
		/*
		if(flag == 1)
			break;
		 */
	}
	return KEY;

}

u16 getNextOption(u16 currentOption) {
	u8 key = u8KEY_PRESSED();
	if (key == 'N') {
		currentOption++;
		if (currentOption > 5) {
			currentOption = 1;
		}
	} else if (key == 'C') { // Assuming 'C' is the key for 'Confirm'
		return 0xFF; // Return a special value to indicate confirmation
	}
	return currentOption;
}
