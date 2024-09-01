/*
 * TIMER_Program.c
 *
 *  Created on: Aug 5, 2024
 *      Author: sohas
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "TIMER_Config.h"
#include "TIMER_Interface.h"
#include "TIMER_Private.h"

void TIMER0_init(void){
	/*MODE SELECT*/
	switch(TIMER0_Mode){
	case TIMER0_NORMAL_MODE:
		CLEAR_BIT(TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
		/*ENABLE OVERFLOW INTRRUPET*/
		TIMER0_IntrrupetEnable_OV();

		break;
	case TIMER0_PHASECORRECT_MODE:
		SET_BIT(TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
		break;
	case TIMER0_CTC_MODE:
		CLEAR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		/*ENABLE COMPARE MATCH INTRRUPET*/
		TIMER0_IntrrupetEnable_OC();
		break;
	case TIMER0_FASTPWM_MODE:
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
	default:
		break;
	}


	/*SET INTI VALUE*/
	TIMER0_Preload(TIMER0_INITIAL_VALUE);
}

void TIMER0_Start(void){
	/*SELECT PRESCALER*/
	switch(TIMER0_Prescaler){
	case TIMER0_SCALER_1:
		SET_BIT(TCCR0,CS00);
		break;
	case TIMER0_SCALER_1024:
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS02);
		break;
	case TIMER0_SCALER_256:
		SET_BIT(TCCR0,CS02);
		break;
	case TIMER0_SCALER_64:
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		break;
	case TIMER0_SCALER_8:
		SET_BIT(TCCR0,CS01);
		break;
	case EXTERNAL_RISING:
		SET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;
	case EXTERNALl_FALLING:
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;
	default:
		break;

	}
}


void TIMER0_FAST_PWM_MODE(void)
{
	switch(TIMER0_PWM_MODE)
	{
	case disconnected:
		CLEAR_BIT(TCCR0 , COM00);
		CLEAR_BIT(TCCR0 , COM01);
		break;
	case nin_inverting:
		CLEAR_BIT(TCCR0 , COM00);
		SET_BIT(TCCR0 , COM01);
		break;
	case inverting:
		SET_BIT(TCCR0 , COM00);
		SET_BIT(TCCR0 , COM01);
		break;

	}
}

void TIMER0_IntrrupetEnable_OV(){
	SET_BIT(TIMSK,TOIE0);
}

void TIMER0_IntrrupetDisable_OV(){
	CLEAR_BIT(TIMSK,TOIE0);
}



void TIMER0_IntrrupetEnable_OC(){
	SET_BIT(TIMSK,OCIE0);
}

void TIMER0_IntrrupetDisable_OC(){
	CLEAR_BIT(TIMSK,OCIE0);
}



void TIMER0_Stop(void){
	TCCR0=0X00;
}


void TIMER0_Preload(u8 preload){
	TCNT0=preload;
}


void TIMER0_OC_Value(u8 value){
	OCR0=value;
}

// TIMER2
void TIMER2_init(void){
	/*MODE SELECT*/
	switch(TIMER2_Mode){
	case TIMER2_NORMAL_MODE:
		CLEAR_BIT(TCCR2,WGM20);
		CLEAR_BIT(TCCR2,WGM21);
		/*ENABLE OVERFLOW INTRRUPET*/
		TIMER2_IntrrupetEnable_OV();

		break;
	case TIMER2_PHASECORRECT_MODE:
		SET_BIT(TCCR2,WGM20);
		CLEAR_BIT(TCCR2,WGM21);
		break;
	case TIMER0_CTC_MODE:
		CLEAR_BIT(TCCR2,WGM20);
		SET_BIT(TCCR2,WGM21);
		/*ENABLE COMPARE MATCH INTRRUPET*/
		TIMER2_IntrrupetEnable_OC();
		break;
	case TIMER2_FASTPWM_MODE:
		SET_BIT(TCCR2,WGM20);
		SET_BIT(TCCR2,WGM21);
		break;
	default:
		break;
	}


	/*SET INTI VALUE*/
	TIMER0_Preload(TIMER0_INITIAL_VALUE);
}

void TIMER2_Start(void){
	/*SELECT PRESCALER*/
	switch(TIMER2_Prescaler){
	case TIMER2_SCALER_1:
		SET_BIT(TCCR2,CS20);
		CLEAR_BIT(TCCR2,CS21);
		CLEAR_BIT(TCCR2,CS22);
		break;
	case TIMER2_SCALER_8:
		CLEAR_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		CLEAR_BIT(TCCR2,CS22);
		break;
	case TIMER2_SCALER_32:
		SET_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		CLEAR_BIT(TCCR2,CS22);
		break;
	case TIMER2_SCALER_64:
		CLEAR_BIT(TCCR2,CS20);
		CLEAR_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);
		break;
	case TIMER2_SCALER_128:
		SET_BIT(TCCR2,CS20);
		CLEAR_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);
		break;
	case TIMER2_SCALER_256:
		CLEAR_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);
		break;
	case TIMER2_SCALER_1024:
		SET_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);
		break;
	default:
		break;

	}
}


