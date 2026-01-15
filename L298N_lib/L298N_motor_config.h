#ifndef L298N_motor_config_H
#define L298N_motor_config_H

#include "main.h"
#include "PWM.h"
#include "Motor_direction_control.h"

typedef struct{
	GPIO_TypeDef* port;
	uint16_t pin;
}Motor_Pin_Typedef;

typedef enum{
	Motor_Spin_CW,
	Motor_Spin_CCW,
	Motor_Spin_STOP	
}Motor_State;	

typedef struct{
	Motor_Pin_Typedef In_p;
	Motor_Pin_Typedef In_n;
	PWM_Typedef Enable;
	uint16_t speed;
}Motor_Config_Typedef;

void control_motor(Motor_Config_Typedef *motor, Motor_State State, uint16_t Velocity);

void Motor_Config(Motor_Config_Typedef *motor,
									GPIO_TypeDef* port_p,
									uint16_t pin_p,
									GPIO_TypeDef* port_n,
									uint16_t pin_n, 
									TIM_HandleTypeDef* timer, 
									uint32_t channel);



#endif 
