# 25011102023_FIoT_LAB — Fundamentals of Internet of Things + Lab

**Course Code:** 25CS2741  
**Course Title:** Fundamentals of Internet of Things + Lab  
**Institution:** Shiv Nadar University, Chennai — Department of Computer Science & Engineering  
**Academic Level:** B.Tech CSE (IoT) — II Year / 3rd Semester  
**Student Register Number:** 25011102056 
**Default Branch:** `main`

---

## 1. About the Repository

This repository contains the laboratory work for the **Fundamentals of Internet of Things (FIoT) Lab**. It is organized by microcontroller platform and Continuous Assessment (CAT), with experiment source code, hardware circuit diagrams, project configuration files, supporting libraries, and experiment-level documentation.

The repository currently has two main platform directories:

1. **8051 (`8051/`)** — Bare-metal Embedded C experiments for the **AT89S52** microcontroller using the Keil C51 toolchain. The work covers GPIO, LED control, keypad and display interfacing, timers, software PWM, stepper-motor control, UART, and LCD interfacing.
2. **STM32 (`STM32/`)** — ARM Cortex-M firmware projects using **STM32CubeMX**, the **STM32 HAL**, and **Keil MDK-ARM**. The projects use the STM32 Blue Pill (STM32F103C8T6) and NUCLEO-F401RE (STM32F401RET6) boards, progressing from GPIO and USART exercises to Wi-Fi, BME280 sensing, HTTP, MQTT, and Node-RED integration.

The repository is organized around the contents currently present in the `main` branch. Task names and folder references below follow the repository layout rather than an assumed syllabus template.

---

## 2. Repository Structure

```text
25011102023_FIoT_LAB/
│
├── README.md
│
├── 8051/
│   ├── CAT2/
│   │   ├── README.md
│   │   ├── main.c
│   │   ├── STARTUP.A51
│   │   ├── TASK2B.uvproj
│   │   ├── circuit.png
│   │   └── objects/
│   │       └── TASK2B.hex
│   │
│   ├── CAT3/
│   │   ├── README.md
│   │   ├── main.c
│   │   ├── STARTUP.A51
│   │   ├── TASK3A.uvproj
│   │   ├── circuit.png
│   │   └── objects/
│   │
│   ├── CAT4/
│   │   ├── README.md
│   │   ├── main.c
│   │   ├── STARTUP.A51
│   │   ├── TASK4A.uvproj
│   │   ├── circuit.png
│   │   └── objects/
│   │
│   ├── CAT5/
│   │   ├── README.md
│   │   ├── TASK5A/
│   │   ├── TASK5B/
│   │   │   ├── TASK5B.1/
│   │   │   ├── TASK5B.2/
│   │   │   └── TASK5B.3/
│   │   └── TASK5C/
│   │
│   ├── CAT6/
│   │   ├── TASK6A/
│   │   └── TASK6B/
│   │
│   └── CAT7/
│       ├── TASK7A/
│       ├── TASK7B/
│       └── TASK7C/
│
└── STM32/
    ├── CAT8/
    │   ├── README.md
    │   ├── TASK8A/
    │   ├── TASK8B/
    │   └── TASK8C/
    │
    ├── CAT9/
    │   ├── README.md
    │   ├── TASK9A/
    │   └── TASK9B/
    │
    ├── CAT10/
    │   ├── README.md
    │   ├── TASK10A/
    │   ├── TASK10B/
    │   └── TASK10C/
    │
    ├── CAT11/
    │   ├── README.md
    │   ├── TASK11A/
    │   ├── TASK11B/
    │   └── TASK11C/
    │
    ├── CAT12/
    │   ├── README.md
    │   ├── TASK12A/
    │   ├── TASK12B/
    │   └── TASK12C/
    │
    ├── CAT13/
    │   ├── README.md
    │   ├── TASK13/
    │   ├── TASK13A/
    │   └── TASK13B/
    │
    ├── CAT14/
    │   ├── README.md
    │   ├── TASK14/
    │   ├── TASK14A/
    │   └── TASK14B/
    │
    └── CAT15/
        ├── README.md
        ├── TASK15/
        └── NodeRED/
            ├── README.md
            └── flows.json
```

