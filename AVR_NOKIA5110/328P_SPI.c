/*
 * _328P_SPI.c
 *
 * Created: 2018-02-19 오후 9:02:26
 *  Author: kiki
 */ 

#ifndef F_CPU
#define F_CPU	16000000
#endif

#include "328P_SPI.h"

void SPI_Init(void)
{		
	/* MOSI, SCK, SS Output */	
	SPI_DDR |= _BV(SPI_MOSI) | _BV(SPI_SCK) | _BV(SPI_SS);
	
	/* Deselect SS */
	SPI_Deselect();
	
	/* MISO Input + Pullup */
	SPI_DDR &= ~_BV(SPI_MISO);
	SPI_PORT |= _BV(SPI_MISO);
			
	/* Master mode + Enable, F_CPU/4 =  4MHz */	
	SPCR |= (_BV(MSTR) | _BV(SPE));	
}

uint8_t SPI_Rx()
{	
	SPDR = 0x00;		
	loop_until_bit_is_set(SPSR, SPIF);
	
	return SPDR;
}

void SPI_Tx(uint8_t data)
{		
	SPDR = data;
	loop_until_bit_is_set(SPSR, SPIF);		
}

void SPI_RxBuffer(uint8_t *buffer, uint8_t length)
{
	for(int i = 0; i < length; i++)
	{
		buffer[i] = SPI_Rx();
	}
}

void SPI_TxBuffer(uint8_t *buffer, uint8_t length)
{
	for(int i = 0; i < length; i++)
	{
		SPI_Tx(buffer[i]);
	}	
}

void SPI_Select()
{
	SPI_PORT &= ~_BV(SPI_SS);	
}

void SPI_Deselect()
{
	SPI_PORT |= _BV(SPI_SS);		
}