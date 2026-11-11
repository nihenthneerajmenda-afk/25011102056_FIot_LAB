# CAT 7 - TASK 7B: Cursor Positioning & Dynamic Counter Display

## 1. Objective
Implement cursor positioning on the HD44780 16x2 LCD, display a static header on Line 1, and dynamically update an incrementing integer counter on Line 2 in real time.

## 2. Hardware Setup & Pin Mapping
| LCD Pin | Function | 8051 Pin |
|---|---|---|
| **RS** | Register Select | `P2.0` |
| **RW** | Read / Write | `P2.1` |
| **EN** | Enable | `P2.2` |
| **D4 – D7** | Data Lines | `P2.4` – `P2.7` |

## 3. Working Principle & Implementation Details
1. **Static vs Dynamic Regions:**
   - Line 1 displays `"Dynamic Counter:"` once during initialization.
   - Line 2 is repositioned on each iteration via `lcd_goto(1, 0);`.
2. **Integer to ASCII Conversion:**
   - Function `lcd_print_number(unsigned int num)` repeatedly extracts modulo digits (`num % 10 + '0'`) into an internal buffer.
   - Digits are printed in reverse order to display the correct decimal value.
3. **Trailing Blanking:** Prints trailing spaces (`"   "`) after each count to clear previous digits when transitioning between power-of-ten boundaries.

## 4. Circuit Diagram
![Circuit Diagram](circuit.png)

## 5. Output Verification & Inferences
- Counter updates smoothly from 0 upwards every 250 ms on Line 2 without screen flickering.
- Confirms precise cursor coordinate addressing (`lcd_goto(row, col)`).
