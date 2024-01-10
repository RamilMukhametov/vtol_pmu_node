// Copyright (C) 2023 Dmitry Ponomarev <ponomarevda96@gmail.com>
// Distributed under the terms of the GPL v3 license, available in the file LICENSE.

#ifndef SRC_APPLICATION_PERIPHERY_LED_LED_HPP_
#define SRC_APPLICATION_PERIPHERY_LED_LED_HPP_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

class LedPeriphery {
public:
    static void reset();
    static void toggle();
};

#ifdef __cplusplus
}
#endif

#endif  // SRC_APPLICATION_PERIPHERY_LED_LED_HPP_
