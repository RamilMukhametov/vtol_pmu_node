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

enum class Melody {
    ANOYING = 0,
    TOLERABLE = 1,
    BUMER = 2,

    MANUAL = 127,
};

class Buzzer {
public:
    Buzzer() = default;
    int8_t init();
    void process(uint8_t error_flag);
    static void buzzerSet(uint32_t frequency);

private:
    static const PwmPin pwm_pin = PwmPin::PWM_BUZZER;
    static Logger logger;
    void play_melody();
    void buzzerBeepBummer();
    void buzzerBeepAnnoying();
    void buzzerBeepTolerable();
    void update_params();
    static void callback(CanardRxTransfer* transfer);
    void publish_command();

    Melody error_melody;
    Melody arm_melody;

    uint32_t error_buzzer_frequency;
    uint32_t error_buzzer_sound_duration;
    uint32_t error_buzzer_period;

    static uint32_t buzzer_frequency;
    static uint32_t buzzer_duration;

    bool verbose;

    static uint32_t cmd_end_time_ms;

    static uint32_t crnt_time_ms;
    bool error_flag = false;
};

#ifdef __cplusplus
}
#endif

#endif  // SRC_MODULES_BUZZER_HPP_
