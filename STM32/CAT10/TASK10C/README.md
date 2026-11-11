# CAT 10 - TASK 10C: Multi-Step IoT Provisioning Engine

## 1. Objective
Implement a non-blocking finite state machine (FSM) on the STM32F401RET6 to manage multi-step IoT device provisioning with the ESP8266 Wi-Fi modem, transitioning through ping, station mode configuration, AP connection, and IP verification.

## 2. Hardware Setup & Pin Mapping
| Interface | STM32 Pins | Function |
|---|---|---|
| **USART1** | `PA9` (TX), `PA10` (RX) | ESP8266 AT Command Link @ 115200 |
| **USART2** | `PA2` (TX), `PA3` (RX) | PC Debug Console @ 115200 |

## 3. Working Principle & FSM State Flow
1. **State Machine Definitions:**
   - `IOT_STATE_INIT`: Sends startup banner to PC console.
   - `IOT_STATE_TEST_AT`: Sends `AT\r\n` ping.
   - `IOT_STATE_SET_MODE`: Sends `AT+CWMODE=1\r\n`.
   - `IOT_STATE_JOIN_WIFI`: Transmits `AT+CWJAP="SNUC","snu12345"\r\n` and provides a 5-second non-blocking window for DHCP association.
   - `IOT_STATE_GET_IP`: Sends `AT+CIFSR\r\n` to confirm IP address assignment.
   - `IOT_STATE_READY`: Enters transparent passthrough mode for live telemetry streaming.
2. **Non-Blocking Architecture:** Uses `HAL_GetTick()` timestamps to time transitions between states, ensuring the microcontroller never blocks or stalls.

## 4. Circuit Diagram
![Circuit Diagram](circuit.png)

## 5. Output Verification & Inferences
- FSM steps through all 5 provisioning stages automatically upon boot.
- Console logs provide clear milestone indicators for each stage of network association.
