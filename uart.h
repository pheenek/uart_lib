
#define F_CPU 16000000UL                // define the CPU speed. The MCU is running at 16MHz set by an external crystal

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

// define some macros
#define BAUD    9600                               // define baud
#define MYUBRR  ((F_CPU/16/BAUD)-1)                  // set baud rate value for UBRR

void USART_Init();

void USART_Transmit(unsigned char data);

unsigned char USART_Receive(void);

void sendString(char *data);

void readString(char myString[], uint8_t maxLength);
