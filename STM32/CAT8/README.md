# CAT 8: STM32 GPIO Bring-Up & Switch-Controlled LED

## Experiment Overview
- **Course:** Fundamentals of IoT Lab (25CS2741)
- **Target Platform:** STM32 Blue Pill (STM32F103C8T6, ARM Cortex-M3 @ 72 MHz)
- **Primary Toolchain:** STM32CubeMX, Keil MDK-ARM, ST-LINK V2
- **Objective:** Configure STM32 GPIO input and output peripherals using STM32CubeMX and the HAL library to interface a tactile push-button with an onboard LED across follow mode, toggle mode, and duration classification modes.

---

## Active Subtasks
- 📁 **[TASK 8A: GPIO Direct Follow Mode](TASK8A/)**: Output LED on `PC13` directly reflects the real-time state of push-button on `PA0`.
- 📁 **[TASK 8B: Debounced Push Button Toggle Mode](TASK8B/)**: 25 ms non-blocking debounce filter toggling `PC13` LED state upon each valid press.
- 📁 **[TASK 8C: Non-Blocking Short vs Long Press Duration Classifier](TASK8C/)**: Distinguishes short press (<1s) from long press (≥1s) using `HAL_GetTick()`.

---

## Working Principle & Hardware Setup
1. **Target Hardware:** STM32 Blue Pill has an onboard user LED connected to `PC13` (Active-LOW: logic LOW turns LED ON, logic HIGH turns it OFF). An external tactile button is wired to `PA0` with an internal pull-up resistor.
2. **Direct Follow Logic:** Reads `HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)` and immediately sets `PC13` to match the pressed/released state.
3. **Debounced Toggle:** Records millisecond timestamps using `HAL_GetTick()`. When a state change persists longer than 25 ms, the transition is confirmed as a valid press.
4. **Duration Classifier:** Measures the elapsed time between falling edge (button pressed) and rising edge (button released):
   - **Short Press (< 1000 ms):** Toggles LED steady ON/OFF.
   - **Long Press (≥ 1000 ms):** Enters or exits a 100 ms fast blinking strobe mode.

---

## Circuit Diagram
![Circuit Diagram](circuit.png)

---

## Summary & Inferences
1. Successfully mastered STM32CubeMX GPIO pin configuration in input pull-up and output push-pull/open-drain modes.
2. Non-blocking timing using `HAL_GetTick()` eliminates CPU blocking caused by `HAL_Delay()`.
3. Switch duration classification allows a single button to execute multiple user actions.
