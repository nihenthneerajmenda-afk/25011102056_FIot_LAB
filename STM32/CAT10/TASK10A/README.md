# CAT 10 - TASK 10A: Dual-UART Transparent Bridge

## 1. Objective
Configure two independent hardware UART peripherals (USART1 and USART2) on the STM32F401RET6 to implement a bidirectional transparent bridge between a PC terminal emulator and a Wemos D1 Mini (ESP8266) Wi-Fi AT modem.

## 2. Hardware Setup & Pin Mapping
| Port | STM32 Pins | Baud Rate | Connected Device |
|---|---|---|---|
| **USART1** | `PA9` (TX), `PA10` (RX) | 115200-8-N-1 | Wemos D1 Mini (ESP8266 RX/TX) |
| **USART2** | `PA2` (TX), `PA3` (RX) | 115200-8-N-1 | PC ST-LINK Virtual COM Port |

## 3. Working Principle & Implementation Details
1. **Dual-UART Architecture:**
   - Allows the host PC to directly communicate with the ESP8266 AT firmware through the STM32 MCU.
2. **Bidirectional Forwarding:**
   - Checks for incoming bytes from PC (`USART2`): forwards immediately to ESP8266 (`USART1`).
   - Checks for incoming response bytes from ESP8266 (`USART1`): forwards immediately to PC (`USART2`).
3. **Non-Blocking Operation:** Both `HAL_UART_Receive` calls use a minimal 2 ms timeout, enabling seamless full-duplex pass-through without data dropping.

## 4. Circuit Diagram
![Circuit Diagram](circuit.png)

## 5. Output Verification & Inferences
- Typing `AT` in PuTTY returns `OK` from the ESP8266 modem.
- Querying `AT+GMR` displays the ESP8266 firmware version and SDK build information on the PC screen.
