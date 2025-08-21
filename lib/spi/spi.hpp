#if !defined(SPI_HPP_)
#define SPI_HPP_

#define SPI1_PCLK_EN() (RCC->APB2ENR |= (1 << 12))

#include "stm32f4xx.h"

typedef struct
{
  uint8_t SPI_DeviceMode;
  uint8_t SPI_BusConfig;
  uint8_t SPI_SclkSpeed;
  uint8_t SPI_DFF;
  uint8_t SPI_CPOL;
  uint8_t SPI_CPHA;
  uint8_t SPI_SSM;
} SPI_Config_t;

/*
 * Handle structure for SPIx peripheral
 */
typedef struct
{
  SPI_TypeDef *pSPIx;
  SPI_Config_t SPI_Config;
} SPI_Handle_t;

/*
 * @SPI_Device_mode
 */
#define SPI_MODE_MASTER 1
#define SPI_MODE_SLAVE 0
/*
 * @SPI_BusConfig
 */
#define SPI_BUS_CONFIG_FD 1
#define SPI_BUS_CONFIG_HD 2
#define SPI_BUS_CONFIG_S_RXONLY 3

/*
 * @SPI_SclkSpeed
 */
#define SPI_SCLK_SPEED_DIV2 0
#define SPI_SCLK_SPEED_DIV4 1
#define SPI_SCLK_SPEED_DIV8 2
#define SPI_SCLK_SPEED_DIV16 3
#define SPI_SCLK_SPEED_DIV32 4
#define SPI_SCLK_SPEED_DIV64 5
#define SPI_SCLK_SPEED_DIV128 6
#define SPI_SCLK_SPEED_DIV256 7

/*
 * @SPI_DFF
 */
#define SPI_DFF_8BITS 0
#define SPI_DFF_16BITS 1
/*
 * @CPOL
 */
#define SPI_CPOL_HIGH 1
#define SPI_CPOL_LOW 0

/*
 * @CPHA
 */
#define SPI_CPHA_HIGH 1
#define SPI_CPHA_LOW 0

/*
 * @SPI_SSM
 */
#define SPI_SSM_EN 1
#define SPI_SSM_DI 0



// Generic macros
#define ENABLE  1
#define DISABLE 0
#define SET ENABLE
#define RESET DISABLE
#define GPIO_PIN_SET  ENABLE
#define GPIO_PIN_RESET DISABLE


void SPI_Init(SPI_Handle_t *pSPIHandle);
void SPI_SendData(SPI_TypeDef *pSPIx, uint8_t *pTxBuffer, uint32_t len);

#endif // SPI_H_
