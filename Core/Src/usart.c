#include "usart.h"

extern hal_uart_t uart;

void set_uart_baudrate(hal_uart_t *drv,hal_uart_baudrate_t baudrate){
    
    switch(baudrate){
            
        case HAL_UART_BAUDRATE_9600:
          drv->huart->Init.BaudRate = 9600;
        break;
        case HAL_UART_BAUDRATE_115200:
          drv->huart->Init.BaudRate = 115200;
        break;
    }

}

void set_uart_datalen(hal_uart_t *drv,hal_uart_datalen_t datalen){

    switch(datalen){
        
        case HAL_UART_DATALEN_8:
          drv->huart->Init.WordLength = UART_WORDLENGTH_8B;
        break;
        case HAL_UART_DATALEN_9:
          drv->huart->Init.WordLength = UART_WORDLENGTH_9B;
        break; 
    }
}


void set_uart_parity(hal_uart_t *drv,hal_uart_parity_t parity){

    switch(parity){

        case HAL_UART_PARITY_NONE:
          drv->huart->Init.Parity = UART_PARITY_NONE;
        break;
        case HAL_UART_PARITY_EVEN:
          drv->huart->Init.Parity = UART_PARITY_EVEN;
        break;
        case HAL_UART_PARITY_ODD:
          drv->huart->Init.Parity = UART_PARITY_ODD;
        break;
    }

}

void set_uart_stopbit(hal_uart_t *drv,hal_uart_stopbit_t stopbit){
    
    switch(stopbit){
      
        case HAL_UART_STOP_1bit:
          drv->huart->Init.StopBits = UART_STOPBITS_1;
        break;
        case HAL_UART_STOP_2bit:
          drv->huart->Init.StopBits = UART_STOPBITS_2;
        break;
        
    }
}

void set_uart_mode(hal_uart_t *drv,hal_uart_mode_t mode){

  switch(mode){
      
      case HAL_UART_MODE_TX:
        drv->huart->Init.Mode = UART_MODE_TX;
      break;
      case HAL_UART_MODE_RX:
        drv->huart->Init.Mode = UART_MODE_RX;
      break;
      case HAL_UART_MODE_TX_RX:
        drv->huart->Init.Mode = UART_MODE_TX_RX;
      break;
  }

}


void set_uart_hwctrl(hal_uart_t *drv,hal_uart_hwctrl_t hwctrl){

    switch(hwctrl){
        case HAL_UART_HWCONTROL_NONE:
          drv->huart->Init.HwFlowCtl = UART_HWCONTROL_NONE;
        break;
        case HAL_UART_HWCONTROL_CTS:
          drv->huart->Init.HwFlowCtl = UART_HWCONTROL_CTS;
        break;
        case HAL_UART_HWCONTROL_RTS:
          drv->huart->Init.HwFlowCtl = UART_HWCONTROL_RTS;
        break;
        case HAL_UART_HWCONTROL_RTS_CTS:
          drv->huart->Init.HwFlowCtl = UART_HWCONTROL_RTS_CTS;
        break;
    }
}

void set_uart_oversimpling(hal_uart_t *drv,hal_uart_oversimpling_t oversimpling){

    switch(oversimpling){
        
        case HAL_UART_OVERSIMPLING_8:
          drv->huart->Init.OverSampling = UART_OVERSAMPLING_8;
        break;
        case HAL_UART_OVERSIMPLING_16:
          drv->huart->Init.OverSampling = UART_OVERSAMPLING_16;
        break;

    }

}

void my_uart_setting(hal_uart_t *drv,hal_uart_baudrate_t baudrate,hal_uart_datalen_t datalen,hal_uart_parity_t parity,hal_uart_stopbit_t stopbit,\
                     hal_uart_mode_t mode,hal_uart_hwctrl_t hw_hwctrl,hal_uart_oversimpling_t oversimpling){
    
    __HAL_RCC_USART1_CLK_ENABLE();
    set_uart_baudrate(drv,baudrate);
    set_uart_datalen(drv,datalen);
    set_uart_parity(drv,parity);
    set_uart_stopbit(drv,stopbit);
    set_uart_mode(drv,mode);
    set_uart_hwctrl(drv,hw_hwctrl);
    set_uart_oversimpling(drv,oversimpling);
    HAL_UART_Init((drv->huart));

}

/* USART1 init function */

void nvic_config(uint32_t nvic_prioritygroup,IRQn_Type IRQn, uint32_t PreemptPriority, uint32_t SubPriority){
    
    HAL_NVIC_SetPriorityGrouping(nvic_prioritygroup);
    HAL_NVIC_SetPriority(IRQn,PreemptPriority,SubPriority);
    HAL_NVIC_EnableIRQ(IRQn);

}

//void MX_USART1_UART_Init(void)
//{

//  /* USER CODE BEGIN USART1_Init 0 */

//  /* USER CODE END USART1_Init 0 */

//  /* USER CODE BEGIN USART1_Init 1 */

//  /* USER CODE END USART1_Init 1 */
//  huart1.Instance = USART1;
//  huart1.Init.BaudRate = 115200;
//  huart1.Init.WordLength = UART_WORDLENGTH_8B;
//  huart1.Init.StopBits = UART_STOPBITS_1;
//  huart1.Init.Parity = UART_PARITY_NONE;
//  huart1.Init.Mode = UART_MODE_TX_RX;
//  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
//  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
//  if (HAL_UART_Init(&huart1) != HAL_OK)
//  {
//    Error_Handler();
//  }


//}


//void MX_USART3_UART_Init(void)
//{

//  /* USER CODE BEGIN USART3_Init 0 */

//  /* USER CODE END USART3_Init 0 */

//  /* USER CODE BEGIN USART3_Init 1 */

//  /* USER CODE END USART3_Init 1 */
//  huart3.Instance = USART3;
//  huart3.Init.BaudRate = 115200;
//  huart3.Init.WordLength = UART_WORDLENGTH_8B;
//  huart3.Init.StopBits = UART_STOPBITS_1;
//  huart3.Init.Parity = UART_PARITY_NONE;
//  huart3.Init.Mode = UART_MODE_TX_RX;
//  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
//  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
//  if (HAL_UART_Init(&huart3) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  /* USER CODE BEGIN USART3_Init 2 */

//  /* USER CODE END USART3_Init 2 */

//}



int fputc(int ch, FILE *f){

    uint32_t temp = ch;
    HAL_UART_Transmit((uart.huart), (uint8_t *)&temp, 1, 1000); 
    return ch;

}


int fgetc(FILE *f)
{
    int ch;
    while (__HAL_UART_GET_FLAG((uart.huart), UART_FLAG_RXNE) == RESET);
    HAL_UART_Receive((uart.huart), (uint8_t *)&ch, 1, 0xFFFF);
    return (ch);
}




/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
