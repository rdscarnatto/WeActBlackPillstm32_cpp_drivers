#include "spi.hpp"

void SPI_init(SPI_Handle_t *pSPIHandle)
{
  // Enable SPI clock
  SPI1_PCLK_EN();
  //
  // SPI_TypeDef *pSPIx = NULL;
}