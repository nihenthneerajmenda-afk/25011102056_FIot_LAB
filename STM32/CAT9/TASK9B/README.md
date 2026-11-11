# CAT 9 - TASK 9B: Interactive LED Command Parser

## 1. Objective
Implement a serial command interpreter on the STM32F401RET6 that receives text commands from a serial console over USART2 at 115200 baud, parses recognized commands (`LED ON`, `LED OFF`, `LED TOGGLE`, `LED STATUS`), and actuates the onboard user LED accordingly.

## 2. Hardware Setup & Pin Mapping
| Component | STM32 Pin | Description |
|---|---|---|
| **USART2 TX / RX** | `PA2` / `PA3` | Serial command console linked to PC ST-LINK @ 115200 |
| **User LED LD2** | `PA5` | Controlled output indicator |

## 3. Working Principle & Command Grammar
1. **Buffer Assembly & Backspace Handling:**
   - Incoming bytes are echoed back to the terminal so the user can see what they type.
   - Backspace (`\b` or `0x7F`) removes the previous character from the buffer and sends ` \b` to erase it visually.
2. **Command Delimitation & Parsing:**
   - When Enter (`\r` or `\n`) is pressed, the string is null-terminated and evaluated:
     - `LED ON` $\rightarrow$ Drives `PA5` HIGH, replies `"[OK] User LED (PA5) is now turned ON"`.
     - `LED OFF` $\rightarrow$ Drives `PA5` LOW, replies `"[OK] User LED (PA5) is now turned OFF"`.
     - `LED TOGGLE` $\rightarrow$ Inverts `PA5`, reports new state.
     - `LED STATUS` $\rightarrow$ Reads `PA5` pin state, reports `ON` or `OFF`.
     - *Unknown Command* $\rightarrow$ Returns an error notification listing valid commands.

## 4. Circuit Diagram
![Circuit Diagram](circuit.png)

## 5. Output Verification & Inferences
- Commands typed in PuTTY successfully change the physical state of LED LD2.
- The command line interface provides descriptive error handling for unrecognized commands.
