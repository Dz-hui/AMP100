#ifndef __USART_H__
#define __USART_H__

#include "main.h"


extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart3;

#define _HAL_UART_CLK(uart)    __HAL_RCC_##uart##_CLK_ENABLE()


typedef enum{

    HAL_UART_BAUDRATE_9600,
    HAL_UART_BAUDRATE_115200,

}hal_uart_baudrate_t;

typedef enum{

    AL_UART_DATALEN_8,
    AL_UART_DATALEN_9,

}hal_uart_datalen_t;

typedef enum{
  
   HAL_UART_PARITY_NONE,
   HAL_UART_PARITY_EVEN,
   HAL_UART_PARITY_ODD,

}hal_uart_parity_t;


typedef enum{

    HAL_UART_STOP_1bit,
    HAL_UART_STOP_2bit,

}hal_uart_stopbit_t;


typedef enum{

    HAL_UART_MODE_TX,
    HAL_UART_MODE_RX,
    HAL_UART_MODE_TX_RX,

}hal_uart_mode_t;

typedef enum{

    HAL_UART_HWCONTROL_NONE,
    HAL_UART_HWCONTROL_CTS,
    HAL_UART_HWCONTROL_RTS,
    HAL_UART_HWCONTROL_RTS_CTS,

}hal_uart_hwctrl_t;

typedef enum{

    HAL_UART_OVERSIMPLING_8,
    HAL_UART_OVERSIMPLING_16,

}hal_uart_oversimpling_t;


typedef struct {
  
    hal_uart_baudrate_t  uart_baudrate;
    hal_uart_datalen_t uart_datalen;
    hal_uart_parity_t uart_parity;
    hal_uart_stopbit_t uart_stopbit;
    hal_uart_mode_t uart_mode;
    hal_uart_oversimpling_t uart_oversimpling;
    hal_uart_hwctrl_t uart_hwctrl;
    
}hal_uart_setting_t;

typedef struct{
    
    hal_uart_setting_t setting;
    UART_HandleTypeDef *huart;

}hal_uart_t;






void MX_USART1_UART_Init(void);
void MX_USART3_UART_Init(void);






#endif /* __USART_H__ */

