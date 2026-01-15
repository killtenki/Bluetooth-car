#include "Motor_direction_control.h"
#include "L298N_motor_config.h"


extern TIM_HandleTypeDef htim2;

extern uint16_t Velocity;


Motor_Config_Typedef Motor_A;
Motor_Config_Typedef Motor_B;
	

void Car_control(Car_state state){
	switch(state){
		case Car_stop:
			control_motor(&Motor_A, Motor_Spin_STOP, Velocity);
			control_motor(&Motor_B, Motor_Spin_STOP, Velocity);
			break;
		case Car_forward:
			control_motor(&Motor_A, Motor_Spin_CW, Velocity);
			control_motor(&Motor_B, Motor_Spin_CW, Velocity);
			break;
		case Car_backward:
			control_motor(&Motor_A, Motor_Spin_CCW, Velocity);
			control_motor(&Motor_B, Motor_Spin_CCW, Velocity);			
			break;
		case Car_left:
			control_motor(&Motor_A, Motor_Spin_CW, Velocity);
			control_motor(&Motor_B, Motor_Spin_CCW, Velocity);
			break;
		case Car_right:
			control_motor(&Motor_A, Motor_Spin_CCW, Velocity);
			control_motor(&Motor_B, Motor_Spin_CW, Velocity);
			break;
	}
}

void Init(){

	Motor_Config(&Motor_A, GPIOA, GPIO_PIN_8, GPIOB, GPIO_PIN_15, &htim2, TIM_CHANNEL_1);
	Motor_Config(&Motor_B, GPIOB, GPIO_PIN_14, GPIOB, GPIO_PIN_13, &htim2, TIM_CHANNEL_2);
	Car_control(Car_stop);
}
