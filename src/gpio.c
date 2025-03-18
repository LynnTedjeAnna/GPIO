//
// Created by Lynn Meindertsma on 17 Feb 2025.
//

#include "gpio.h"

void reset_GPIO(GPIO_TypeDef* port, uint8_t pin){
    port->MODER &= ~(0b11 << (pin*2));      // Reset mode register
    port->PUPDR &= ~(0b11 << (pin*2));      // Reset pull register
}

void config_GPIO(GPIO_TypeDef* port, uint8_t pin, GPIO_MODE_t mode, GPIO_PULL_t pull){
    reset_GPIO(port, pin);
    port->MODER |= mode << (pin*2);         // Set mode register
    port->PUPDR |= pull << (pin*2);         // Set pull register
}

void config_GPIO_af(GPIO_TypeDef* port, uint8_t pin, GPIO_PULL_t pull, uint8_t af){
    reset_GPIO(port, pin);
    port->MODER |= GPIO_alt_func << (pin*2);         // Set mode register
    port->PUPDR |= pull << (pin*2);                  // Set pull register
    if (pin < 8) {
        port->AFR[0] |= ((af & 0b1111) << (pin*4));  // Set alternate function register
    } else {
        port->AFR[1] |= ((af & 0b1111) << (pin*4));  // Set alternate function register
    }
}

// todo clock en/dis-able
void enable_GPIO_clock(RCC_TypeDef* port){
    // todo: switch case
    port->AHBENR |= (0b1 <<  17);
}

void GPIO_write(GPIO_TypeDef* port, uint8_t pin, uint8_t data){
    port->ODR &= ~(0x1 << pin);
    port->ODR |= (data << pin);
}

void GPIO_toggle(GPIO_TypeDef* port, uint8_t pin){
    port->ODR ^= 0x1 << pin;
}

uint8_t GPIO_read(GPIO_TypeDef* port, uint8_t pin){
    return ((port->IDR & (0x1 << pin)) >> pin);
}