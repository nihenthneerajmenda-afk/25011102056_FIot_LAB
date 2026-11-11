# CAT 5 - TASK 5B.1: Software PWM Fading - Triangular Wave Modulation

## 1. Objective
Implement a software Pulse-Width Modulation (PWM) generator on the AT89S52 to smoothly fade an LED on Port 1 Pin 1 (`P1.1`) by varying the duty cycle from 0% to 100% and back down to 0% in a triangular modulation pattern.

## 2. Hardware Setup & Pin Mapping
| Component | 8051 Pin | Electrical Connection |
|---|---|---|
| **Fading LED** | `P1.1` | Active-LOW LED in series with 330 Ω resistor to VCC |

## 3. Working Principle & Implementation Details
1. **Software PWM Concept:** Generates PWM by rapidly toggling `P1.1` within a 100-step time frame:
   - For steps `0` to `duty - 1`: `P1.1 = 0` (LED is ON).
   - For steps `duty` to `99`: `P1.1 = 1` (LED is OFF).
2. **Triangular Modulation:**
   - The duty cycle begins at 0% (LED completely dark).
   - Increments by 2% on each cycle until reaching 100% (peak brightness).
   - Once at 100%, the direction reverses and decrements back to 0%.
3. **Visual Persistence:** Because the repetition rate exceeds visual persistence (>100 Hz), human eyes perceive continuous, smooth brightness fading without optical flicker.

## 4. Circuit Diagram
![Circuit Diagram](circuit.png)

## 5. Output Verification & Inferences
- Smooth, sinusoidal-like breathing illumination observed on the LED.
- Oscilloscope waveform shows duty cycle expanding from 0% to 100% and shrinking back in a periodic triangular profile.