### 2.1 Common STM32 Task Project Contents

The STM32 task projects generally use the STM32CubeMX / HAL project layout. Depending on the task, a project directory may contain:

| File / Folder | Purpose |
|---|---|
| `*.ioc` | STM32CubeMX peripheral and pin configuration |
| `.mxproject` | STM32CubeMX project metadata |
| `Core/Inc/` | Application header files |
| `Core/Src/` | Application source and interrupt files |
| `Drivers/` | CMSIS and STM32 HAL driver files |
| `MDK-ARM/` | Keil µVision project and startup files |
| `circuit.png` | Hardware wiring diagram |
| `README.md` | Experiment objective, implementation notes, and observations |

The exact files vary between tasks. Refer to the individual task directory before assuming that every item in this table is present.

### 2.2 8051 Project Contents

The 8051 experiments use Keil C51 project files (`*.uvproj`), Embedded C source files, and the 8051 startup assembly file (`STARTUP.A51`). The repository also contains circuit diagrams and `objects/` build-output folders in applicable experiments.

---

## 3. Platform and CAT Overview

### 3.1 8051 Experiments

| CAT | Experiment / Focus | Tasks present in this repository |
|---|---|---|
| [CAT2](8051/CAT2/) | 8051 hardware bring-up, LED blink, and delay library | [TASK2B](8051/CAT2/) |
| [CAT3](8051/CAT3/) | Debounced push-button control and four-mode LED pattern controller | [TASK3A](8051/CAT3/) |
| [CAT4](8051/CAT4/) | Matrix keypad scanning, 7-segment display, and LED HMI | [TASK4A](8051/CAT4/) |
| [CAT5](8051/CAT5/) | Hardware Timer 0, software PWM, LED fading, and stepper motor | [TASK5A](8051/CAT5/TASK5A/), [TASK5B.1](8051/CAT5/TASK5B/TASK5B.1/), [TASK5B.2](8051/CAT5/TASK5B/TASK5B.2/), [TASK5B.3](8051/CAT5/TASK5B/TASK5B.3/), [TASK5C](8051/CAT5/TASK5C/) |
| [CAT6](8051/CAT6/) | UART driver development and serial communication | [TASK6A](8051/CAT6/TASK6A/), [TASK6B](8051/CAT6/TASK6B/) |
| [CAT7](8051/CAT7/) | 16×2 LCD driver, display control, and keypad-based interaction | [TASK7A](8051/CAT7/TASK7A/), [TASK7B](8051/CAT7/TASK7B/), [TASK7C](8051/CAT7/TASK7C/) |

**8051 target:** AT89S52, 8-bit MCS-51 architecture. The experiments use register-level Embedded C and the Keil µVision C51 environment. Hardware details such as the clock, supply voltage, pin assignments, and peripheral wiring are documented in the corresponding experiment README and circuit diagram.

### 3.2 STM32 Experiments

| CAT | Experiment / Focus | Tasks present in this repository |
|---|---|---|
| [CAT8](STM32/CAT8/) | STM32 GPIO bring-up and switch-controlled LED operation | [TASK8A](STM32/CAT8/TASK8A/), [TASK8B](STM32/CAT8/TASK8B/), [TASK8C](STM32/CAT8/TASK8C/) |
| [CAT9](STM32/CAT9/) | USART serial communication and command-controlled LED | [TASK9A](STM32/CAT9/TASK9A/), [TASK9B](STM32/CAT9/TASK9B/) |
| [CAT10](STM32/CAT10/) | STM32–Wemos Wi-Fi modem interface using ESP8266 AT commands | [TASK10A](STM32/CAT10/TASK10A/), [TASK10B](STM32/CAT10/TASK10B/), [TASK10C](STM32/CAT10/TASK10C/) |
| [CAT11](STM32/CAT11/) | NUCLEO-F401RE GPIO, onboard LED, push-button state, and press-duration classification | [TASK11A](STM32/CAT11/TASK11A/), [TASK11B](STM32/CAT11/TASK11B/), [TASK11C](STM32/CAT11/TASK11C/) |
| [CAT12](STM32/CAT12/) | BME280 environmental sensing and HTTP cloud ingestion | [TASK12A](STM32/CAT12/TASK12A/), [TASK12B](STM32/CAT12/TASK12B/), [TASK12C](STM32/CAT12/TASK12C/) |
| [CAT13](STM32/CAT13/) | BME280 I2C sensing and MQTT cloud analytics using ESP8266 / ESPLib | [TASK13](STM32/CAT13/TASK13/), [TASK13A](STM32/CAT13/TASK13A/), [TASK13B](STM32/CAT13/TASK13B/) |
| [CAT14](STM32/CAT14/) | Environmental sensing with BME280 and MQTT cloud analytics | [TASK14](STM32/CAT14/TASK14/), [TASK14A](STM32/CAT14/TASK14A/), [TASK14B](STM32/CAT14/TASK14B/) |
| [CAT15](STM32/CAT15/) | BME280 MQTT telemetry with Node-RED dashboard and analytics | [TASK15](STM32/CAT15/TASK15/), [NodeRED](STM32/CAT15/NodeRED/) |

