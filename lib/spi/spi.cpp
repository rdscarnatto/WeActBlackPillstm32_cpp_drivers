#include "spi.hpp"

void SPI_init(SPI_Handle_t *pSPIHandle)
{
  // Enable SPI clock
  SPI1_PCLK_EN();
  
  // Configure SPI_CR1 register
  uint32_t tempreg = 0;

  //1. Configure the device mode (MSTR of SPI_CR1)
  tempreg |= pSPIHandle->SPI_Config.SPI_DeviceMode << 2;

  //2. Configure de BusConfig
  if (pSPIHandle->SPI_Config.SPI_BusConfig == SPI_BUS_CONFIG_FD)
  {
    tempreg &= ~(1 << 15);
  }else if (pSPIHandle->SPI_Config.SPI_BusConfig == SPI_BUS_CONFIG_HD)
  {
    tempreg |= (1 << 15);
  }else if (pSPIHandle->SPI_Config.SPI_BusConfig == SPI_BUS_CONFIG_S_RXONLY){
    tempreg &= ~(1 << 15);
    tempreg |= (1 << 10);
  }
  //3. Configure serial clock speed (baudrate)
  tempreg |= pSPIHandle->SPI_Config.SPI_SclkSpeed << 3; 

  //4. Confiure the DFF
  tempreg |= pSPIHandle->SPI_Config.SPI_DFF << 11;

  //5. Configure the CPOL
  tempreg |= pSPIHandle->SPI_Config.SPI_CPOL << 1;

  //6. Configure the CPHA
  tempreg |= pSPIHandle->SPI_Config.SPI_CPHA << 0;

  pSPIHandle->pSPIx->CR1 |= tempreg;

}