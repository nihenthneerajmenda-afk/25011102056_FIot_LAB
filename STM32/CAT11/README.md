# CAT 11: STM32F401RE GPIO, Switch Control & Press Classifier

## Experiment Overview
- **Course:** Fundamentals of Internet of Things + Lab (25CS2741)
- **Target Platform:** STM32 NUCLEO-F401RE (ARM Cortex-M4 @ 84 MHz)
- **Primary Toolchain:** STM32CubeMX, Keil MDK-ARM µVision & ST-LINK V2-1
- **Objective:** Configure the STM32F401RE microcontroller GPIO peripherals to bring up the onboard user LED (LD2), implement debounced switch control with state remembrance (latching memory) using the B1 user push-button, and classify button presses based on duration.

---

## Comprehensive Task Breakdown (All CAT 11 Tasks)

### Task 11A — Onboard User LED LD2 Bring-Up (1.0 Hz Blink)
1. **Objective:** Configure `PA5` as a push-pull GPIO output and blink user LED LD2 at 1.0 Hz (500 ms ON, 500 ms OFF) using the STM32 HAL library.
2. **Hardware Configuration:**
   - Onboard green LED LD2 is connected to `PA5`. Driving `PA5` HIGH illuminates the LED; driving LOW turns it OFF (Active-HIGH).
   - In each loop cycle, the firmware executes:
     ```c
     HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
     HAL_Delay(500);
     ```

### Task 11B — User Push-Button B1 Control with State Remembrance
1. **Objective:** Configure onboard blue push-button B1 on `PC13` as a digital input with an internal pull-up and implement latching toggle memory.
2. **Working Principle:**
   - B1 is Active-LOW (Logic 0 when pressed, Logic 1 when released).
   - A non-blocking 25 ms debounce filter verifies falling edges.
   - When a valid press transition occurs, the state variable is toggled (`led_state = !led_state;`) and written to `PA5`.
   - The LED persists in its new state indefinitely after the button is released.

### Task 11C — Short-Press vs Long-Press Duration Classifier
1. **Objective:** Measure the exact duration of button depression using `HAL_GetTick()` and trigger distinct actions:
   - **Short Press (< 1000 ms):** Toggles LED LD2 state.
   - **Long Press (≥ 1000 ms):** Enters continuous alert blinking mode (5.0 Hz). Next short press exits alert mode.
2. **Implementation Flow:**
   - Non-blocking state machine records `press_start_time = HAL_GetTick()` upon falling edge.
   - Upon rising edge, computes `duration = HAL_GetTick() - press_start_time;`.

---

## Dedicated Task Folders
- 📁 **[TASK 11A: User LED LD2 Bring-Up](TASK11A/)**: 1.0 Hz HAL toggle project.
- 📁 **[TASK 11B: Push Button B1 Control](TASK11B/)**: Debounced latching switch control project.
- 📁 **[TASK 11C: Press Duration Classifier](TASK11C/)**: Short vs long press duration classifier project.

---

## Circuit Diagram
![Circuit Diagram](circuit.png)

---

## Summary & Inferences
1. Successfully verified NUCLEO-F401RE GPIO push-pull and pull-up input configurations.
2. State remembrance architecture retains output state across physical button releases.
3. Millisecond timebase measurement (`HAL_GetTick()`) enables non-blocking multi-event classification on a single input pin.
