# CAT 7 - TASK 7C: 4x4 Keypad Interactive LCD Menu Navigation

## 1. Objective
Combine the 4-bit HD44780 LCD driver on Port 2 with 4x4 matrix keypad scanning on Port 0 to create an interactive menu display where keypresses are read, decoded, and rendered on the LCD screen in real time.

## 2. Hardware Setup & Pin Mapping
| Peripheral | Signals | 8051 Port / Pins |
|---|---|---|
| **16x2 LCD** | RS, RW, EN, D4-D7 | `P2.0`, `P2.1`, `P2.2`, `P2.4`–`P2.7` |
| **4x4 Keypad** | Rows R1–R4, Cols C1–C4 | `P0.0`–`P0.3` (Rows), `P0.4`–`P0.7` (Cols) |

## 3. Working Principle & Implementation Details
1. **Keypad Matrix Scanning on Port 0:** Sequentially asserts logic LOW on row pins (`P0.0`-`P0.3`) and reads column pins (`P0.4`-`P0.7`).
2. **Lookup Table:** Translates coordinate intersections into characters `'0'`–`'9'`, `'A'`–`'D'`, `'*'`, `'#'`.
3. **LCD Interactive Render:**
   - Line 1 displays `"Interactive Menu"`.
   - When a key is detected, `lcd_goto(1, 5);` positions the cursor and prints the character enclosed in brackets, e.g., `Key: [5]`.

## 4. Circuit Diagram
![Circuit Diagram](circuit.png)

## 5. Output Verification & Inferences
- Pressing any key on the matrix keypad immediately updates the displayed character on the LCD.
- Demonstrates integration of multiple input/output peripherals on an 8-bit microcontroller.
