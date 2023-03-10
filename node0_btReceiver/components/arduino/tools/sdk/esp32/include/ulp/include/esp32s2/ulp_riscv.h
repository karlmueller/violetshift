// Copyright 2010-2020 Espressif Systems (Shanghai) PTE LTD
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

#pragma once
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include "esp_err.h"
#include "soc/soc.h"
#include "ulp_common.h"

/**
 * @brief Run the program loaded into RTC memory
 * @return  ESP_OK on success
 */
esp_err_t ulp_riscv_run(void);

/**
 * @brief Load ULP-RISC-V program binary into RTC memory
 *
 * Different than ULP FSM, the binary program has no special format, it is the ELF
 * file generated by RISC-V toolchain converted to binary format using objcopy.
 *
 * Linker script in components/ulp/ld/esp32s2.ulp.riscv.ld produces ELF files which
 * correspond to this format. This linker script produces binaries with load_addr == 0.
 *
 * @param program_binary pointer to program binary
 * @param program_size_bytes size of the program binary
 * @return
 *      - ESP_OK on success
 *      - ESP_ERR_INVALID_SIZE if program_size_bytes is more than 8KiB
 */
esp_err_t ulp_riscv_load_binary(const uint8_t* program_binary, size_t program_size_bytes);