**STM32 target boards used across the repository:**

- **STM32 Blue Pill:** STM32F103C8T6, ARM Cortex-M3.
- **NUCLEO-F401RE:** STM32F401RET6, ARM Cortex-M4.
- **Wi-Fi interface:** Wemos D1 Mini / ESP8266 modem using AT-command communication in the relevant projects.
- **Environmental sensor:** Bosch BME280, interfaced over I2C in the sensing experiments.

The board and peripheral configuration for a particular task must be taken from that task's `.ioc` file, source code, and README. Not every STM32 task uses every board or peripheral listed above.

---

## 4. Tools and Technologies

| Tool / Technology | Usage |
|---|---|
| Keil µVision C51 | 8051 Embedded C development |
| Keil MDK-ARM | STM32 ARM firmware development |
| STM32CubeMX | STM32 pin, clock, and peripheral configuration |
| STM32 HAL | STM32 peripheral abstraction and driver APIs |
| AT89S52 | 8051 microcontroller platform |
| STM32F103C8T6 | Blue Pill development board |
| STM32F401RET6 | NUCLEO-F401RE development board |
| Wemos D1 Mini / ESP8266 | Wi-Fi modem and AT-command interface |
| Bosch BME280 | Temperature, humidity, and pressure sensing |
| MQTT | Lightweight publish/subscribe messaging in the MQTT experiments |
| HTTP | Request-based telemetry transfer in the HTTP experiment |
| Node-RED | MQTT ingestion, data processing, dashboard visualization, and analytics |
| MQTTX / serial terminal tools | Testing and debugging communication where applicable |

---

## 5. Experiment Documentation

Experiment documentation is maintained at the CAT level or task level depending on the directory structure. Open the relevant `README.md` for the detailed objective, hardware connections, implementation, and observations.

A useful experiment report should include the following information:

| Field | Description |
|---|---|
| **Experiment / CAT** | Continuous Assessment number |
| **Date** | Date on which the experiment was performed |
| **Experiment Name** | Experiment title |
| **Hardware Setup / Platform** | Board, microcontroller, sensors, peripherals, and interface |
| **Task Number** | Task identifier and title |
| **Circuit Diagram** | Wiring diagram and pin connections |
| **Core Logic** | Working principle, algorithm, or pseudocode |
| **Code / Project Files** | Main source files, headers, libraries, and IDE project |
| **Output / Verification** | Observed hardware or terminal output |
| **Inference** | Result and technical conclusion |

### 5.1 Circuit Diagram Convention

Where a `circuit.png` file exists, it is stored with the relevant CAT or task and can be embedded in its README using a relative path:

```markdown
![Circuit Diagram](circuit.png)
```

For a diagram stored in a parent folder, adjust the relative path accordingly, for example:

```markdown
![Circuit Diagram](../circuit.png)
```

Circuit diagrams should identify the development board, connected components, GPIO or bus pins, power supply, and ground.

### 5.2 Source Code and Project Files

