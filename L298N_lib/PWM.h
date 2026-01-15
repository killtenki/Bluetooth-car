#ifndef Motor_speed_control_H
#define Motor_speed_control_H

#include "main.h"
typedef struct{
	TIM_HandleTypeDef* timer;
	uint32_t channel;
}PWM_Typedef;


#endif
