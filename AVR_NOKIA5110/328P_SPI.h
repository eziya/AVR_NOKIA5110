/*
 * _328P_SPI.h
 *
 * Created: 2018-02-19 오후 9:02:12
 *  Author: kiki
 */ 


#ifndef __328P_SPI_H_
#define __328P_SPI_H_

#include <avr/io.h>
#include <util/delay.h>

#define SPI_DDR		DDRB
#define SPI_PORT	PORTB

#define SPI_SS		PB2
#define SPI_MOSI	PB3
#define SPI_MISO	PB4
#define SPI_SCK		PB5

void SPI_Init(void);
uint8_t SPI_Rx();
void SPI_Tx(uint8_t data);
void SPI_RxBuffer(uint8_t *buffer, uint8_t length);
void SPI_TxBuffer(uint8_t *buffer, uint8_t length);
void SPI_Select(void);
void SPI_Deselect(void);

#endif /* __328P_SPI_H_ */