- **8051:** Embedded C source (`.c`), header files (`.h`) where used, startup assembly (`STARTUP.A51`), Keil C51 project (`.uvproj`), circuit diagrams, and available build output.
- **STM32:** CubeMX configuration (`.ioc`), application source and header files under `Core/`, HAL and CMSIS dependencies under `Drivers/`, Keil project files under `MDK-ARM/`, startup assembly, and circuit diagrams.
- **Node-RED:** The CAT15 Node-RED folder contains an importable `flows.json` file and a setup / usage README.

---

## 6. Network and IoT Configuration

The IoT experiments use different communication paths depending on the CAT:

| Experiment | Communication path | Purpose |
|---|---|---|
| CAT10 | STM32 USART ↔ ESP8266 AT interface | Wi-Fi modem setup and network connection |
| CAT12 | BME280 I2C → STM32 → ESP8266 → HTTP → Node-RED | Environmental telemetry over HTTP |
| CAT13 | BME280 I2C → STM32 / ESPLib → ESP8266 → MQTT broker | MQTT environmental telemetry |
| CAT14 | BME280 I2C → STM32 / ESP8266 MQTT client → broker | MQTT sensor-data publishing |
| CAT15 | BME280 → STM32 / ESP8266 → MQTT broker → Node-RED | Live dashboard and environmental analytics |

### 6.1 Configuration and Credential Safety

Network credentials, private tokens, and passwords should be supplied locally during setup and must not be committed to a public repository. Use placeholders in documentation and source examples, such as:

- Wi-Fi SSID: `<YOUR_WIFI_SSID>`
- Wi-Fi password: `<YOUR_WIFI_PASSWORD>`
- MQTT broker: use the broker configured for the experiment
- MQTT topic: use the topic configured in the corresponding firmware and Node-RED flow

Do not assume that a network name, password, IP address, broker, or topic used in one experiment is valid for another experiment. Check the relevant task source, README, and Node-RED flow for the configuration actually used.

---

## 7. Node-RED Dashboard — CAT15

The CAT15 Node-RED project is stored in [`STM32/CAT15/NodeRED/`](STM32/CAT15/NodeRED/).

| File | Description |
|---|---|
| [`flows.json`](STM32/CAT15/NodeRED/flows.json) | Node-RED flow to import into the Node-RED editor |
| [`README.md`](STM32/CAT15/NodeRED/README.md) | Dashboard setup, flow import, and testing instructions |
| [`circuit.png`](STM32/CAT15/circuit.png) | CAT15 hardware / system diagram |

The documented dashboard flow includes MQTT message ingestion, BME280 telemetry processing, environmental metrics, gauges, trend charts, and alert logic. Refer to the CAT15 Node-RED README and `flows.json` for the exact nodes, topic, payload format, and dashboard configuration.

---

## 8. General Repository Guidelines

1. Keep experiments inside their existing `8051/` or `STM32/` platform directory.
2. Preserve the CAT and task folder names already used in the repository.
3. Keep source files, project configuration, and supporting headers together with their respective experiment.
4. Include a circuit diagram when the experiment requires external hardware connections.
5. Update the relevant README when pin mappings, hardware, code behavior, or experiment results change.
6. Verify project paths and required libraries before building in Keil.
7. Do not commit generated temporary files unless they are intentionally part of the submission.
8. Never publish Wi-Fi passwords, API keys, private tokens, or other credentials in source files or documentation.
9. Test Node-RED flows with the correct broker, topic, and payload format before relying on the dashboard.
10. Keep links in this README relative so they continue to work when the repository is cloned.

---

## 9. Repository Links

- **GitHub Repository:** [25011102023_FIoT_LAB](https://github.com/byneedipranavraj666/25011102023_FIoT_LAB)
- **8051 Experiments:** [`8051/`](8051/)
- **STM32 Experiments:** [`STM32/`](STM32/)
- **CAT15 Node-RED Dashboard:** [`STM32/CAT15/NodeRED/`](STM32/CAT15/NodeRED/)

---

*This README describes the directory layout and experiment groups currently present in the repository's `main` branch. Update the structure and CAT index when new tasks or files are added.*
