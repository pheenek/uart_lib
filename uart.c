
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

// define some macros
#define BAUD    9600                               // define baud
#define MYUBRR  ((F_CPU/16/BAUD)-1)                  // set baud rate value for UBRR
// #define MYUBRR  51

// function to initialize UART
void USART_Init(){
    //set baudrate
    UBRR0H = (MYUBRR >> 8);
    UBRR0L = MYUBRR;

    //enable receiver and transmitter
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);

    //set frame fornat: 8 data
    UCSR0C = (3 << UCSZ00);
}

void USART_Transmit(unsigned char data){
    // wait for empty transmit buffer
    while(!(UCSR0A & (1 << UDRE0)));

    // put data into the buffer, sends the data
    UDR0 = data;
}

unsigned char USART_Receive(void){
    //wait for data to be received
    while(!(UCSR0A & (1 << RXC0)));

    //Get and return received data from buffer
    return UDR0;
    
}

void sendString(char *data){
    while(*data){
        USART_Transmit(*data);
        data++;
    }
    USART_Transmit('\r');
    USART_Transmit('\n');
    
}

int main(){
    USART_Init();
    DDRB |= 1 << PINB0;
    char *hi = "hello";
    char myData[10];

    while(1){
        // USART_Transmit('b');
        sprintf(myData, "sent: %s", hi);
        sendString(myData);
        PORTB ^= 1 << PINB0;
        _delay_ms(1000);
    }
    
}
