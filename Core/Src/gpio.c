#include "gpio.h"


void set_gpio_clk(uint8_t num)
{
    switch(num){
        case HAL_GPIOA:
#ifdef GPIOA       
            __HAL_RCC_GPIOA_CLK_ENABLE();
#endif
        break;
        case HAL_GPIOB:
#ifdef GPIOB       
            __HAL_RCC_GPIOB_CLK_ENABLE();
#endif
        break;
        case HAL_GPIOC:
#ifdef GPIOC       
            __HAL_RCC_GPIOC_CLK_ENABLE();
#endif
        break;
        case HAL_GPIOD:
#ifdef GPIOD       
            __HAL_RCC_GPIOD_CLK_ENABLE();
#endif
        break;
        case HAL_GPIOE:
#ifdef GPIOE       
            __HAL_RCC_GPIOE_CLK_ENABLE();
#endif
        break;
        case HAL_GPIOF:
#ifdef GPIOF       
            __HAL_RCC_GPIOF_CLK_ENABLE();
#endif
        break;
        case HAL_GPIOG:
#ifdef GPIOG       
            __HAL_RCC_GPIOG_CLK_ENABLE();
#endif
        break;
        case HAL_GPIOH:
#ifdef GPIOH       
            __HAL_RCC_GPIOH_CLK_ENABLE();
#endif
        break; 
        case HAL_GPIOI:    
#ifdef GPIOI       
            __HAL_RCC_GPIOI_CLK_ENABLE();
#endif
        break; 
        case HAL_GPIOJ: 
#ifdef GPIOJ       
            __HAL_RCC_GPIOJ_CLK_ENABLE();
#endif
        break; 
        case HAL_GPIOk: 
#ifdef GPIOK       
            __HAL_RCC_GPIOK_CLK_ENABLE();
#endif
        break;                                                                   
    } 
}


void set_gpio_pin(hal_gpio_t *drv,uint8_t num)
{
    switch(num){
        case 1:
          drv->GPIO_Init.Pin = HAL_GPIO_PIN(1);
        break;  
        case 2:
          drv->GPIO_Init.Pin = HAL_GPIO_PIN(2);
        break;
        case 3:
          drv->GPIO_Init.Pin = HAL_GPIO_PIN(3);
        break;
        case 4:
          drv->GPIO_Init.Pin = HAL_GPIO_PIN(4);
        break;
        case 5:
          drv->GPIO_Init.Pin = HAL_GPIO_PIN(5);
        break;
        case 6:
          drv->GPIO_Init.Pin = HAL_GPIO_PIN(6);
        break;
        case 7:
          drv->GPIO_Init.Pin = HAL_GPIO_PIN(7);
        break;
        case 8:
          drv->GPIO_Init.Pin = HAL_GPIO_PIN(8);
        break;
        case 9:
          drv->GPIO_Init.Pin = HAL_GPIO_PIN(9);
        break;
        case 10:
          drv->GPIO_Init.Pin = HAL_GPIO_PIN(10);
        break;
        case 11:
          drv->GPIO_Init.Pin = HAL_GPIO_PIN(11);
        break;
        case 12:
          drv->GPIO_Init.Pin = HAL_GPIO_PIN(12);
        break;
        case 13:
          drv->GPIO_Init.Pin = HAL_GPIO_PIN(13);
        break;
        case 14:
          drv->GPIO_Init.Pin = HAL_GPIO_PIN(14);
        break;
        case 15:
          drv->GPIO_Init.Pin = HAL_GPIO_PIN(15);
        break;

    }
    
}



