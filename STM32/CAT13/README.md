# CAT 13: BME280 Environmental Sensing (I2C) & MQTT Cloud Analytics

## Experiment Overview
- **Course:** Fundamentals of Internet of Things + Lab (25CS2741)
- **Target Platform:** STM32 NUCLEO-F401RE (ARM Cortex-M4 @ 84 MHz) + ESP8266 Wemos D1 Mini
- **Primary Toolchain:** STM32CubeMX, Keil MDK-ARM µVision & ST-LINK V2-1
- **Objective:** Develop a production-grade, end-to-end IoT edge sensing node. The STM32 reads temperature, pressure, and humidity from a Bosch BME280 sensor over I2C, utilizes a custom-built ESP8266 driver library (`ESPLib`) to connect to campus Wi-Fi (`SNUC`), and publishes structured JSON telemetry over MQTT to a cloud broker (`broker.emqx.io`) for real-time Node-RED analytics.

---

## Comprehensive Task Breakdown (All CAT 13 Tasks)

### Task 13A — BME280 I2C Hardware Interfacing & Compensation
1. **Objective:** Interface the Bosch BME280 environmental sensor with STM32 via `I2C1` (`PB8` SCL, `PB9` SDA) and extract factory calibration parameters.
2. **Implementation Details:**
   - Verifies Chip ID register `0xD0 == 0x60`.
   - Configures oversampling ($1	imes$ temperature, $1	imes$ pressure, $1	imes$ humidity) in Normal operating mode.
   - Reads 8-byte raw uncompensated burst registers (`0xF7`–`0xFE`).
   - Applies 64-bit fixed-point compensation formulas to calculate temperature in °C, barometric pressure in hPa, and relative humidity in %RH.

### Task 13B — ESP8266 MQTT Client API (`ESPLib`) & Cloud Ingestion
1. **Objective:** Implement modular MQTT client services via USART2 using the custom `ESPLib` driver to establish cloud telemetry streaming.
2. **Network & Protocol Flow:**
   - **Station Initialization:** `ESP8266_Init(StationMode, huart2);`
   - **Wi-Fi Association:** `ESP8266_wifiConnect("SNUC", "snu12345");`
   - **TCP Broker Connection:** Connects to public MQTT broker on port 1883:
     ```c
     ESP8266_portConnect("TCP", "broker.emqx.io", "1883");
     ```
   - **MQTT Session Configuration:**
     - Client ID: `MqttID_25011102018`
     - Keep-Alive: 500 seconds
     - Connect Flag: Clean Session
   - **Telemetry Publishing:** Formulates JSON payloads and streams periodically to topic `stm32/test/data` (QoS0):
     ```c
     MQTT_publishTopic("stm32/test/data", json_payload, QoS0);
     ```
   - **Node-RED Cloud Dashboard:** An `mqtt in` node subscribed to `stm32/test/data` parses incoming JSON and renders live gauges for Temperature, Pressure, and Humidity.

---

## Dedicated Task Folder
- 📁 **[TASK 13: Integrated Smart IoT Edge Node Project](TASK13/)**: Complete STM32CubeMX project, `Core/Src/main.c`, `Core/Inc/bme280.h`, `Core/Inc/ESPLib.h`, and MDK-ARM build files.

---

## Circuit Diagram
![Circuit Diagram](circuit.png)

---

## Summary & Inferences
1. Successfully integrated multi-bus embedded architecture: I2C for local sensor telemetry and UART AT commands for wireless network connectivity.
2. Fixed-point sensor compensation produces laboratory-grade ambient measurements.
3. MQTT telemetry streaming provides lightweight, low-bandwidth publish-subscribe transport suitable for IoT edge nodes.
