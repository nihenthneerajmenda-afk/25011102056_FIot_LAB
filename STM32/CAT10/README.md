# CAT 10: STM32-Wemos Wi-Fi Modem Interface Using AT Commands

## Experiment Overview
- **Target Platform:** STM32 NUCLEO-F401RE + Wemos D1 Mini (ESP8266)
- **Objective:** Interface the STM32 host microcontroller with an ESP8266 Wi-Fi modem over serial UART using AT commands, configure Station Mode, connect to the campus Wi-Fi network (`SNUC`), and query the assigned IP address.

---

## Active Subtasks
- 📁 **[TASK 10A: Dual-UART Transparent Bridge](TASK10A/)**: Bi-directional bridge connecting PC console (USART2) with ESP8266 AT modem (USART1).
- 📁 **[TASK 10B: Wi-Fi Modem Configuration (Station & AP Connect)](TASK10B/)**: Automated sequence executing `AT`, `AT+CWMODE=1`, and `AT+CWJAP="SNUC","snu12345"`.
- 📁 **[TASK 10C: Multi-Step IoT Provisioning Engine](TASK10C/)**: Non-blocking finite state machine (FSM) managing device provisioning and status verification.

---

## Working Principle & Dual-UART Architecture
1. **Dual UART Routing:**
   - **USART1 (`PA9` TX, `PA10` RX @ 115200):** Communicates with the ESP8266 Wi-Fi modem.
   - **USART2 (`PA2` TX, `PA3` RX @ 115200):** Communicates with the PC via ST-LINK VCP.
2. **AT Command Flow:**
   - `AT\r\n` $\rightarrow$ Tests UART physical link; modem replies `OK`.
   - `AT+CWMODE=1\r\n` $\rightarrow$ Sets ESP8266 into Wi-Fi Station Mode.
   - `AT+CWJAP="SNUC","snu12345"\r\n` $\rightarrow$ Connects to Wi-Fi access point.
   - `AT+CIFSR\r\n` $\rightarrow$ Retrieves assigned Station IP and MAC address.
3. **FSM Provisioning (Task 10C):** Uses non-blocking millisecond states (`INIT` $\rightarrow$ `TEST_AT` $\rightarrow$ `SET_MODE` $\rightarrow$ `JOIN_WIFI` $\rightarrow` `GET_IP` $\rightarrow$ `READY`) to ensure dependable connection without blocking the main CPU loop.

---

## Circuit Diagram
![Circuit Diagram](circuit.png)

---

## Summary & Inferences
1. Dual-UART architecture provides full visibility into modem communication while sending host commands.
2. ESP8266 Wi-Fi modem was successfully provisioned to the `SNUC` network using standardized AT commands.
3. The non-blocking state machine handles network response delays cleanly.
