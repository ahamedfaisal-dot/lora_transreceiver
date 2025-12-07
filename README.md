# ESP32 LoRa 2-Way Wireless Chat with LED Indicator

This project demonstrates a full-duplex wireless communication system using ESP32 and LoRa (SX127x) modules.

Users can send and receive text messages in both directions using the Serial Monitor, acting as a wireless chat system. An LED indicator blinks whenever a message is received, providing instant visual feedback.

## Features

- Two-way wireless communication
- Send text directly from Serial Monitor
- Real-time message reception
- LED blinks when data is received
- RSSI signal strength display
- Long-range communication using LoRa
- Same firmware runs on both nodes

## How It Works

Each ESP32 acts as both a Transmitter and a Receiver:

- **Transmitter Mode**: Sends text typed in the Serial Monitor via LoRa.
- **Receiver Mode**: Listens for incoming LoRa packets, displays them in the Serial Monitor, and blinks an LED.

Both devices run the exact same firmware, making the system symmetric and easy to scale.

## Hardware Requirements

- 2 × ESP32 Development Boards
- 2 × LoRa Modules (SX1276 / SX1278)
- 2 × LEDs
- 2 × 220Ω Resistors
- Jumper Wires
- Breadboard
- USB Cables

## Wiring Diagram (LoRa to ESP32)

| ESP32 Pin | LoRa Pin | Description |
|-----------|----------|-------------|
| 3.3V      | VCC      | Power       |
| GND       | GND      | Ground      |
| GPIO 18   | SCK      | SPI Clock   |
| GPIO 19   | MISO     | SPI MISO    |
| GPIO 23   | MOSI     | SPI MOSI    |
| GPIO 5    | NSS (CS) | Chip Select |
| GPIO 14   | RESET    | Reset       |
| GPIO 26   | DIO0     | Interrupt   |

### LED Connection

- GPIO 13 → Resistor (220Ω) → LED (+) / Anode
- GND → LED (-) / Cathode

## Software Requirements

- Arduino IDE
- ESP32 Board Package installed in Board Manager
- LoRa Library by Sandeep Mistry

## Installing the Library

1. Open Arduino IDE
2. Go to **Sketch → Include Library → Manage Libraries**
3. Search for "LoRa"
4. Install the library by Sandeep Mistry

## Configuration

Before uploading, ensure you set the correct frequency in the code based on your LoRa module version:

```cpp
// Select frequency based on your module
#define LORA_FREQ 433E6   // 433 MHz (Asia/Europe)
// #define LORA_FREQ 866E6   // 866 MHz (Europe)
// #define LORA_FREQ 915E6   // 915 MHz (North America)
```

## How to Run the Project

1. Connect LoRa module to both ESP32 boards
2. Upload the same code to both boards
3. Open two Serial Monitors at 115200 baud
4. Type a message in one board's Serial Monitor and press Enter
5. The message will:
   - Appear on the other board
   - Blink the LED
   - Display RSSI signal strength
6. Type back from the second board for two-way communication

## Example Output

```
📤 Sending: Hello LoRa
✅ Message Sent

📥 Received: Hello LoRa
📶 RSSI: -67
```

## Applications

 Wireless text communication

 IoT device messaging

 Remote monitoring commands

 Chat systems in disaster zones

 Long-range sensor networks
