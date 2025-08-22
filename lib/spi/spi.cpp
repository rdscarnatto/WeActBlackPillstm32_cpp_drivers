#include "spi.hpp"

void SPI_Init(SPI_Handle_t *pSPIHandle)
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
  tempreg |= pSPIHandle->SPI_Config.SPI_SclkSpeed << SPI_CR1_BR_Pos; 

  //4. Confiure the DFF
  tempreg |= pSPIHandle->SPI_Config.SPI_DFF << SPI_CR1_DFF_Pos;

  //5. Configure the CPOL
  tempreg |= pSPIHandle->SPI_Config.SPI_CPOL << SPI_CR1_CPOL_Pos;

  //6. Configure the CPHA
  tempreg |= pSPIHandle->SPI_Config.SPI_CPHA << SPI_CR1_CPHA_Pos;

  pSPIHandle->pSPIx->CR1 |= tempreg;

}

uint8_t SPI_GetFlagStatus(SPI_TypeDef *pSPIx, uint32_t FlagName){
  
  if (pSPIx->SR & FlagName)
  {
    return SET;
  }
  return RESET; 
}

void SPI_SendData(SPI_TypeDef *pSPIx, uint8_t *pTxBuffer, uint32_t len){

  while (len > 0)
  {
    //1. Wait until TXE is empty
    while(!(SPI_GetFlagStatus(pSPIx, SPI_SR_TXE) == RESET));
    //2. Check data frame format DFF
    if (pSPIx->CR1 & SPI_CR1_DFF)
    {
      //16 bit
      //1. Load the data into DR 
      pSPIx->DR = *((uint16_t*)pTxBuffer);
      len--;
      len--;
      (uint16_t*)pTxBuffer++;
    } else
    {
      //8 bit
      pSPIx->DR = *pTxBuffer;
      len--;
      pTxBuffer++;
    }
    
  }
  
}


