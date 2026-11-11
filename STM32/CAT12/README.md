# CAT 12: BME280 Sensor Data Acquisition & HTTP Cloud Ingestion

## Experiment Overview
- **Target Platform:** STM32 NUCLEO-F401RE + BME280 Sensor + Wemos ESP8266
- **Objective:** Interface the Bosch Sensortec BME280 environmental sensor over the I2C bus, sample temperature, humidity, and atmospheric pressure, format the telemetry into a dynamic JSON payload with exact `Content-Length`, and transmit it via HTTP POST through the ESP8266 Wi-Fi modem to a Node-RED cloud server.

---

## Active Subtasks
- 📁 **[TASK 12A: BME280 I2C Hardware Bring-Up & Sensor Acquisition](TASK12A/)**: I2C1 communication verifying BME280 Chip ID (`0x60`) and periodic telemetry sampling.
- 📁 **[TASK 12B: Dynamic JSON Payload Generation & HTTP Header Formatting](TASK12B/)**: Formulates dynamic JSON telemetry and computes exact `Content-Length`.
- 📁 **[TASK 12C: Node-RED Cloud Ingestion Pipeline](TASK12C/)**: Complete HTTP POST pipeline transmitting telemetry to a Node-RED server over `SNUC` Wi-Fi.

---

## Working Principle & Communication Protocols
1. **I2C Sensor Interface:**
   - I2C1 on `PB8` (SCL) and `PB9` (SDA) operates at 100 kHz standard mode.
   - BME280 7-bit slave address: `0x76` (shifted to `0xEC` for 8-bit HAL operations).
   - Register `0xD0` returns Chip ID `0x60`, validating sensor hardware connectivity.
2. **JSON Telemetry Formulation:**
   Telemetry is formatted as:
   `{"device":"NUCLEO_F401RE","reg_no":"25011102018","temp_c":24.50,"hum":60.20,"press":1013.25}`
3. **HTTP POST Transmission:**
   - Wi-Fi association via `AT+CWJAP="SNUC","snu12345"`.
   - Opens TCP connection: `AT+CIPSTART="TCP","192.168.1.100",1880`.
   - Sends HTTP POST request packet containing computed `Content-Length` and JSON payload.

---

## Circuit Diagram
![Circuit Diagram](circuit.png)

---

## Summary & Inferences
1. I2C communication allows reliable environmental multi-sensor sampling over two shared bus lines.
2. Dynamic string generation accurately formats JSON data with compliant HTTP 1.1 headers.
3. ESP8266 Wi-Fi modem successfully transports sensor data from the embedded node to Node-RED.
