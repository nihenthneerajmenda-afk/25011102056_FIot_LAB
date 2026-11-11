# CAT 12 - TASK 12C: Node-RED Cloud Ingestion Pipeline

## 1. Objective
Implement a complete end-to-end cloud ingestion pipeline from the STM32F401RET6 using an ESP8266 Wi-Fi modem, connecting to the `SNUC` campus network, opening a TCP socket to a local Node-RED server, and transmitting HTTP POST telemetry packets.

## 2. Hardware Setup & Pin Mapping
| Interface | STM32 Pins | Connection Details |
|---|---|---|
| **BME280 Sensor** | `PB8` (SCL), `PB9` (SDA) | I2C1 environmental data input |
| **ESP8266 Modem** | `PA9` (TX), `PA10` (RX) | USART1 AT command connection |
| **PC ST-LINK** | `PA2` (TX), `PA3` (RX) | USART2 diagnostic console |

## 3. Working Principle & Cloud Transmission Flow
1. **Wi-Fi Association:**
   - Sends `AT+CWJAP="SNUC","snu12345"\r\n` to connect to the campus access point.
2. **TCP Connection & HTTP POST:**
   - Every 5 seconds, formats a JSON payload: `{"device":"NUCLEO_F401RE","reg_no":"25011102018","temp_c":24.50,"hum":60.20,"press":1013.25}`.
   - Opens TCP connection to Node-RED: `AT+CIPSTART="TCP","192.168.1.100",1880\r\n`.
   - Sends packet size: `AT+CIPSEND=<len>\r\n`.
   - Transmits HTTP POST packet:
     ```http
     POST /api/telemetry HTTP/1.1
     Host: 192.168.1.100:1880
     Content-Type: application/json
     Content-Length: 104
     Connection: close

     {"device":"NUCLEO_F401RE",...}
     ```
3. **Visual Indication:** `HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5)` blinks the green LED with each successful transmission.

## 4. Circuit Diagram
![Circuit Diagram](circuit.png)

## 5. Output Verification & Inferences
- Node-RED dashboard receives and displays live temperature, humidity, and pressure readings.
- Verifies embedded microcontroller HTTP telemetry transmission over local Wi-Fi.
