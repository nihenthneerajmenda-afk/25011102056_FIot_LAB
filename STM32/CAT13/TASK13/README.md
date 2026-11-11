# CAT 13 - TASK 13: Integrated Smart IoT Edge Node (BME280 I2C + ESP8266 MQTT + Node-RED)

## 1. Objective
Develop a complete, fully integrated smart IoT edge node on the STM32 NUCLEO-F401RE that acquires compensated temperature, humidity, and atmospheric pressure from a Bosch BME280 sensor via I2C, connects to campus Wi-Fi (`SNUC`) through an ESP8266 Wi-Fi module, and streams live telemetry to an MQTT broker (`broker.emqx.io`) for real-time visualization on a Node-RED dashboard.

## 2. Hardware Setup & Pin Mapping
| Component | STM32 Pin | Interface / Mode | Description |
|---|---|---|---|
| **BME280 SCL** | `PB8` | `I2C1_SCL` | 100 kHz standard mode clock with external 4.7 kΩ pull-up |
| **BME280 SDA** | `PB9` | `I2C1_SDA` | 100 kHz standard mode bidirectional data with pull-up |
| **BME280 $V_{DD}$ / GND** | +3.3V / GND | Power Rails | Regulated +3.3V sensor supply |
| **ESP8266 TX** | `PA3` | `USART2_RX` | Serial data from ESP8266 to STM32 (115200 baud) |
| **ESP8266 RX** | `PA2` | `USART2_TX` | Serial AT commands from STM32 to ESP8266 |
| **User Status LED** | `PA5` | GPIO Output | Heartbeat indicator toggling on each MQTT transmission |

## 3. Working Principle & Implementation Details
1. **BME280 Sensor Acquisition (Task 13A):**
   - Initializes sensor via `bme280_init(&dev)` over I2C address `0x76`.
   - Reads raw temperature, pressure, and humidity registers in burst mode.
   - Applies Bosch compensation algorithms:
     ```c
     rslt = bme280_get_sensor_data(BME280_ALL, &comp_data, &dev);
     temperature = comp_data.temperature;
     pressure = comp_data.pressure / 100.0f; /* Convert Pa to hPa */
     humidity = comp_data.humidity;
     ```
2. **ESP8266 MQTT Client API (`ESPLib` — Task 13B):**
   - Initializes Station mode and connects to Wi-Fi:
     ```c
     ESP8266_Init(StationMode, huart2);
     ESP8266_wifiConnect("SNUC", "snu12345");
     ```
   - Connects to public broker `broker.emqx.io` on TCP port 1883:
     ```c
     ESP8266_portConnect("TCP", "broker.emqx.io", "1883");
     ```
   - Configures client credentials (`MqttID_25011102018`, keep-alive 500s).
   - Formulates dynamic JSON payload:
     `{"temperature": 28.45, "humidity": 62.30, "pressure": 1008.72}`
   - Publishes to topic `stm32/test/data` (QoS0):
     ```c
     MQTT_publishTopic("stm32/test/data", json_payload, QoS0);
     ```
3. **Node-RED Cloud Ingestion:**
   - Subscribes to `stm32/test/data`, parses JSON payload, and drives dashboard gauges and temporal trend charts.

## 4. Circuit Diagram
![Circuit Diagram](circuit.png)

## 5. Output Verification & Inferences
- Real-time environmental readings (temperature, pressure, humidity) are sampled every 1.0 second.
- STM32 successfully associates with `SNUC` Wi-Fi network and maintains persistent MQTT connection.
- Node-RED dashboard displays live, interactive telemetry updates matching ambient room conditions.
