
// This is a test program for the uart library.

#include "uart.h"

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