# CAT 5 - TASK 5A: 1 ms Timer 0 ISR & 1s LED Toggle

## 1. Objective
Configure 8051 Hardware Timer 0 in 16-bit Mode 1 to generate precise periodic 1 ms interrupts, count 1000 milliseconds in software, and toggle an output LED on Port 1 Pin 0 (`P1.0`) every 1.0 second.

## 2. Hardware Setup & Pin Mapping
| Component | 8051 Pin | Direction | Function |
|---|---|---|---|
| **Toggle LED** | `P1.0` | Output | Active-LOW LED toggling every 1000 ms (0.5 Hz frequency) |
| **Oscillator** | `XTAL1`/`XTAL2` | Input | 11.0592 MHz crystal reference |

## 3. Working Principle & Timer Calculations
1. **Timer 0 Mode 1 (16-bit Timer):** `TMOD &= 0xF0; TMOD |= 0x01;` configures Timer 0 as a 16-bit counter (0 to 65535).
2. **Preload Derivation for 1 ms Interrupt:**
   $$T_{machine} = \frac{12}{11.0592\text{ MHz}} = 1.085069\,\mu\text{s}$$
   $$\text{Counts for 1 ms} = \frac{1000\,\mu\text{s}}{1.085069\,\mu\text{s}} \approx 922$$
   $$\text{Preload} = 65536 - 922 = 64614 = \text{0xFC66}$$
3. **ISR Execution:** Inside `timer0_isr() interrupt 1`:
   - `TH0 = 0xFC; TL0 = 0x66;` reloads the counter for the next 1 ms.
   - `ms_count++` increments. When it reaches 1000, `ms_count = 0; LED_1SEC = ~LED_1SEC;` toggles `P1.0`.

## 4. Circuit Diagram
![Circuit Diagram](circuit.png)

## 5. Output Verification & Inferences
- Oscilloscope measurement on `P1.0` confirms an exact 1.0 s HIGH and 1.0 s LOW square wave (Period = 2.0 s, $f = 0.5\text{ Hz}$).
- Offloading timing to a hardware timer frees the main loop for background processing without timing drift.
