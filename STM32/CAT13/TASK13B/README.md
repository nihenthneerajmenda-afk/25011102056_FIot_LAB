# CAT 13 - TASK 13B: ESP8266 MQTT Client API & Cloud Telemetry

## 1. Objective
Implement the custom `ESPLib` MQTT client library on STM32 to associate with `SNUC` Wi-Fi, connect to a public MQTT broker (`broker.emqx.io:1883`), and stream JSON sensor telemetry to topic `stm32/test/data` for Node-RED analytics.

## 2. Hardware Setup & Pin Mapping
| Component | STM32 Pin | Interface | Description |
|---|---|---|---|
| **ESP8266 RX** | `PA2` | `USART2_TX` | Transmits AT / MQTT commands |
| **ESP8266 TX** | `PA3` | `USART2_RX` | Receives responses from modem |

## 3. Working Principle & Implementation Details
1. Associates with Wi-Fi: `ESP8266_wifiConnect("SNUC", "snu12345");`.
2. Connects to broker: `ESP8266_portConnect("TCP", "broker.emqx.io", "1883");`.
3. Periodically publishes formatted JSON telemetry to `stm32/test/data`.

## 4. Circuit Diagram
![Circuit Diagram](circuit.png)

## 5. Output Verification & Inferences
- MQTT packets are received and visualized in real time on the Node-RED cloud dashboard.
