/*
 * main.c
 *
 * Created: 2018-03-10 오후 11:05:18
 * Author : kiki
 */ 

#ifndef F_CPU
#define F_CPU	16000000L
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "NOKIA5110.h"
#include "FONT_IMAGE.h"

#define DELAY	2000

int main(void)
{	
	N5110_Init();
			
    /* Replace with your application code */
    while (1)
    {				
		N5110_Clear();
		N5110_SetFont(SmallFont);
		N5110_PrintStr(N5110_MAX_WIDTH/2-(4.5*6), N5110_MAX_HEIGHT/2 - 4, "NOKIA5110", true);
		N5110_Update();
		_delay_ms(DELAY);
		
		N5110_Clear();
		N5110_SetFont(TinyFont);
		N5110_PrintStr(N5110_MAX_WIDTH/2-(4.5*4), N5110_MAX_HEIGHT/2 - 3, "NOKIA5110", true);
		N5110_Update();
		_delay_ms(DELAY);
		
		N5110_Clear();
		N5110_SetFont(MediumNumbers);
		N5110_PrintStr(N5110_MAX_WIDTH/2-(2.5*12), N5110_MAX_HEIGHT/2 - 8, "99-99", true);
		N5110_Update();
		_delay_ms(DELAY);
		
		N5110_Clear();
		N5110_SetFont(BigNumbers);
		N5110_PrintStr(N5110_MAX_WIDTH/2-(2.5*14), N5110_MAX_HEIGHT/2 - 12, "99-99", true);
		N5110_Update();
		_delay_ms(DELAY);
		
		N5110_Clear();
		N5110_SetFont(SmallFont);
		N5110_PrintStr(N5110_MAX_WIDTH/2-(4.5*6), N5110_MAX_HEIGHT/2 - 4, "NOKIA5110", true);
		N5110_Update();
		_delay_ms(DELAY);
			
		N5110_InvertDisplay(true);
		_delay_ms(DELAY);
		N5110_InvertDisplay(false);
		_delay_ms(DELAY);
	
		N5110_DrawHLine(0, N5110_MAX_HEIGHT/2 - 8, N5110_MAX_WIDTH, true);
		N5110_DrawHLine(0, N5110_MAX_HEIGHT/2 + 8, N5110_MAX_WIDTH, true);
		N5110_DrawVLine(0, N5110_MAX_HEIGHT/2 - 8, 16, true);
		N5110_DrawVLine(N5110_MAX_WIDTH-1, N5110_MAX_HEIGHT/2 - 8, 16, true);
		N5110_Update();
		_delay_ms(DELAY);
	
		N5110_DrawRect(0, N5110_MAX_HEIGHT/2 - 8, N5110_MAX_WIDTH-1, N5110_MAX_HEIGHT/2 + 8, false, false);	
		N5110_Update();
		_delay_ms(DELAY);
	
		N5110_Clear();
		N5110_Update();	
		
		for(int i = 0; i < N5110_MAX_WIDTH; i=i+5)
		{
			N5110_DrawLine(0, 0, i, N5110_MAX_HEIGHT-1, true);				
		}
		N5110_Update();
		_delay_ms(DELAY);
	
		N5110_Clear();	
		for(int i = 0; i < N5110_MAX_WIDTH; i=i+5)
		{
			N5110_DrawLine(0, N5110_MAX_HEIGHT-1, i, 0, true);		
		}
		N5110_Update();	
		_delay_ms(DELAY);
	
		N5110_Clear();
		for(int i = 0; i < N5110_MAX_WIDTH; i=i+5)
		{
			N5110_DrawLine(N5110_MAX_WIDTH-1, 0, i, N5110_MAX_HEIGHT-1, true);
		}
		N5110_Update();
		_delay_ms(DELAY);
		
		N5110_Clear();
		for(int i = 0; i < N5110_MAX_WIDTH; i=i+5)
		{
			N5110_DrawLine(N5110_MAX_WIDTH-1, N5110_MAX_HEIGHT-1, i, 0, true);
		}
		N5110_Update();
		_delay_ms(DELAY);	
		
		
		N5110_Clear();
		for(int i = 0; i < N5110_MAX_HEIGHT/2; i=i+2)
		{
			N5110_DrawRect(N5110_MAX_WIDTH/2-1.7*i,N5110_MAX_HEIGHT/2-1-i,N5110_MAX_WIDTH/2+1.7*i,N5110_MAX_HEIGHT/2+i, true, false);
			N5110_Update();
		}		
		_delay_ms(DELAY);	
		
		N5110_DrawRect(0, 0, N5110_MAX_WIDTH-1, N5110_MAX_HEIGHT-1, true, true);
		N5110_Update();
		_delay_ms(DELAY);			
		
		N5110_Clear();
		for(int i = 0; i < N5110_MAX_HEIGHT/2; i=i+2)
		{
			N5110_DrawCircle(N5110_MAX_WIDTH/2-1,N5110_MAX_HEIGHT/2-1, i, true, false);
			N5110_Update();
		}
		_delay_ms(DELAY);
		
		N5110_DrawCircle(N5110_MAX_WIDTH/2-1,N5110_MAX_HEIGHT/2-1, N5110_MAX_HEIGHT/2-1, true, true);
		N5110_Update();
		_delay_ms(DELAY);
		
		N5110_PrintStr(15, N5110_MAX_HEIGHT/2 - 4, "NOKIA5110", false);
		N5110_Update();
		_delay_ms(DELAY);
		
		N5110_Clear();
		N5110_DrawBitmap(0, 0, (uint8_t*)Bitmap, N5110_MAX_WIDTH, N5110_MAX_HEIGHT);
		N5110_Update();
		_delay_ms(DELAY);
    }
}

