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

void set_gpio_mode(hal_gpio_t *drv,uint8_t num)
{
    switch(num)
    {
        case HAL_GPIO_MODE_INPUT:
            drv->gpio_setting.gpio_mode = GPIO_MODE_INPUT;
        break; 
        case HAL_GPIO_MODE_OUTPUT_PP:
            drv->gpio_setting.gpio_mode = GPIO_MODE_OUTPUT_PP;
        break; 
        case HAL_GPIO_MODE_OUTPUT_OD:
            drv->gpio_setting.gpio_mode = GPIO_MODE_OUTPUT_OD;
        break; 
        case HAL_GPIO_MODE_ANALOG:
            drv->gpio_setting.gpio_mode = GPIO_MODE_ANALOG;
        break; 
        case HAL_GPIO_MODE_IT_FALLING:
            drv->gpio_setting.gpio_mode = GPIO_MODE_IT_FALLING;
        break; 
        case HAL_GPIO_MODE_IT_RISING:
            drv->gpio_setting.gpio_mode = GPIO_MODE_IT_RISING;
        break; 
        case HAL_GPIO_MODE_IT_RISING_FALLING:
            drv->gpio_setting.gpio_mode = GPIO_MODE_IT_RISING_FALLING;
        break; 
    }
}

void set_gpio_speed(hal_gpio_t *drv,uint8_t num)
{
     switch(num)
     {
        case HAL_GPIO_SPEED_LOW:
            drv->gpio_setting.gpio_speed = GPIO_SPEED_LOW;
        break;
      case HAL_GPIO_SPEED_MEDIUM:
            drv->gpio_setting.gpio_speed = GPIO_SPEED_MEDIUM;
        break;
      case HAL_GPIO_SPEED_HIGH:
            drv->gpio_setting.gpio_speed = GPIO_SPEED_HIGH;
        break;        
     }
}

void set_gpio_pull(hal_gpio_t *drv,uint8_t num)
{
    switch(num)
    {
        case HAL_GPIO_NOPULL:
            drv->gpio_setting.gpio_pull = GPIO_NOPULL;
        break;
        case HAL_GPIO_PULLDOWN:
            drv->gpio_setting.gpio_pull = GPIO_PULLDOWN;
        break;
        case HAL_GPIO_PULLUP:
            drv->gpio_setting.gpio_pull = GPIO_PULLUP;
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
              drv->gpio_setting.gpio_af = GPIO_AF1_TIM1;
          break;   
          /*.........*/
     }
}


void my_gpio_init(hal_gpio_t *drv,uint8_t gpio_clk,uint8_t gpio_mode,uint8_t gpio_speed,uint8_t goio_pull, uint8_t gpio_af,GPIO_TypeDef  *GPIOx)
{
    set_gpio_clk(gpio_clk);
    set_gpio_mode(drv,gpio_mode);
    set_gpio_speed(drv,gpio_speed);
    set_gpio_pull(drv,goio_pull);
    set_gpio_af(drv,gpio_af);
    HAL_GPIO_Init(GPIOx,&(drv->GPIO_Init));
}


void hal_gpio_init(hal_gpio_t *drv)
{
    drv->my_gpio_init = hal_gpio_init;   
}


