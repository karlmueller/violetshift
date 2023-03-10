// Copyright 2015-2016 Espressif Systems (Shanghai) PTE LTD
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
#ifndef _SOC_DPORT_REG_H_
#define _SOC_DPORT_REG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "interrupt_reg.h"
#include "system_reg.h"
#include "sensitive_reg.h"
#include "soc.h"

#define DPORT_DATE_REG SYSTEM_DATE_REG

#define TRACEMEM_MUX_BLK0_NUM                   19
#define TRACEMEM_MUX_BLK1_NUM                   20
#define TRACEMEM_BLK_NUM2ADDR(_n_)              (0x3FFB8000UL + 0x4000UL*((_n_)-4))

#ifndef __ASSEMBLER__
#include "dport_access.h"
#endif

#ifdef __cplusplus
}
#endif

#endif /*_SOC_DPORT_REG_H_ */
