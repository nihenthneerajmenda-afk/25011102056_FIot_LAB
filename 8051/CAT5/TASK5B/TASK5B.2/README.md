# CAT 5 - TASK 5B.2: Software PWM Carrier Frequency Analysis

## 1. Objective
Generate a software PWM signal with a calibrated 500 Hz carrier frequency on Port 1 Pin 1 (`P1.1`) and evaluate output waveform integrity across discrete duty cycle settings (25%, 50%, 75%, 100%) on a Digital Storage Oscilloscope (DSO).

## 2. Hardware Setup & Pin Mapping
| Signal | 8051 Pin | Destination |
|---|---|---|
| **PWM Waveform Out** | `P1.1` | DSO Channel 1 & User LED |
| **Sync Pulse Out** | `P1.2` | DSO Channel 2 (External Trigger Sync) |

## 3. Working Principle & Implementation Details
1. **Fixed Carrier Period:** Each PWM period is composed of 100 micro-time-slices calibrated to produce an overall carrier period of $2.0\text{ ms}$ ($500\text{ Hz}$).
2. **Discrete Test Levels:**
   - Level 0: 25% Duty Cycle (0.5 ms ON, 1.5 ms OFF)
   - Level 1: 50% Duty Cycle (1.0 ms ON, 1.0 ms OFF)
   - Level 2: 75% Duty Cycle (1.5 ms ON, 0.5 ms OFF)
   - Level 3: 100% Duty Cycle (Continuous ON)
3. **DSO Trigger Sync:** `P1.2` generates a rising-edge strobe at the start of each PWM frame to lock the DSO display for stable duty cycle measurement.

## 4. Circuit Diagram
![Circuit Diagram](circuit.png)

## 5. Output Verification & Inferences
- DSO Channel 1 confirms exact 500 Hz carrier frequency with duty cycle stepping through 25%, 50%, 75%, and 100% every 500 periods (~1 second).
- Demonstrates how pulse width directly dictates average delivered voltage ($V_{avg} = V_{CC} \times \text{Duty}$).
