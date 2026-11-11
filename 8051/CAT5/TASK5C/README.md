# CAT 5 - TASK 5C: Stepper Motor Full-Step Sequence Generator

## 1. Objective
Interface a 28BYJ-48 4-phase unipolar permanent-magnet stepper motor with Port 2 of the AT89S52 using a ULN2003 Darlington transistor array, and implement a full-step sequence generator for smooth continuous rotation.

## 2. Hardware Setup & Pin Mapping
| Stepper Coil | ULN2003 Input | 8051 Pin | Coil Color |
|---|---|---|---|
| **Phase A** | IN1 (Pin 1) | `P2.0` | Blue |
| **Phase B** | IN2 (Pin 2) | `P2.1` | Pink |
| **Phase C** | IN3 (Pin 3) | `P2.2` | Yellow |
| **Phase D** | IN4 (Pin 4) | `P2.3` | Orange |
| **Motor Common** | +5V DC | — | Red |

## 3. Working Principle & Step Sequence
1. **ULN2003 Driver:** The 8051 cannot supply the ~150 mA required to energize stepper coils. The ULN2003 provides high-voltage, high-current Darlington pairs with integrated flyback suppression diodes.
2. **4-Step Full-Step Sequence Table:**
   - Step 0: `0x09` (Coil A + Coil D energized)
   - Step 1: `0x0C` (Coil A + Coil B energized)
   - Step 2: `0x06` (Coil B + Coil C energized)
   - Step 3: `0x03` (Coil C + Coil D energized)
3. **Speed Control:** A 20 ms delay between steps yields a steady stepping rate of 50 steps/second without stalling or slipping.

## 4. Circuit Diagram
![Circuit Diagram](circuit.png)

## 5. Output Verification & Inferences
- The stepper motor shaft rotates smoothly in the clockwise direction with high holding torque.
- Full-step excitation provides maximum torque output compared to single-phase wave drive.
