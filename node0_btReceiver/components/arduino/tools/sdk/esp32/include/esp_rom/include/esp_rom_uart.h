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

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define ESP_ROM_CDC_ACM_WORK_BUF_MIN 128

typedef enum {
    ESP_ROM_UART_0,
    ESP_ROM_UART_1,
    ESP_ROM_UART_USB
} esp_rom_uart_num_t;

/**
 * @brief Wait for UART TX FIFO is empty and all data has been sent out.
 *
 * @param uart_no UART port number
 */
void esp_rom_uart_tx_wait_idle(uint8_t uart_no);

/**
 * @brief Set clock source and baud rate for UART.
 *
 * @param uart_no UART port number
 * @param clock_hz Source clock (in Hz)
 * @param baud_rate Baud rate to set
 */
void esp_rom_uart_set_clock_baudrate(uint8_t uart_no, uint32_t clock_hz, uint32_t baud_rate);

/**
 * @brief Wait until UART TX FIFO is empty (i.e. flush TX FIFO)
 *
 * @param uart_no UART port number
 */
void esp_rom_uart_flush_tx(uint8_t uart_no);

/**
 * @brief Transmit one character to the console channel.
 *
 * @param c Character to send
 * @return
 *      - 0 on success
 *      - 1 on failure
 */
int esp_rom_uart_tx_one_char(uint8_t c);

/**
 * @brief Transmit one character to the console channel.
 * @note This function is a wrapper over esp_rom_uart_tx_one_char, it can help handle line ending issue by replacing '\n' with '\r\n'.
 *
 * @param c Character to send
 */
void esp_rom_uart_putc(char c);

/**
 * @brief Get one character from the console channel.
 *
 * @param c Where to store the character
 * @return
 *      - 0 on success
 *      - 1 on failure or no data available
 */
int esp_rom_uart_rx_one_char(uint8_t *c);

/**
 * @brief Get one line of string from console channel (line ending won't be stored in the buffer).
 *
 * @param str Where to store the string
 * @param max_len Maximum length of the buffer (including the NULL delimiter)
 * @return always return 0 when on success or wait in a loop for rx data
 */
int esp_rom_uart_rx_string(uint8_t *str, uint8_t max_len);

/**
 * @brief Set the UART port used by ets_printf.
 *
 * @param uart_no UART port number
 */
void esp_rom_uart_set_as_console(uint8_t uart_no);

/**
 * @brief Initialize the USB ACM UART
 * @note The ACM working memroy should be at least 128 bytes (ESP_ROM_CDC_ACM_WORK_BUF_MIN) in size.
 *
 * @param cdc_acm_work_mem Pointer to the work memroy used for CDC-ACM
 * @param cdc_acm_work_mem_len Length of work memory
 */
void esp_rom_uart_usb_acm_init(void *cdc_acm_work_mem, int cdc_acm_work_mem_len);

#ifdef __cplusplus
}
#endif
