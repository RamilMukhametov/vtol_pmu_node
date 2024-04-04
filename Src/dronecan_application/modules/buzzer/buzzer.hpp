// Copyright (C) 2024 Anastasiia Stepanova <asiiapine@gmail.com>
// Distributed under the terms of the GPL v3 license, available in the file LICENSE.

#ifndef SRC_MODULES_BUZZER_HPP_
#define SRC_MODULES_BUZZER_HPP_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "dronecan.h"
#include "main.h"
#include "params.hpp"
#include "storage.h"
#include "periphery/pwm/pwm.hpp"
#include "uavcan/equipment/indication/BeepCommand.h"

#include "../../logger.hpp"

class Buzzer {
public:
    Buzzer();
    int8_t init();
    void process(uint8_t error_flag);
    static void buzzerSet(uint32_t frequency);

private:
    static const PwmPin pwm_pin = PwmPin::PWM_BUZZER;
    static Logger logger;
    void buzzerBeepBummer();
    void buzzerBeepAnnoying();
    void buzzerBeepTolerable();
    void update_params();
    static void callback(CanardRxTransfer* transfer);
    void publish_command();

    uint8_t error_melody;
    uint8_t arm_melody;

    uint32_t error_buzzer_frequency;
    uint32_t error_buzzer_sound_duration;
    uint32_t error_buzzer_period;

    static uint32_t buzzer_frequency;
    static uint32_t buzzer_duration;

    bool verbose;

    static uint32_t cmd_end_time_ms;
    // static uint16_t ttl_cmd;

    static uint32_t crnt_time_ms;
    bool error_flag = false;
};

#ifdef __cplusplus
}
#endif

#endif  // SRC_MODULES_BUZZER_HPP_
