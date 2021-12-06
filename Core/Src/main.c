#include "main.h"



void SystemClock_Config(void);
void MX_FREERTOS_Init(void);

extern uint8_t mottor_state ;
hal_gpio_t gpio;
extern TIM_HandleTypeDef htim1;


int main(void)
{
    static uint8_t key_state = 0;
    static uint8_t key_runing = 0;
    
    uint32_t reload = 0;
    HAL_Init();
    SystemClock_Config();
    /*KEY INIT*/
    my_gpio_init(&gpio,0,HAL_GPIOA,HAL_GPIO_MODE_INPUT,HAL_GPIO_SPEED_MEDIUM,HAL_GPIO_NOPULL,HAL_GPIO_AF_NULL,GPIOA);
    my_gpio_init(&gpio,13,HAL_GPIOC,HAL_GPIO_MODE_INPUT,HAL_GPIO_SPEED_MEDIUM,HAL_GPIO_NOPULL,HAL_GPIO_AF_NULL,GPIOC);
    /*LED INIT*/
    my_gpio_init(&gpio,11,HAL_GPIOH,HAL_GPIO_MODE_OUTPUT_PP,HAL_GPIO_SPEED_MEDIUM,HAL_GPIO_NOPULL,HAL_GPIO_AF_NULL,GPIOH);
    HAL_GPIO_WritePin(GPIOH,GPIO_PIN_11,SET);
    /*USART INIT*/
    my_gpio_init(&gpio,9,HAL_GPIOA,HAL_GPIO_MODE_AF_PP,HAL_GPIO_SPEED_MEDIUM,HAL_GPIO_NOPULL,HAL_GPIO_AF7_USART1,GPIOA);
    my_gpio_init(&gpio,10,HAL_GPIOA,HAL_GPIO_MODE_AF_PP,HAL_GPIO_SPEED_MEDIUM,HAL_GPIO_NOPULL,HAL_GPIO_AF7_USART1,GPIOA);
    MX_USART1_UART_Init();
    /*TIM INIT*/
    hal_base_tim_setting();
    printf("初始化完成\n");
    
    while (1){
        
        key_state = key_scanf();
        reload = hal_tim_read_reload(&htim1);
		    printf("\nreload = %d\n",reload);

        
        if(key_state == KEY1_ON)
        {
            if(key_runing ==4)
            {
              key_runing = 0;
            }
            key_runing++ ;

            switch(key_runing){
              case key_state_1: 
                hal_led_on(GPIOH,GPIO_PIN_11);
                mottor_state = mottor_on;
                if(reload >= 20000)
                {
                    mottor_state = mottor_hold_on;
                    hal_tim_set_reload(&htim1,20000);
                }
                break;
              case key_state_4: 
                mottor_state = mottor_off;
                if(reload <= 1)
                {
                    mottor_state = mottor_stop;
                    hal_tim_set_reload(&htim1,0);
                }
                break;
              case key_state_2: 
                hal_led_toggle(GPIOH,GPIO_PIN_11);
                mottor_state = mottor_speed_up;
                if(reload >= 21000)
                {
                    mottor_state = mottor_hold_on;
                    hal_tim_set_reload(&htim1,21000);
                }
                break;
              case key_state_3: 
                mottor_state = mottor_speed_down;
                if(reload <= 19000)
                {
                    mottor_state = mottor_hold_on;
                    hal_tim_set_reload(&htim1,19000);
                }
                break;
              default:
                break;        
            }

          
        }
                  
        
    }

}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 15;
  RCC_OscInitStruct.PLL.PLLN = 216;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
