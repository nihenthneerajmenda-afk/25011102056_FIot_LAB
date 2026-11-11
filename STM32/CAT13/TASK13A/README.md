# CAT 13 - TASK 13A: BME280 I2C Environmental Sensing & Compensation

## 1. Objective
Interface the Bosch BME280 environmental sensor with STM32 NUCLEO-F401RE over I2C1, verify Chip ID (`0x60`), read raw uncompensated temperature, pressure, and humidity registers, and apply Bosch compensation formulas.

## 2. Hardware Setup & Pin Mapping
| Component | STM32 Pin | Interface | Function |
|---|---|---|---|
| **BME280 SCL** | `PB8` | `I2C1_SCL` | 100 kHz I2C Clock |
| **BME280 SDA** | `PB9` | `I2C1_SDA` | 100 kHz I2C Data |
| **Power Rails** | +3.3V / GND | DC Rails | +3.3V supply |

## 3. Working Principle & Implementation Details
1. `bme280_init(&dev)` verifies chip communication over address `0x76`.
2. Raw data registers are sampled and processed using fixed-point compensation.
3. Compensated readings are output in physical units (°C, hPa, %RH).

## 4. Circuit Diagram
![Circuit Diagram](circuit.png)

## 5. Output Verification & Inferences
- Valid temperature (~28°C), pressure (~1008 hPa), and humidity (~62%RH) values are verified over I2C.
