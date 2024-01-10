// Copyright (C) 2023 Dmitry Ponomarev <ponomarevda96@gmail.com>
// Distributed under the terms of the GPL v3 license, available in the file LICENSE.

#include "periphery/led/led.hpp"
#include "main.h"


void LedPeriphery::reset() {
    HAL_GPIO_WritePin(INTERNAL_LED_1_GPIO_Port, INTERNAL_LED_1_Pin, GPIO_PIN_SET);
}

void LedPeriphery::toggle() {
    auto crnt_time_ms = HAL_GetTick();
    GPIO_PinState state = (crnt_time_ms % 1000 > 500) ? GPIO_PIN_SET : GPIO_PIN_RESET;

    HAL_GPIO_WritePin(INTERNAL_LED_1_GPIO_Port, INTERNAL_LED_1_Pin, state);
}
