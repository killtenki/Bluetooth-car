#ifndef Motor_direction_control_H
#define Motor_direction_control_H

#include "main.h"

extern uint16_t Velocity;

typedef enum{
	Car_stop,
	Car_forward,
	Car_backward,
	Car_left,
	Car_right
}Car_state;

void Init(void);
void Car_control(Car_state state);
#endif 