void set_gpio_mode(hal_gpio_t *drv,uint8_t num)
{
    switch(num)
    {
        case HAL_GPIO_MODE_INPUT:
            drv->GPIO_Init.Mode = GPIO_MODE_INPUT;
        break; 
        case HAL_GPIO_MODE_OUTPUT_PP:
            drv->GPIO_Init.Mode = GPIO_MODE_OUTPUT_PP;
        break; 
        case HAL_GPIO_MODE_OUTPUT_OD:
            drv->GPIO_Init.Mode = GPIO_MODE_OUTPUT_OD;
        break; 
        case HAL_GPIO_MODE_AF_OD:
            drv->GPIO_Init.Mode = GPIO_MODE_AF_OD;
        break; 
        case HAL_GPIO_MODE_AF_PP:
            drv->GPIO_Init.Mode = GPIO_MODE_AF_PP;
        break; 
        case HAL_GPIO_MODE_ANALOG:
            drv->GPIO_Init.Mode = GPIO_MODE_ANALOG;
        break; 
        case HAL_GPIO_MODE_IT_FALLING:
            drv->GPIO_Init.Mode = GPIO_MODE_IT_FALLING;
        break; 
        case HAL_GPIO_MODE_IT_RISING:
            drv->GPIO_Init.Mode = GPIO_MODE_IT_RISING;
        break; 
        case HAL_GPIO_MODE_IT_RISING_FALLING:
            drv->GPIO_Init.Mode = GPIO_MODE_IT_RISING_FALLING;
        break; 
    }
}

void set_gpio_speed(hal_gpio_t *drv,uint8_t num)
{
     switch(num)
     {
        case HAL_GPIO_SPEED_LOW:
            drv->GPIO_Init.Speed = GPIO_SPEED_LOW;
        break;
      case HAL_GPIO_SPEED_MEDIUM:
            drv->GPIO_Init.Speed = GPIO_SPEED_MEDIUM;
        break;
      case HAL_GPIO_SPEED_HIGH:
            drv->GPIO_Init.Speed= GPIO_SPEED_HIGH;
        break;        
     }
}  

void set_gpio_pull(hal_gpio_t *drv,uint8_t num)
{
    switch(num)
    {
        case HAL_GPIO_NOPULL:
            drv->GPIO_Init.Pull = GPIO_NOPULL;
        break;
        case HAL_GPIO_PULLDOWN:
            drv->GPIO_Init.Pull = GPIO_PULLDOWN;
        break;
        case HAL_GPIO_PULLUP:
            drv->GPIO_Init.Pull = GPIO_PULLUP;
        break;
    }  
}

void set_gpio_af(hal_gpio_t *drv,uint8_t num)
{
     switch(num)
     {
          case HAL_GPIO_AF_NULL:
          break;    
          case HAL_GPIO_AF1_TIM2:
                drv->GPIO_Init.Alternate= GPIO_AF1_TIM1;
          break; 
          case HAL_GPIO_AF7_USART1:
                drv->GPIO_Init.Alternate= GPIO_AF7_USART1;
          break;  

          /*.........*/
     }
}


void my_gpio_init(hal_gpio_t *drv,uint8_t gpio_pin,uint8_t gpio_clk,uint8_t gpio_mode,uint8_t gpio_speed,uint8_t goio_pull, uint8_t gpio_af,GPIO_TypeDef  *GPIOx)
{
    set_gpio_clk(gpio_clk);
    set_gpio_pin(drv,gpio_pin);
    set_gpio_mode(drv,gpio_mode);
    set_gpio_speed(drv,gpio_speed);
    set_gpio_pull(drv,goio_pull);
    set_gpio_af(drv,gpio_af);
    HAL_GPIO_Init(GPIOx,&(drv->GPIO_Init));

}



    
void hal_led_gpio_init(void) {
	
    GPIO_InitTypeDef GPIO_Init; 
	
	__HAL_RCC_GPIOH_CLK_ENABLE();
	GPIO_Init.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_Init.Pin = GPIO_PIN_11;
	GPIO_Init.Pull = GPIO_NOPULL;
	GPIO_Init.Speed = GPIO_SPEED_FREQ_MEDIUM;
    HAL_GPIO_Init(GPIOH, &GPIO_Init);

}