void TIMER2_FAST_PWM_MODE(void)
{
	switch(TIMER2_PWM_MODE)
	{
	case disconnected:
		CLEAR_BIT(TCCR2 , COM20);
		CLEAR_BIT(TCCR2 , COM21);
		break;
	case nin_inverting:
		CLEAR_BIT(TCCR2 , COM20);
		SET_BIT(TCCR2 , COM21);
		break;
	case inverting:
		SET_BIT(TCCR2 , COM20);
		SET_BIT(TCCR2 , COM21);
		break;

	}
}

void TIMER2_IntrrupetEnable_OV(){
	SET_BIT(TIMSK,TOIE2);
}

void TIMER2_IntrrupetDisable_OV(){
	CLEAR_BIT(TIMSK,TOIE2);
}



void TIMER2_IntrrupetEnable_OC(){
	SET_BIT(TIMSK,OCIE2);
}

void TIMER2_IntrrupetDisable_OC(){
	CLEAR_BIT(TIMSK,OCIE2);
}



void TIMER2_Stop(void){
	TCCR2=0X00;
}


void TIMER2_Preload(u8 preload){
	TCNT2=preload;
}


void TIMER2_OC_Value(u8 value){
	OCR2=value;
}




/***********************************************TIMER1*******************/


void vTIMER1_INIT(void)
{

#if TIMER1_MODE==TIMER1_NORMAL_MODE
	CLEAR_BIT(TCCR1A,WGM10);
	CLEAR_BIT(TCCR1A,WGM11);
	CLEAR_BIT(TCCR1B,WGM12);
	CLEAR_BIT(TCCR1B,WGM13);
#elif TIMER1_MODE==TIMER1_CTC_ICR_TOP_MODE
	CLEAR_BIT(TCCR1A,WGM10);
	CLEAR_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);

#elif TIMER1_MODE==TIMER1_CTC_OCRA_TOP_MODE

	CLEAR_BIT(TCCR1A,WGM10);
	CLEAR_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	CLEAR_BIT(TCCR1B,WGM13);
#elif  TIMER1_MODE==TIMER1_FASTPWM_ICR_TOP_MODE
	CLEAR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
#elif  TIMER1_MODE==TIMER1_FASTPWM_OCRA_TOP_MODE
	SET_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
#endif


}


void Timer1_OCRA1Mode(u8 oc1a_mode)
{
	switch (oc1a_mode)
	{
	case OCRA1_DISCONNECTED:
		CLEAR_BIT(TCCR1A,COM1A0);
		CLEAR_BIT(TCCR1A,COM1A1);
		break;

	case ORA1_NON_INVERTING:
		CLEAR_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
		break;
	case OCA1_INVERTING:
		SET_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
		break;
	}
}
void Timer1_OCRB1Mode(u8 oc1b_mode)
{
	switch (oc1b_mode)
	{
	case OCRB1_DISCONNECTED:
		CLEAR_BIT(TCCR1A,COM1B0);
		CLEAR_BIT(TCCR1A,COM1B1);
		break;

	case ORB1_NON_INVERTING:
		CLEAR_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
		break;
	case OCB1_INVERTING:
		SET_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
		break;
	}
}


void vTIMER1_START(void)
{
	TCCR1B=TCCR1B&0b11111000;
	TCCR1B=TCCR1B|TIMER1_PRESCALLER;
}

void vTIMER1_STOP(void)
{
	CLEAR_BIT(TCCR1B,0);
	CLEAR_BIT(TCCR1B,1);
	CLEAR_BIT(TCCR1B,2);
}

void vTIMER1_preload(u8 preload)
{
	TCNT1=preload;
}

void vTIMER1_Compare_OCR1A(u16 OCRA)
{
	OCR1A=OCRA;
}
void vTIMER1_Compare_OCRB1(u16 OCRB)
{
	OCR1B=OCRB;
}

void vTIMER1_ICR1(u16 ICR)
{
	ICR1=ICR;
}
void Timer1_InputCaptureEdge(u8 ICU_Edge_type_edge)
{
	if(ICU_Edge_type_edge==ICU_Edge_type_RISING)
		SET_BIT(TCCR1B,ICES1);

	else if(ICU_Edge_type_edge==ICU_Edge_type_RISING)
		CLEAR_BIT(TCCR1B,ICES1);
}


void Timer1_ICR_InterruptEnable(void)
{
	SET_BIT(TIMSK,TICIE1);
}
void Timer1_ICR_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,TICIE1);
}
void Timer1_OVF_InterruptEnable(void)
{
	SET_BIT(TIMSK,TOIE1);
}
void Timer1_OVF_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,TOIE1);
}
void Timer1_OCA_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE1A);
}
void Timer1_OCA_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,OCIE1A);
}
void Timer1_OCB_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE1B);
}
void Timer1_OCB_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,OCIE1B);
}

