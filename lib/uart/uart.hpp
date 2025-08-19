#if !defined(UART_HPP)
#define UART_HPP

#include "stm32f4xx.h"

void uart_init(void);
void uart_write(char ch);
int uart_read(void);

#endif // UART_H
