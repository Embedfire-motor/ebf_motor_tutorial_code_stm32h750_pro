#ifndef __BSP_ENCOEDER_H
#define	__BSP_ENCOEDER_H

#include "stm32h7xx.h"

/* 定时器选择 */
#define ENCODER_TIM                            TIM3
#define ENCODER_TIM_CLK_ENABLE()  				     __HAL_RCC_TIM3_CLK_ENABLE()

/* 定时器溢出值 */		
#define ENCODER_TIM_PERIOD                     65535
/* 定时器预分频值 */
#define ENCODER_TIM_PRESCALER                  1      

/* 定时器中断 */
#define ENCODER_TIM_IRQn                       TIM3_IRQn
#define ENCODER_TIM_IRQHandler                 TIM3_IRQHandler

/* 编码器接口引脚 */
#define ENCODER_TIM_CH1_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOA_CLK_ENABLE()
#define ENCODER_TIM_CH1_GPIO_PORT              GPIOA
#define ENCODER_TIM_CH1_PIN                    GPIO_PIN_6
#define ENCODER_TIM_CH1_GPIO_AF                GPIO_AF2_TIM3

#define ENCODER_TIM_CH2_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOB_CLK_ENABLE()
#define ENCODER_TIM_CH2_GPIO_PORT              GPIOB
#define ENCODER_TIM_CH2_PIN                    GPIO_PIN_5
#define ENCODER_TIM_CH2_GPIO_AF                GPIO_AF2_TIM3

/* 编码器接口倍频数 */
#define ENCODER_MODE                           TIM_ENCODERMODE_TI12

/* 编码器接口输入捕获通道相位设置 */
#define ENCODER_IC1_POLARITY                   TIM_ICPOLARITY_FALLING
#define ENCODER_IC2_POLARITY                   TIM_ICPOLARITY_FALLING

/* 编码器物理分辨率 */
#define ENCODER_RESOLUTION                     600

/* 经过倍频之后的总分辨率 */
#if ((ENCODER_MODE == TIM_ENCODERMODE_TI1) || (ENCODER_MODE == TIM_ENCODERMODE_TI2))
  #define ENCODER_TOTAL_RESOLUTION             (ENCODER_RESOLUTION * 2)  /* 2倍频后的总分辨率 */
#else
  #define ENCODER_TOTAL_RESOLUTION             (ENCODER_RESOLUTION * 4)  /* 4倍频后的总分辨率 */
#endif

extern __IO int16_t encoder_overflow_count;
extern TIM_HandleTypeDef TIM_EncoderHandle;

void Encoder_Init(void);

#endif   /* __BSP_ENCODER_H */

