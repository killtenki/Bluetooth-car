#include "L298N_motor_config.h"

void control_motor(Motor_Config_Typedef *motor, Motor_State State, uint16_t Velocity){
	switch(State){
		case Motor_Spin_CW:
			HAL_GPIO_WritePin(motor->In_p.port, motor->In_p.pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(motor->In_n.port, motor->In_n.pin, GPIO_PIN_RESET);
			__HAL_TIM_SET_COMPARE(motor->Enable.timer, motor->Enable.channel, Velocity);
			break;
		
		case Motor_Spin_CCW:
			HAL_GPIO_WritePin(motor->In_p.port, motor->In_p.pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(motor->In_n.port, motor->In_n.pin, GPIO_PIN_SET);
			__HAL_TIM_SET_COMPARE(motor->Enable.timer, motor->Enable.channel, Velocity);
			break;
		
		case Motor_Spin_STOP:
			HAL_GPIO_WritePin(motor->In_p.port, motor->In_p.pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(motor->In_n.port, motor->In_n.pin, GPIO_PIN_RESET);
			break;
	}
}

void Motor_Config(Motor_Config_Typedef *motor, GPIO_TypeDef* port_p, uint16_t pin_p, GPIO_TypeDef* port_n, uint16_t pin_n, TIM_HandleTypeDef* timer, uint32_t channel){
	motor->In_p.port = port_p;
	motor->In_p.pin = pin_p;
	motor->In_n.port = port_n;
	motor->In_n.pin = pin_n;
	motor->Enable.timer = timer;
	motor->Enable.channel = channel;
	HAL_TIM_PWM_Start(motor->Enable.timer, motor->Enable.channel);
}




