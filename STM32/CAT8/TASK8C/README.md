# CAT 8 - TASK 8C: Non-Blocking Short vs Long Press Duration Classifier

## 1. Objective
Design and implement a non-blocking press duration classifier on the STM32F103C8T6 that categorizes button presses on `PA0` into Short (< 1.0 s) and Long (≥ 1.0 s) presses, controlling the `PC13` LED with multi-mode behaviors.

## 2. Hardware Setup & Pin Mapping
| Component | STM32 Pin | Function |
|---|---|---|
| **Push-Button** | `PA0` | Input with pull-up resistor |
| **User LED** | `PC13` | Output indicator LED |

## 3. Working Principle & Implementation Details
1. **Duration Measurement:**
   - On falling edge (`pin_val == RESET`), the system records `press_start_tick = HAL_GetTick();`.
   - On rising edge (`pin_val == SET`), it calculates `duration = now - press_start_tick;`.
2. **Behavioral Classification:**
   - **Short Press (< 1000 ms):** Toggles LED between steady ON and steady OFF.
   - **Long Press (≥ 1000 ms):** Enters/exits a fast-blinking strobe mode (100 ms toggle interval).
3. **Execution Engine:** A non-blocking state machine updates the LED output every loop iteration based on the active mode (`LED_MODE_OFF`, `LED_MODE_ON`, or `LED_MODE_BLINK_FAST`).

## 4. Circuit Diagram
![Circuit Diagram](circuit.png)

## 5. Output Verification & Inferences
- Short presses reliably toggle the LED ON or OFF.
- Holding the button for 1 second or longer switches the LED into a rapid strobe mode.
- Demonstrates how timing differentiation expands single-button user interfaces.
