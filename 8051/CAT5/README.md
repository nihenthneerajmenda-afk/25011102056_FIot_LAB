# CAT 5: Hardware Timer, Software PWM & Stepper Motor Control

## Experiment Overview
- **Target Platform:** AT89S52 Microcontroller Development Board @ 11.0592 MHz
- **Objective:** Implement precise non-blocking timing using Timer 0 interrupts, generate software PWM waveforms for LED brightness fading and breathing, and drive a 4-phase unipolar stepper motor using a ULN2003 Darlington driver.

---

## Active Subtasks
- 📁 **[TASK 5A: 1 ms Timer 0 ISR & 1s LED Toggle](TASK5A/)**: 16-bit Timer 0 Mode 1 periodic interrupt generating 1 ms time base and 1s LED toggle.
- 📁 **[TASK 5B.1: Software PWM Fading - Triangular Modulation](TASK5B/TASK5B.1/)**: Duty cycle ramp from 0% to 100% and back to 0%.
- 📁 **[TASK 5B.2: Software PWM Fading - Carrier Frequency Analysis](TASK5B/TASK5B.2/)**: Fixed 500 Hz PWM carrier with discrete duty levels (25%, 50%, 75%, 100%).
- 📁 **[TASK 5B.3: Software PWM Multi-LED Breathing Controller](TASK5B/TASK5B.3/)**: Multi-LED breathing effect across Port 1.
- 📁 **[TASK 5C: Stepper Motor Full-Step Sequence Generator](TASK5C/)**: 4-phase full-step excitation sequence driving a 28BYJ-48 stepper motor.

---

## Working Principle & Calculations
1. **Timer 0 1 ms Preload:**
   $$\text{Counts for 1 ms} = \frac{1000\,\mu\text{s}}{1.085\,\mu\text{s}} \approx 922$$
   $$\text{Preload} = 65536 - 922 = 64614 = \text{0xFC66} \quad (\text{TH0} = \text{0xFC},\; \text{TL0} = \text{0x66})$$
2. **Software PWM:** Rapidly switches the output pin ON and OFF within a fixed time window. Modulating the duty cycle (ratio of ON time to total period) varies average power and perceived LED brightness.
3. **Stepper Sequence:** Coils A, B, C, D are energized in the full-step sequence `0x09` $\rightarrow$ `0x0C` $\rightarrow$ `0x06` $\rightarrow$ `0x03` to rotate the motor smoothly.

---

## Circuit Diagram
![Circuit Diagram](circuit.png)

---

## Summary & Inferences
1. Hardware Timer 0 offloads timing from the CPU, allowing accurate 1 ms periodic intervals.
2. Software PWM successfully controls LED brightness without dedicated hardware PWM pins.
3. ULN2003 provides current amplification to step the motor safely.
