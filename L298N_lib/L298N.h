#ifndef L298N_H
#define L298N_H

#include "main.h"

#define high GPIO_PIN_SET
#define low GPIO_PIN_RESET


#define p_left GPIO_PIN_8
#define n_left GPIO_PIN_15
#define p_right GPIO_PIN_14
#define n_right GPIO_PIN_13

#define p_left_port GPIOA
#define n_left_port GPIOB
#define p_right_port GPIOB
#define n_right_port GPIOB

#define EnableA TIM_CHANNEL_1
#define EnableB TIM_CHANNEL_2
#define EnableA_port GPIOA
#define EnableB_port GPIOA

#define State_port GPIOB
#define State GPIO_PIN_12

extern uint8_t Rdata;
extern volatile uint8_t soft_start;
extern uint32_t	time_update;
extern uint8_t acceleration; //= 50
extern volatile uint16_t speed;
extern volatile uint16_t target_speed ; //= 4800

void L298N_Init(void);
void soft_start_motor(void);
#endif
