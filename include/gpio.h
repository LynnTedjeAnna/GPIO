//
// Created by Lynn Meindertsma on 17 Feb 2025.
//

#ifndef GPIO_GPIO_H
#define GPIO_GPIO_H

#include "stm32f303xe.h"

typedef enum {
    GPIO_input =			0b00,
    GPIO_output =			0b01,
    GPIO_alt_func =			0b10,
    GPIO_analog =			0b11	// r
} GPIO_MODE_t;

typedef enum {
    GPIO_low_speed =		0b00,	// r
    GPIO_medium_speed =		0b01,
    GPIO_high_speed =		0b10,
    GPIO_very_high_speed =	0b11
} GPIO_SPEED_t;

typedef enum {
    GPIO_no_pull =			0b00,	// r
    GPIO_pull_up =			0b01,
    GPIO_pull_down =		0b10,
    GPIO_reserved =			0b11
} GPIO_PULL_t;

typedef enum {
    GPIO_push_pull =		0b0,	// r
    GPIO_open_drain =		0b1
} GPIO_OT_t;

/* Functions */
void reset_GPIO(GPIO_TypeDef* port, uint8_t pin);
void config_GPIO(GPIO_TypeDef* port, uint8_t pin, GPIO_MODE_t mode, GPIO_PULL_t pull);
void config_GPIO_af(GPIO_TypeDef* port, uint8_t pin, GPIO_PULL_t pull, uint8_t af);

void enable_GPIO_clock(RCC_TypeDef* port);                                              // todo research rcc ipv gpio
void disable_GPIO_clock(RCC_TypeDef* port);                                             // todo research rcc ipv gpio

void GPIO_write(GPIO_TypeDef* port, uint8_t pin, uint8_t data);
void GPIO_toggle(GPIO_TypeDef* port, uint8_t pin);
uint8_t GPIO_read(GPIO_TypeDef* port, uint8_t pin);

#endif //GPIO_GPIO_H
