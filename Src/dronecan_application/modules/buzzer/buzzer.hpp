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
    void buzzerSet(uint32_t frequency, uint32_t duration);

private:
    PwmPin pwm_pin;
    static Logger logger;
    void buzzerBeapBimmer();
    void buzzerBeapAnnoying();
    void buzzerBeapTolerable();
    void update_params();
    void callback(CanardRxTransfer* transfer);
    void publish_command();

    uint8_t error_melody;
    uint8_t arm_melody;

    uint32_t error_buzzer_frequency;
    uint32_t error_buzzer_duration;

    uint32_t buzzer_frequency;
    uint32_t buzzer_duration;

    bool verbose;

    static uint32_t ttl_current_cmd_ms;
    static uint16_t ttl_cmd;

    static uint32_t crnt_time_ms;
    bool error_flag = false;
};

#ifdef __cplusplus
}
#endif

#endif  // SRC_MODULES_BUZZER_HPP_
