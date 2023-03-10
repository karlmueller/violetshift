// Copyright 2020 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#pragma once

#include <stdint.h>
#include "soc/soc_caps.h"

#if SOC_MPU_CONFIGURABLE_REGIONS_SUPPORTED
typedef void** mpu_region_table_t;
#endif

typedef enum {
    MPU_REGION_ILLEGAL,
#if SOC_MPU_REGION_RO_SUPPORTED
    MPU_REGION_RO,      // read-only
#endif
#if SOC_MPU_REGION_WO_SUPPORTED
    MPU_REGION_WO,      // write-only
#endif
    MPU_REGION_RW,      // read-write
    MPU_REGION_X,       // executable
    MPU_REGION_RWX      // read-write-executable
} mpu_access_t;
