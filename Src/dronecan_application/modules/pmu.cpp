// Copyright (C) 2023 Dmitry Ponomarev <ponomarevda96@gmail.com>
// Distributed under the terms of the GPL v3 license, available in the file LICENSE.

#include "pmu.hpp"
#include "dronecan.h"
#include "main.h"
#include "params.hpp"
#include "string_params.hpp"
#include "string_params.hpp"
#include "storage.h"

VtolPmu::VtolPmu() {

}

int8_t VtolPmu::init() {
    return 0;
}

void VtolPmu::process() {
    uint32_t crnt_time_ms = HAL_GetTick();
    if (crnt_time_ms < _last_spin_time_ms + 1000) {
        return;
    }

    _spin_once();
}

void VtolPmu::_spin_once() {
    _last_spin_time_ms = HAL_GetTick();

    dronecan_equipment_battery_info_publish(&_battery_info, &_transfer_id);
    _transfer_id++;
}
