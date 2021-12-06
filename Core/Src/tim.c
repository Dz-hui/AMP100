#include "tim.h"


/*
void hal_tim_setting(void)
{
    __HAL_RCC_TIM5_CLK_ENABLE();

    TIM_HandleTypeDef htim;
    TIM_OC_InitTypeDef sConfig;
    htim.Init.ClockDivision= TIM_CLOCKDIVISION_DIV1;
    htim.Init.Period = 
    htim.Init.Prescaler = 
    htim.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
    htim.Init.RepetitionCounter = 0;
    HAL_TIM_Base_Init(&htim);

    sConfig.Pulse= 100;
    sConfig.OCPolarity= TIM_OCPOLARITY_HIGH;
    sConfig.OCMode= TIM_OCMODE_PWM1;
    sConfig.OCIdleState= TIM_OCIDLESTATE_RESET;
    sConfig.OCFastMode = TIM_OCFAST_DISABLE;
    
    HAL_TIM_PWM_ConfigChannel(&htim,&sConfig,TIM_CHANNEL_3);
}
*/


TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;
uint32_t duty_count = 0;
uint32_t fre_count =  0;
uint8_t mottor_state = 0;



void hal_base_tim_setting(void)
{
    /*************10ms进一次中断**************/
    hal_nvic_setting(TIM4_IRQn,4,1);
    __HAL_RCC_TIM4_CLK_ENABLE();
    
    htim1.Instance = TIM4;
    htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim1.Init.Period = 19400;
    htim1.Init.Prescaler = 45;
    htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
    htim1.Init.RepetitionCounter = 0;
    HAL_TIM_Base_Init(&htim1);
    HAL_TIM_Base_Start_IT(&htim1);

    /***********1us进一次中断******************/
    hal_nvic_setting(TIM7_IRQn,3,1);
    __HAL_RCC_TIM7_CLK_ENABLE();

    htim2.Instance = TIM7;
    htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim2.Init.Period = 1000;
    htim2.Init.Prescaler = 45;
    htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
    htim2.Init.RepetitionCounter = 0;
    HAL_TIM_Base_Init(&htim2);
    HAL_TIM_Base_Stop_IT(&htim2);

}

void hal_nvic_setting(IRQn_Type IRQn,uint32_t PreemptPriority, uint32_t SubPriority)
{
    HAL_NVIC_SetPriority(IRQn,PreemptPriority,SubPriority);
    HAL_NVIC_EnableIRQ(IRQn);
}


void hal_tim_set_reload(TIM_HandleTypeDef *htim,uint32_t reload)
{
    htim->Instance->ARR = reload;

}

uint32_t hal_tim_read_reload(TIM_HandleTypeDef *htim)
{
    uint32_t reload;
    reload = htim->Instance->ARR;
    return reload;
}

void TIM4_IRQHandler()
{
    HAL_TIM_IRQHandler(&htim1);

}

void TIM7_IRQHandler()
{
    HAL_TIM_IRQHandler(&htim2);

}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
   if(htim == (&htim1))
   {
        uint32_t tim1_reload = 0;
        switch(mottor_state){
            case mottor_on :
              HAL_TIM_Base_Start_IT(&htim2);
              tim1_reload =  hal_tim_read_reload(&htim1);
              tim1_reload ++;
              if(tim1_reload == 20000)
              {
                mottor_state = mottor_hold_on;
              }
              hal_tim_set_reload(&htim1,tim1_reload);
              break;  
            case mottor_off :
              HAL_TIM_Base_Start_IT(&htim2);
              tim1_reload =  hal_tim_read_reload(&htim1);
              tim1_reload --;
              if(tim1_reload == 0)
              {
                mottor_state = mottor_stop;
              }
              hal_tim_set_reload(&htim1,tim1_reload);
              break;  
            case mottor_hold_on :
              HAL_TIM_Base_Start_IT(&htim2);
              break;  
            case mottor_speed_up :
              HAL_TIM_Base_Start_IT(&htim2);
              tim1_reload =  hal_tim_read_reload(&htim1);
              tim1_reload ++;
              if(tim1_reload == 20500)
              {
                mottor_state = mottor_hold_on;
              }
              hal_tim_set_reload(&htim1,tim1_reload);
              break;  
            case mottor_speed_down :
              HAL_TIM_Base_Start_IT(&htim2);
              tim1_reload =  hal_tim_read_reload(&htim1);
              tim1_reload --;
              if(tim1_reload == 19500)
              {
                mottor_state = mottor_hold_on;
              }
              hal_tim_set_reload(&htim1,tim1_reload);
              break;  
            case mottor_stop :
              HAL_TIM_Base_Stop_IT(&htim2);
              break;

        }
        

        //printf("reload = %d\n",reload);
        //hal_tim_set_reload(&htim1,reload-1);  
      
   }

   else if(htim == (&htim2))
   {
       HAL_GPIO_WritePin(GPIOH, GPIO_PIN_12, GPIO_PIN_RESET);
       HAL_TIM_Base_Stop_IT(&htim2);
   }
}



