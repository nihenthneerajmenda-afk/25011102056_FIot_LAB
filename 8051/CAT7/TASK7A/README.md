# CAT 7 - TASK 7A: LCD 4-Bit Driver & Dual-Row Display

## 1. Objective
Develop an Embedded C 4-bit parallel driver for the HD44780 16x2 alphanumeric LCD and display static alphanumeric text across both rows (`"25011102018 FIoT"` on Line 1 and `"LCD 16x2 4-Bit OK"` on Line 2).

## 2. Hardware Setup & Pin Mapping
| LCD Pin | Function | 8051 Pin | Description |
|---|---|---|---|
| **RS** | Register Select | `P2.0` | 0 = Command, 1 = Character Data |
| **RW** | Read / Write | `P2.1` | Tied to GND (Write mode) |
| **EN** | Enable Strobe | `P2.2` | High-to-Low pulse latches data nibble |
| **D4 – D7** | Data Lines | `P2.4` – `P2.7` | High nibble parallel bus |

## 3. Working Principle & 4-Bit Initialization
1. **Nibble Transmission:** Each 8-bit byte is transmitted in two successive 4-bit nibbles: higher nibble first, followed by lower nibble shifted left by 4 bits. Each nibble is latched with a High-to-Low pulse on `EN`.
2. **Initialization Sequence:**
   - Power-on wait (20 ms).
   - Special reset nibbles: `0x30` $\rightarrow$ `0x30` $\rightarrow$ `0x30` $\rightarrow$ `0x20` (sets 4-bit mode).
   - Function set: `0x28` (4-bit, 2 lines, 5x7 font).
   - Display control: `0x0C` (Display ON, cursor OFF).
   - Entry mode: `0x06` (Increment cursor automatically).
   - Clear display: `0x01`.
3. **Row Positioning:** Line 1 DDRAM address starts at `0x80`; Line 2 starts at `0xC0`.

## 4. Circuit Diagram
![Circuit Diagram](circuit.png)

## 5. Output Verification & Inferences
- Dual-row strings are rendered clearly across both rows of the 16x2 LCD display.
- 4-bit mode conserves 4 microcontroller GPIO pins without noticeable display latency.
