#ifndef __BSP_STEP_MOTOR_INIT_H
#define __BSP_STEP_MOTOR_INIT_H

#include "stm32h7xx.h"
#include "stm32h7xx_hal.h"

//引脚定义
/*******************************************************/
//Motor 方向 
#define MOTOR_DIR_PIN                   GPIO_PIN_14   
#define MOTOR_DIR_GPIO_PORT             GPIOB                    
#define MOTOR_DIR_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOB_CLK_ENABLE()

//Motor 使能 
#define MOTOR_EN_PIN                    GPIO_PIN_15
#define MOTOR_EN_GPIO_PORT              GPIOB                       
#define MOTOR_EN_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOB_CLK_ENABLE()

//Motor 脉冲
#define MOTOR_PUL_PIN                   GPIO_PIN_6
#define MOTOR_PUL_GPIO_PORT             GPIOC
#define MOTOR_PUL_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOC_CLK_ENABLE()

/************************************************************/
#define HIGH GPIO_PIN_SET	      //高电平
#define LOW  GPIO_PIN_RESET	    //低电平

#define ON  HIGH	              //开
#define OFF LOW	                //关

#define CW 	LOW		              //顺时针
#define CCW HIGH      	        //逆时针

//控制使能引脚
/* 带参宏，可以像内联函数一样使用 */
#define MOTOR_EN(x)					HAL_GPIO_WritePin(MOTOR_EN_GPIO_PORT,MOTOR_EN_PIN,x)
#define MOTOR_PUL(x)				HAL_GPIO_WritePin(MOTOR_PUL_GPIO_PORT,MOTOR_PUL_PIN,x)
#define MOTOR_DIR(x)				HAL_GPIO_WritePin(MOTOR_DIR_GPIO_PORT,MOTOR_DIR_PIN,x)

#define MOTOR_EN_TOGGLE     HAL_GPIO_TogglePin(MOTOR_EN_GPIO_PORT,MOTOR_EN_PIN)


extern void stepper_Init(void);
extern void stepper_turn(int tim,float angle,float subdivide,uint8_t dir);
#endif /* __STEP_MOTOR_INIT_H */


