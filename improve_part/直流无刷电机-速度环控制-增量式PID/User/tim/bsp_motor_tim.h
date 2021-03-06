#ifndef __BSP_MOTOR_TIM_H
#define	__BSP_MOTOR_TIM_H

#include "stm32h7xx.h"
#include ".\bldcm_control\bsp_bldcm_control.h"

/* 电机控旋转实现结构体 */

#define SPEED_FILTER_NUM      30    // 速度滤波次数

typedef struct
{
  int32_t timeout;            // 定时器更新计数
  float speed;                // 电机速度 rps（转/秒）
  int32_t enable_flag;        // 电机使能标志
  int32_t speed_group[SPEED_FILTER_NUM];
}motor_rotate_t;

/* 电机控制定时器 */
#define MOTOR_TIM           				      TIM8
#define MOTOR_TIM_CLK_ENABLE()  			    __TIM8_CLK_ENABLE()
extern TIM_HandleTypeDef  htimx_bldcm;

/* 累计 TIM_Period个后产生一个更新或者中断		
	当定时器从0计数到5599，即为5600次，为一个定时周期 */
#define PWM_PERIOD_COUNT     (5600)

#define PWM_MAX_PERIOD_COUNT    (PWM_PERIOD_COUNT - 100)

/* 定时器时钟源TIMxCLK = 2 * PCLK1  
					PCLK1 = HCLK / 4 
					=> TIMxCLK=HCLK/2=SystemCoreClock/2=240MHz
	 设定定时器频率为=TIMxCLK/(PWM_PRESCALER_COUNT+1)/PWM_PERIOD_COUNT = 14.28KHz*/
#define PWM_PRESCALER_COUNT     (3)

/* TIM8通道1输出引脚 */
#define MOTOR_OCPWM1_PIN           		    GPIO_PIN_8
#define MOTOR_OCPWM1_GPIO_PORT     		    GPIOJ
#define MOTOR_OCPWM1_GPIO_CLK_ENABLE() 	  __HAL_RCC_GPIOJ_CLK_ENABLE()
#define MOTOR_OCPWM1_AF					          GPIO_AF3_TIM8

/* TIM8通道2输出引脚 */
#define MOTOR_OCPWM2_PIN           		    GPIO_PIN_10
#define MOTOR_OCPWM2_GPIO_PORT     		    GPIOJ
#define MOTOR_OCPWM2_GPIO_CLK_ENABLE() 	  __HAL_RCC_GPIOJ_CLK_ENABLE()
#define MOTOR_OCPWM2_AF					          GPIO_AF3_TIM8

/* TIM8通道3输出引脚 */
#define MOTOR_OCPWM3_PIN           		    GPIO_PIN_0
#define MOTOR_OCPWM3_GPIO_PORT     		    GPIOK
#define MOTOR_OCPWM3_GPIO_CLK_ENABLE() 	  __HAL_RCC_GPIOK_CLK_ENABLE()
#define MOTOR_OCPWM3_AF					          GPIO_AF3_TIM8

/* TIM8通道1互补输出引脚 */
#define MOTOR_OCNPWM1_PIN            		  GPIO_PIN_9
#define MOTOR_OCNPWM1_GPIO_PORT      		  GPIOJ
#define MOTOR_OCNPWM1_GPIO_CLK_ENABLE()	  __HAL_RCC_GPIOJ_CLK_ENABLE()
#define MOTOR_OCNPWM1_AF					        GPIO_AF3_TIM8

/* TIM8通道2互补输出引脚 */
#define MOTOR_OCNPWM2_PIN            		  GPIO_PIN_11
#define MOTOR_OCNPWM2_GPIO_PORT      		  GPIOJ
#define MOTOR_OCNPWM2_GPIO_CLK_ENABLE()	  __HAL_RCC_GPIOJ_CLK_ENABLE()
#define MOTOR_OCNPWM2_AF					        GPIO_AF3_TIM8

/* TIM8通道3互补输出引脚 */
#define MOTOR_OCNPWM3_PIN            		  GPIO_PIN_1
#define MOTOR_OCNPWM3_GPIO_PORT      		  GPIOK
#define MOTOR_OCNPWM3_GPIO_CLK_ENABLE()	  __HAL_RCC_GPIOK_CLK_ENABLE()
#define MOTOR_OCNPWM3_AF					        GPIO_AF3_TIM8

#define TIM_COM_TS_ITRx                   TIM_TS_ITR3    // 内部触发配置(TIM8->ITR2->TIM4)

/* 霍尔传感器定时器 */
#define HALL_TIM           				      TIM4
#define HALL_TIM_CLK_ENABLE()  			    __TIM4_CLK_ENABLE()

extern TIM_HandleTypeDef htimx_hall;

/* 累计 TIM_Period个后产生一个更新或者中断		
	当定时器从0计数到4999，即为5000次，为一个定时周期 */
#define HALL_PERIOD_COUNT     (10000)

/* 定时器时钟源TIMxCLK = 2 * PCLK1  
					PCLK1 = HCLK / 4 
					=> TIMxCLK=HCLK/2=SystemCoreClock/2=240MHz
	 设定定时器频率为 = TIMxCLK / (PWM_PRESCALER_COUNT + 1) / PWM_PERIOD_COUNT = 10Hz
   周期 T = 100ms */
#define HALL_PRESCALER_COUNT     (2400)

/* TIM5 通道 1 引脚 */
#define HALL_INPUTU_PIN           		    GPIO_PIN_6
#define HALL_INPUTU_GPIO_PORT     		    GPIOB
#define HALL_INPUTU_GPIO_CLK_ENABLE() 	  __HAL_RCC_GPIOB_CLK_ENABLE()
#define HALL_INPUTU_AF					          GPIO_AF2_TIM4

/* TIM5 通道 2 引脚 */
#define HALL_INPUTV_PIN           		    GPIO_PIN_7
#define HALL_INPUTV_GPIO_PORT     		    GPIOB
#define HALL_INPUTV_GPIO_CLK_ENABLE() 	  __HAL_RCC_GPIOB_CLK_ENABLE()
#define HALL_INPUTV_AF					          GPIO_AF2_TIM4

/* TIM5 通道 3 引脚 */
#define HALL_INPUTW_PIN           		    GPIO_PIN_8
#define HALL_INPUTW_GPIO_PORT     		    GPIOB
#define HALL_INPUTW_GPIO_CLK_ENABLE() 	  __HAL_RCC_GPIOB_CLK_ENABLE()
#define HALL_INPUTW_AF					          GPIO_AF2_TIM4

#define HALL_TIM_IRQn                    TIM4_IRQn
#define HALL_TIM_IRQHandler              TIM4_IRQHandler

extern TIM_HandleTypeDef TIM_TimeBaseStructure;

void PWM_TIMx_Configuration(void);
void stop_pwm_output(void);
void start_pwm_output(void);
void set_pwm_pulse(uint16_t pulse);

void hall_enable(void);
void hall_disable(void);
void hall_tim_config(void);

float get_motor_speed(void);

#endif /* __BSP_MOTOR_TIM_H */

