#include "L298N.h"

extern UART_HandleTypeDef huart1;
extern TIM_HandleTypeDef htim2;




uint8_t Rdata;
volatile uint8_t soft_start;
uint32_t	time_update;
uint8_t acceleration = 50;
volatile uint16_t speed;
volatile uint16_t target_speed = 4800;




void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if(huart->Instance == USART1){
		switch(Rdata){
			case 'U':
				target_speed = 2000;
				break;
			case 'I':
				target_speed = 3000;
				break;
			case 'O':
				target_speed = 4800;
				break;
			case 'W':
				HAL_GPIO_WritePin(p_left_port, p_left, high );
				HAL_GPIO_WritePin(p_right_port, p_right, high );
				HAL_GPIO_WritePin(n_left_port, n_left, low );
				HAL_GPIO_WritePin(n_right_port, n_right, low );
				soft_start = 1;
				break;
			case 'S':
				HAL_GPIO_WritePin(p_left_port, p_left, low );
				HAL_GPIO_WritePin(p_right_port, p_right, low );
				HAL_GPIO_WritePin(n_left_port, n_left, high );
				HAL_GPIO_WritePin(n_right_port, n_right, high );
				soft_start = 1;
				break;
			case 'D':
				HAL_GPIO_WritePin(p_left_port, p_left, low );
				HAL_GPIO_WritePin(p_right_port, p_right, high );
				HAL_GPIO_WritePin(n_left_port, n_left, high );
				HAL_GPIO_WritePin(n_right_port, n_right, low );
				soft_start = 1;
				break;
			case 'A':
				HAL_GPIO_WritePin(p_left_port, p_left, high );
				HAL_GPIO_WritePin(p_right_port, p_right, low );
				HAL_GPIO_WritePin(n_left_port, n_left, low );
				HAL_GPIO_WritePin(n_right_port, n_right, high );
				soft_start = 1;
				break;
			default:
				HAL_GPIO_WritePin(p_left_port, p_left, low );
				HAL_GPIO_WritePin(p_right_port, p_right, low );
				HAL_GPIO_WritePin(n_left_port, n_left, low );
				HAL_GPIO_WritePin(n_right_port, n_right, low );
				soft_start = 0;
				speed = 0;
				break;
		}
		HAL_UART_Receive_IT(&huart1, &Rdata, 1);
	}
}

void soft_start_motor(){
	if(HAL_GetTick() - time_update > 10 && soft_start == 1){
		time_update = HAL_GetTick();
		if(speed <= target_speed){
			speed = speed + acceleration;
			__HAL_TIM_SET_COMPARE(&htim2, EnableA, speed);
			__HAL_TIM_SET_COMPARE(&htim2, EnableB, speed);
		}
		else{
			speed = target_speed;
		}
	}
}

void L298N_Init() {
    HAL_UART_Receive_IT(&huart1, (uint8_t*)&Rdata, 1);
    HAL_TIM_PWM_Start(&htim2, EnableA);
    HAL_TIM_PWM_Start(&htim2, EnableB);
}
