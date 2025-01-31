// Copyright (C) 2023 Dmitry Ponomarev <ponomarevda96@gmail.com>
// Distributed under the terms of the GPL v3 license, available in the file LICENSE.

#ifndef SRC_PERIPHERY_ADC_ADC_HPP_
#define SRC_PERIPHERY_ADC_ADC_HPP_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum class AdcChannel : uint8_t {
    ADC_VIN                 = 0,
    ADC_GATE_2              = 1,
    ADC_CRNT                = 2,
    ADC_GATE_3              = 3,
    ADC_GATE_4              = 4,
    ADC_TEMPERATURE         = 5,
    ADC_VERSION             = 6,
    ADC_NUMBER_OF_CNANNELS  = 7,
};

class AdcPeriphery {
public:
    static int8_t init();
    static uint16_t get(AdcChannel channel);
private:
    static inline bool _is_adc_already_inited = false;
};

#ifdef __cplusplus
}
#endif

#endif  // SRC_PERIPHERY_ADC_ADC_HPP_