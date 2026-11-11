# CAT 8 - TASK 8B: Debounced Push Button Toggle Mode

## 1. Objective
Implement a software debounced button toggle engine on the STM32F103C8T6 that filters mechanical contact noise using a 25 ms non-blocking time window and toggles the state of the `PC13` LED on each valid button press.

## 2. Hardware Setup & Pin Mapping
| Component | STM32 Pin | Mode | Description |
|---|---|---|---|
| **Push-Button** | `PA0` | Input with Pull-Up | Active-LOW input |
| **User LED** | `PC13` | Output Open-Drain | Active-LOW output |

## 3. Working Principle & Implementation Details
1. **Mechanical Chatter:** Mechanical switches bounce upon closure for 5 to 20 ms. Without debouncing, a single physical press can trigger multiple state toggles.
2. **Non-Blocking Debounce Filter:**
   - Records elapsed time via `uint32_t current_tick = HAL_GetTick();`.
   - Compares current pin state with `last_btn_state`.
   - If the state changes and `(current_tick - last_debounce_tick) > 25` ms, the transition is accepted.
   - On a confirmed falling edge (`current_state == GPIO_PIN_RESET`), `HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13)` inverts the LED state.

## 4. Circuit Diagram
![Circuit Diagram](circuit.png)

## 5. Output Verification & Inferences
- Each individual button tap cleanly changes the LED between ON and OFF states without glitching or double-toggling.
- Using `HAL_GetTick()` provides debouncing without stalling CPU execution.
