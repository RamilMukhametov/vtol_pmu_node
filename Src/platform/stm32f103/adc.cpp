// Copyright (C) 2023 Dmitry Ponomarev <ponomarevda96@gmail.com>
// Distributed under the terms of the GPL v3 license, available in the file LICENSE.

#include "periphery/adc/adc.hpp"
#include "main.h"

extern ADC_HandleTypeDef hadc1;

int8_t AdcPeriphery::init() {
    if (HAL_ADCEx_Calibration_Start(&hadc1) != HAL_OK) {
        return -1;
    }

    uint8_t channels_amount = static_cast<uint8_t>(AdcChannel::ADC_NUMBER_OF_CNANNELS);
    if (HAL_ADC_Start_DMA(&hadc1, (uint32_t*)(void*)&_adc_raw, channels_amount) != HAL_OK) {
        return -1;
    }

    _is_adc_already_inited = true;
    return 0;
}

uint16_t AdcPeriphery::get(AdcChannel channel) {
    if (!_is_adc_already_inited || channel >= AdcChannel::ADC_NUMBER_OF_CNANNELS) {
        return 0;
    }

    return _adc_raw[static_cast<uint8_t>(channel)];
}
