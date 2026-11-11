# CAT 9: STM32 USART Command Controlled LED

## Experiment Overview
- **Target Platform:** STM32 NUCLEO-F401RE (ARM Cortex-M4 @ 84 MHz)
- **Primary Toolchain:** STM32CubeMX, Keil MDK-ARM, PuTTY Serial Terminal
- **Objective:** Configure the STM32 USART2 peripheral at 115200-8-N-1 via the ST-LINK Virtual COM Port to implement a character echo engine and an interactive text command parser controlling the onboard user LED.

---

## Active Subtasks
- 📁 **[TASK 9A: Terminal Character Echo Engine](TASK9A/)**: Full-duplex echo immediately transmitting received characters back to the terminal.
- 📁 **[TASK 9B: Interactive LED Command Parser](TASK9B/)**: Command parser supporting `LED ON`, `LED OFF`, `LED TOGGLE`, and `LED STATUS`.

---

## Working Principle & Serial Architecture
1. **Hardware Link:** The NUCLEO-F401RE routes USART2 (`PA2` TX, `PA3` RX) through the onboard ST-LINK debugger directly to the PC as a Virtual COM Port (VCP).
2. **Serial Parameters:** 115200 Baud, 8 Data Bits, 1 Stop Bit, No Parity.
3. **Echo Engine (Task 9A):** Polls `HAL_UART_Receive()` with a short timeout; upon receiving a byte, immediately calls `HAL_UART_Transmit()` to echo it back to the screen.
4. **Command Interpreter (Task 9B):** Accumulates typed characters into a string buffer until Enter (`\r` or `\n`) is received. It compares the string against valid commands:
   - `LED ON` $\rightarrow$ Drives `PA5` HIGH (`HAL_GPIO_WritePin`).
   - `LED OFF` $\rightarrow$ Drives `PA5` LOW.
   - `LED TOGGLE` $\rightarrow$ Inverts `PA5` state (`HAL_GPIO_TogglePin`).
   - `LED STATUS` $\rightarrow$ Reads and prints the current state of `PA5`.

---

## Circuit Diagram
![Circuit Diagram](circuit.png)

---

## Summary & Inferences
1. USART2 communication at 115200 baud provides responsive, reliable interactive debugging.
2. Combining `\r` and `\n` is essential in PuTTY to ensure proper cursor alignment and line formatting.
3. String comparison and command execution allow intuitive human-machine control of microcontroller peripherals.
