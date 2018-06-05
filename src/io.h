#pragma once

#include <avr/io.h> 

void io_init();

void io_out_set_high();
void io_out_set_low();

uint8_t io_pc_is_enabled();
uint8_t io_pc_is_low();
uint8_t io_selected_option();

