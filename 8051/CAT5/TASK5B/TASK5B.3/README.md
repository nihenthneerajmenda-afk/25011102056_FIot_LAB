# CAT 5 - TASK 5B.3: Software PWM Multi-LED Breathing Controller

## 1. Objective
Implement a multi-channel software PWM breathing controller on the AT89S52 that simultaneously modulates the luminous intensity of 4 LEDs connected across Port 1 Pins 0 to 3 (`P1.0`–`P1.3`).

## 2. Hardware Setup & Pin Mapping
| Component | 8051 Port / Pins | Connection Details |
|---|---|---|
| **4x User LEDs** | `P1.0`, `P1.1`, `P1.2`, `P1.3` | Active-LOW LEDs with 330 Ω current limiters |

## 3. Working Principle & Implementation Details
1. **Parallel Port Modulation:** Rather than toggling pins individually, the entire Port 1 lower nibble is written in a single machine instruction:
   - When active (`step < duty`): `LED_PORT = 0xF0;` (pulls `P1.0`-`P1.3` LOW, turning all 4 LEDs ON).
   - When inactive: `LED_PORT = 0xFF;` (sets pins HIGH, turning LEDs OFF).
2. **Smooth Breathing Algorithm:** Modulates duty cycle from 2% to 98% with an inflection point reversal, producing a rhythmic "breathing" illumination curve.

## 4. Circuit Diagram
![Circuit Diagram](circuit.png)

## 5. Output Verification & Inferences
- All 4 LEDs fade in and out in synchronized rhythm with identical brightness levels.
- Port-level parallel writes ensure minimal CPU overhead compared to bit-by-bit manipulation.
