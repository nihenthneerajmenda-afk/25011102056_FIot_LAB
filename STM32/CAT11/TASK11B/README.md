# CAT 11 - TASK 11B: Push Button B1 Control with State Remembrance & Duration Classifier

## 1. Objective
Configure the STM32F401RE NUCLEO-64 onboard user push-button B1 (`PC13`) and user LED LD2 (`PA5`) using the HAL library. Implement software debouncing to toggle the LED on each valid press, maintain output latching memory (state remembrance) across button releases, and classify button events based on press duration.

## 2. Hardware Setup & Pin Mapping
| Component | NUCLEO-F401RE Pin | Mode / Configuration | State Description |
|---|---|---|---|
| **User Push-Button B1** | `PC13` | GPIO Input with Internal Pull-Up | Active-LOW (0 = Pressed, 1 = Released) |
| **User LED LD2 (Green)** | `PA5` | GPIO Output Push-Pull | Active-HIGH (1 = LED ON, 0 = LED OFF) |

## 3. Working Principle & Implementation Details
1. **Switch Contact Debouncing:**
   - Mechanical contact bounce is filtered using a 25 ms software verification window.
2. **State Remembrance (Latching Logic):**
   - The application maintains a boolean variable `led_state`.
   - On each verified falling edge, `led_state` toggles and the output is updated:
     ```c
     led_state = !led_state;
     HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, led_state ? GPIO_PIN_SET : GPIO_PIN_RESET);
     ```
   - Releasing the button preserves `led_state`, fulfilling the state remembrance requirement.
3. **Press Duration Classification (Task 11C):**
   - When `PC13` goes LOW, the timestamp is recorded: `start_time = HAL_GetTick();`.
   - Upon release, the duration is calculated:
     $$\Delta t = 	ext{HAL\_GetTick}() - 	ext{start\_time}$$
   - If $\Delta t < 1000	ext{ ms}$, it is classified as a **Short Press** (toggle LED).
   - If $\Delta t \ge 1000	ext{ ms}$, it is classified as a **Long Press** (enters rapid alert flashing).

## 4. Circuit Diagram
![Circuit Diagram](circuit.png)

## 5. Output Verification & Inferences
- Pressing B1 cleanly flips LD2 state between ON and OFF without switch bounce chatter.
- LED persists in its toggled state indefinitely after releasing the button.
- Sustained holding (>1s) successfully triggers long-press mode.
