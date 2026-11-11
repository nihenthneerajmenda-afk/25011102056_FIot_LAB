# CAT 11 - TASK 11C: Short-Press vs Long-Press Duration Classifier

## 1. Objective
Implement a non-blocking push-button press duration classifier on the STM32 NUCLEO-F401RE using `HAL_GetTick()`. Classify presses into Short Press (< 1000 ms) to toggle user LED LD2, and Long Press (≥ 1000 ms) to trigger rapid alert flashing.

## 2. Hardware Setup & Pin Mapping
| Component | STM32 Pin | Mode | Description |
|---|---|---|---|
| **User Button B1** | `PC13` | Input with Pull-Up | Active-LOW (0 = Pressed, 1 = Released) |
| **User LED LD2** | `PA5` | Output Push-Pull | Active-HIGH onboard green LED |

## 3. Working Principle & Implementation Details
1. Millisecond timing is sampled via `HAL_GetTick()`.
2. Upon falling edge on `PC13`, `press_start = HAL_GetTick()` is captured.
3. Upon release, elapsed duration $\Delta t = 	ext{HAL\_GetTick}() - 	ext{press\_start}$ determines event classification.

## 4. Circuit Diagram
![Circuit Diagram](circuit.png)

## 5. Output Verification & Inferences
- Short tap immediately toggles LED state.
- Sustained hold for 1+ seconds executes a distinct 5-blink alert pattern.
