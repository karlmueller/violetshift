// Copyright 2018-2019 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _dsp_common_H_
#define _dsp_common_H_
#include <stdint.h>
#include <stdbool.h>
#include "dsp_err.h"
#include "esp_idf_version.h"
#include "soc/cpu.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief      check power of two
 * The function check if the argument is power of 2.
 * The implementation use ANSI C and could be compiled and run on any platform
 *
 * @return
 *      - true if x is power of two
 *      - false if no
 */
bool dsp_is_power_of_two(int x);


/**
 * @brief      Power of two
 * The function return power of 2 for values 2^N.
 * The implementation use ANSI C and could be compiled and run on any platform
 *
 * @return
 *      - power of two
 */
int dsp_power_of_two(int x);

#ifdef __cplusplus
}
#endif

// esp_cpu_get_ccount function is implemented in IDF 4.1 and later
#if ESP_IDF_VERSION >= ESP_IDF_VERSION_VAL(4, 1, 0)
#define dsp_get_cpu_cycle_count  esp_cpu_get_ccount
#else
#define dsp_get_cpu_cycle_count  xthal_get_ccount
#endif

#endif // _dsp_common_H_