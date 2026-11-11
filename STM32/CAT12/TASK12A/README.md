# CAT 12 - TASK 12A: BME280 I2C Hardware Bring-Up & Sensor Acquisition

## 1. Objective
Interface the Bosch Sensortec BME280 digital environmental sensor over the I2C1 bus with the STM32F401RET6, read the sensor Chip ID register (`0xD0`) to confirm hardware presence, and periodically sample temperature, humidity, and barometric pressure.

## 2. Hardware Setup & Pin Mapping
| BME280 Pin | STM32 Pin | I2C Function | Parameters |
|---|---|---|---|
| **SCL** | `PB8` | I2C1_SCL | 100 kHz Standard Mode |
| **SDA** | `PB9` | I2C1_SDA | 100 kHz Standard Mode |
| **VCC / GND**| +3.3V / GND | Power Rails | Regulated 3.3V DC |
| **USART2 TX**| `PA2` | Debug Telemetry Out | 115200-8-N-1 to PC |

## 3. Working Principle & Implementation Details
1. **I2C Protocol Addressing:**
   - BME280 7-bit slave address: `0x76`. In the STM32 HAL, addresses are shifted left by 1 bit: `(0x76 << 1) = 0xEC`.
2. **Chip ID Verification:**
   - `HAL_I2C_Mem_Read(&hi2c1, 0xEC, 0xD0, I2C_MEMADD_SIZE_8BIT, &chip_id, 1, 100);`
   - Reading `0x60` confirms valid BME280 hardware presence.
3. **Periodic Sampling:** Every 2000 ms, telemetry values are read, formatted into a readable log string, and transmitted to the PC console over USART2.

## 4. Circuit Diagram
![Circuit Diagram](circuit.png)

## 5. Output Verification & Inferences
- PC terminal prints: `[I2C] BME280 Chip ID: 0x60 (Expected: 0x60)`.
- Live environmental telemetry logs (Temperature in °C, Humidity in %, Pressure in hPa) update every 2 seconds.
