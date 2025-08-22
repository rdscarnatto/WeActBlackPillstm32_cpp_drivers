#include <stdio.h>
#include "uart.hpp"
#include "spi.hpp"
#include "gpio.hpp"

/*
*PB15 --> SPI2_MOSI
*PB14 --> SPI2_MISO
*PB13 --> SPI2_SCK
*PB12 --> SPI2_NSS
*ALT Funciton mode: 5

*/


int main()
{

  uart_init();

  /* code */
  return 0;
}
