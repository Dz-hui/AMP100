#ifndef __TIM__H
#define __TIM__H


#include "main.h"
#include "stm32f4xx_hal_tim.h"

void hal_nvic_setting(IRQn_Type IRQn,uint32_t PreemptPriority, uint32_t SubPriority);
void hal_tim_set_reload(TIM_HandleTypeDef *htim,uint32_t reload);
void hal_base_tim_setting(void);
uint32_t hal_tim_read_reload(TIM_HandleTypeDef *htim);

#endif/*__TIM__H*/