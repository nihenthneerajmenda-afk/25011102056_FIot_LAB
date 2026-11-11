# CAT 12 - TASK 12B: Dynamic JSON Payload Generation & HTTP Header Formatting

## 1. Objective
Construct a dynamic JSON telemetry string from BME280 sensor values on the STM32F401RET6, calculate the exact `Content-Length` byte count, and assemble a standard HTTP POST request header for cloud server transmission.

## 2. Hardware Setup & Pin Mapping
| Peripheral | STM32 Pins | Description |
|---|---|---|
| **BME280 Sensor** | `PB8` (SCL), `PB9` (SDA) | I2C1 environmental telemetry input |
| **PC Terminal** | `PA2` (TX), `PA3` (RX) | USART2 debug console |
| **User LED LD2** | `PA5` | Activity indicator |

## 3. Working Principle & Implementation Details
1. **Dynamic JSON Formatting:**
   `snprintf(json_body, sizeof(json_body), "{\"device\":\"NUCLEO_F401RE\",\"reg_no\":\"25011102018\",\"temp_c\":%.2f,\"humidity\":%.2f,\"pressure_hpa\":%.2f,\"uptime_ms\":%lu}", temp, hum, press, uptime);`
2. **Content-Length Calculation:**
   `content_len = strlen(json_body);`
   HTTP 1.1 web servers strictly require an accurate `Content-Length` header matching the exact payload byte count to prevent connection timeouts.
3. **HTTP Header Formulation:**
   Formats the completed HTTP POST packet showing method, destination endpoint (`/api/telemetry`), `Host`, `Content-Type: application/json`, `Content-Length`, and payload.

## 4. Circuit Diagram
![Circuit Diagram](circuit.png)

## 5. Output Verification & Inferences
- Telemetry is accurately formatted into valid JSON syntax with matching header lengths.
- Validates embedded string formatting and buffer management without memory fragmentation.
