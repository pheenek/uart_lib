# AVR UART library
The AVR UART library seeks to put together all the common AVR UART functionality so that it can be accessible as simple function calls.
The functions within the library are:
* USART_Init - Initializes the UART at a baudrate of 9600 and using 8 data bits
* USART_Transmit - transmit a single character by placing it onto the data buffer
* USART_Receive - read and return a single character from the data buffer
* sendString - accepts a string as a parameter and transmits it
