# CAT 10 - TASK 10B: Wi-Fi Modem Configuration (Station & AP Connect)

## 1. Objective
Automate the configuration sequence of the ESP8266 Wi-Fi modem from the STM32 host microcontroller over USART1, setting the modem into Station Mode, connecting to the campus Wi-Fi access point (`SNUC`), and querying the assigned IP address.

## 2. Hardware Setup & Pin Mapping
| Component | STM32 Pins | Description |
|---|---|---|
| **ESP8266 Wi-Fi Modem** | `PA9` (TX), `PA10` (RX) | USART1 AT command interface |
| **PC ST-LINK Console** | `PA2` (TX), `PA3` (RX) | USART2 telemetry logger |

## 3. Working Principle & AT Sequence
1. **Startup Sequence:**
   - `AT\r\n`: Verifies communication link with modem.
   - `AT+CWMODE=1\r\n`: Configures ESP8266 as a Wi-Fi Station (client device).
   - `AT+CWJAP="SNUC","snu12345"\r\n`: Performs 802.11 WPA2 handshake and associates with the network.
   - `AT+CIFSR\r\n`: Queries the local IP and MAC addresses allocated by DHCP.
2. **Diagnostic Forwarding:** All incoming responses from the modem are forwarded to USART2 for real-time monitoring in PuTTY.

## 4. Circuit Diagram
![Circuit Diagram](circuit.png)

## 5. Output Verification & Inferences
- PuTTY terminal displays: `WIFI CONNECTED`, followed by `WIFI GOT IP` and `+CIFSR:STAIP,"192.168.1.X"`.
- Validates reliable embedded network association over the standard AT command set.
