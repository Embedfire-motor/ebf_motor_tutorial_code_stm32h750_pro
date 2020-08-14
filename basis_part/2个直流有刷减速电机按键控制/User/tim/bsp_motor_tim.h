#ifndef __BSP_MOTOR_TIM_H
#define	__BSP_MOTOR_TIM_H

#include "stm32h7xx.h"

/* ��� 1 ��ض��� */
/*�궨��*/
#define PWM_TIM                        	TIM2
#define PWM_TIM_GPIO_AF                 GPIO_AF1_TIM2
#define PWM_TIM_CLK_ENABLE()  					__TIM2_CLK_ENABLE()

#define PWM_CHANNEL_1                   TIM_CHANNEL_1
#define PWM_CHANNEL_2                   TIM_CHANNEL_2

/* �ۼ� TIM_Period�������һ�����»����ж�*/		
/* ����ʱ����0������PWM_PERIOD_COUNT����ΪPWM_PERIOD_COUNT+1�Σ�Ϊһ����ʱ���� */
#define PWM_PERIOD_COUNT     (16000)


/* ͨ�ÿ��ƶ�ʱ��ʱ��ԴTIMxCLK = HCLK=168MHz */
/* �趨��ʱ��Ƶ��Ϊ=TIMxCLK/(PWM_PRESCALER_COUNT+1) */
#define PWM_PRESCALER_COUNT     (2)

/*PWM����*/
#define PWM_TIM_CH1_GPIO_CLK()             __HAL_RCC_GPIOA_CLK_ENABLE();
#define PWM_TIM_CH1_GPIO_PORT              GPIOA
#define PWM_TIM_CH1_PIN                    GPIO_PIN_15

#define PWM_TIM_CH2_GPIO_CLK()             __HAL_RCC_GPIOB_CLK_ENABLE();
#define PWM_TIM_CH2_GPIO_PORT              GPIOB
#define PWM_TIM_CH2_PIN                    GPIO_PIN_3

#define PWM_TIM_CH3_GPIO_CLK()             __HAL_RCC_GPIOB_CLK_ENABLE();
#define PWM_TIM_CH3_GPIO_PORT              GPIOB
#define PWM_TIM_CH3_PIN                    GPIO_PIN_10

/* ��� 2 ��ض��� */
/*�궨��*/
#define PWM2_TIM                        	TIM8
#define PWM2_TIM_GPIO_AF                 GPIO_AF3_TIM8
#define PWM2_TIM_CLK_ENABLE()  					__TIM8_CLK_ENABLE()

#define PWM2_CHANNEL_1                   TIM_CHANNEL_1
#define PWM2_CHANNEL_2                   TIM_CHANNEL_2

/* �ۼ� TIM_Period�������һ�����»����ж�*/		
/* ����ʱ����0������PWM_PERIOD_COUNT����ΪPWM_PERIOD_COUNT+1�Σ�Ϊһ����ʱ���� */
#define PWM2_PERIOD_COUNT     (16000)


/* ͨ�ÿ��ƶ�ʱ��ʱ��ԴTIMxCLK = HCLK=168MHz */
/* �趨��ʱ��Ƶ��Ϊ=TIMxCLK/(PWM_PRESCALER_COUNT+1) */
#define PWM2_PRESCALER_COUNT     (2)

/*PWM����*/
#define PWM2_TIM_CH1_GPIO_PORT           GPIOJ
#define PWM2_TIM_CH1_PIN                 GPIO_PIN_8

#define PWM2_TIM_CH2_GPIO_PORT           GPIOJ
#define PWM2_TIM_CH2_PIN                 GPIO_PIN_10

extern TIM_HandleTypeDef  TIM_TimeBaseStructure;
extern TIM_HandleTypeDef  TIM_TimeBaseStructure2;

extern void TIMx_Configuration(void);
extern void TIM1_SetPWM_pulse(uint32_t channel,int compare);
extern void TIMx_Configuration2(void);
extern void TIM1_SetPWM2_pulse(uint32_t channel,int compare);

#endif   /* __BSP_MOTOR_TIM_H */

