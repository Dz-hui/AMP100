#ifndef __GPIO_H__
#define __GPIO_H__


#include "main.h"

typedef GPIO_TypeDef gpio_def;

typedef enum{

#ifdef GPIOA
    HAL_GPIOA,
#endif   

#ifdef GPIOB
    HAL_GPIOB,
#endif  

#ifdef GPIOC    
    HAL_GPIOC,
#endif  

#ifdef GPIOD
    HAL_GPIOD,
#endif  

#ifdef GPIOE
    HAL_GPIOE,
#endif  

#ifdef GPIOF
    HAL_GPIOF,
#endif  

#ifdef GPIOG
    HAL_GPIOG,
#endif  

#ifdef GPIOH
    HAL_GPIOH,
#endif  

#ifdef GPIOI
    HAL_GPIOI,
#endif  

#ifdef GPIOJ
    HAL_GPIOJ,
#endif  

#ifdef GPIOK
    HAL_GPIOk,
#endif  

}hal_gpio_port_t;

typedef enum{
  
    HAL_GPIO_MODE_INPUT,
    HAL_GPIO_MODE_OUTPUT_PP,
    HAL_GPIO_MODE_OUTPUT_OD,
    HAL_GPIO_MODE_ANALOG,
    HAL_GPIO_MODE_IT_FALLING,
    HAL_GPIO_MODE_IT_RISING,
    HAL_GPIO_MODE_IT_RISING_FALLING,

}hal_gpio_mode_t;

typedef enum{

    HAL_GPIO_SPEED_LOW,
    HAL_GPIO_SPEED_MEDIUM,
    HAL_GPIO_SPEED_HIGH,

}hal_gpio_speed_t;

typedef enum{
    
    HAL_GPIO_NOPULL,
    HAL_GPIO_PULLDOWN,
    HAL_GPIO_PULLUP,

}hal_gpio_pull_t;

typedef enum{

    HAL_GPIO_AF_NULL,
    HAL_GPIO_AF0_RTC_50Hz ,
    HAL_GPIO_AF0_MCO,      
    HAL_GPIO_AF0_SWJ,      
    HAL_GPIO_AF1_TIM1,     
    HAL_GPIO_AF2_TIM3,     
    HAL_GPIO_AF2_TIM5,     
    HAL_GPIO_AF4_I2C1,     
    HAL_GPIO_AF4_I2C3,     
    HAL_GPIO_AF5_SPI2,     
    HAL_GPIO_AF6_SPI3,     
    HAL_GPIO_AF7_USART1,   
    HAL_GPIO_AF7_USART3,  
    HAL_GPIO_AF8_UART5,    
    HAL_GPIO_AF9_CAN1,     
    HAL_GPIO_AF10_OTG_FS,  
    HAL_GPIO_AF11_ETH,     
    HAL_GPIO_AF12_SDIO,    
    HAL_GPIO_AF15_EVENTOUT,
    HAL_GPIO_AF5_SPI5,     
    HAL_GPIO_AF8_UART7,    
    HAL_GPIO_AF12_FMC,     
    HAL_GPIO_AF14_LTDC,
    HAL_GPIO_AF9_TIM14,     
    HAL_GPIO_AF0_TAMPE,    
    HAL_GPIO_AF0_TRACE,     
    HAL_GPIO_AF1_TIM2,      
    HAL_GPIO_AF2_TIM4,      
    HAL_GPIO_AF3_TIM8,      
    HAL_GPIO_AF4_I2C2,      
    HAL_GPIO_AF5_SPI1,      
    HAL_GPIO_AF9_TIM13,     
    HAL_GPIO_AF9_TIM12,     
    HAL_GPIO_AF7_USART2,    
    HAL_GPIO_AF8_UART4,     
    HAL_GPIO_AF8_USART6,    
    HAL_GPIO_AF9_CAN2,      
    HAL_GPIO_AF10_OTG_HS,   
    HAL_GPIO_AF12_OTG_HS_FS,
    HAL_GPIO_AF13_DCMI,     
    HAL_GPIO_AF5_SPI4,      
    HAL_GPIO_AF5_SPI6,      
    HAL_GPIO_AF8_UART8,     
    HAL_GPIO_AF6_SAI1,     
    
}hal_gpio_af_t;

typedef struct {

    hal_gpio_mode_t gpio_mode;
    hal_gpio_speed_t gpio_speed;
    hal_gpio_pull_t gpio_pull;
    hal_gpio_af_t gpio_af;
    hal_gpio_port_t gpio_port;

}hal_gpio_setting_t;


typedef struct
{
    hal_gpio_setting_t gpio_setting;
    GPIO_InitTypeDef *GPIO_Init;

    void (*my_gpio_init)(gpio_def *);

}hal_gpio_t;


void set_gpio_clk(uint8_t num);
void set_gpio_mode(hal_gpio_t *drv,uint8_t num);
void set_gpio_speed(hal_gpio_t *drv,uint8_t num);
void set_gpio_pull(hal_gpio_t *drv,uint8_t num);
void set_gpio_af(hal_gpio_t *drv,uint8_t num);
void my_gpio_init(hal_gpio_t *drv,uint8_t gpio_clk,uint8_t gpio_mode,uint8_t gpio_speed,uint8_t goio_pull, uint8_t gpio_af,GPIO_TypeDef  *GPIOx);

void hal_gpio_init(hal_gpio_t *drv);


#endif /*__ GPIO_H__ */


