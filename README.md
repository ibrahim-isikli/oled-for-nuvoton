# SSD1306 OLED Display Library for Nuvoton M031 Series

This is a lightweight I2C driver library for controlling **SSD1306 OLED displays** using the **Nuvoton M031 series microcontrollers**. The library is adapted from STM32 HAL-based code to work with the NuMicro SDK (CMSIS or BSP) environment. It supports basic initialization, command communication, screen clearing, and updating via I2C.


https://github.com/user-attachments/assets/08f9930c-ce0a-42be-b365-8d633d142dc4


## ✅ Features

- Compatible with SSD1306-based OLED displays (128x64 by default)
- Communicates over I2C
- Written in C for embedded applications
- Tested on Nuvoton M031 series (e.g., M031BT/M031EC)
- Simple and clean API
- Non-blocking (except initialization delay)
- Can be easily ported to other NuMicro devices

## 📦 Contents

- `ssd1306.c` – OLED driver implementation
- `ssd1306.h` – Driver header and configuration
- `fonts.c/.h` – Default fonts library. It is used in all LCD based libraries.
- `main.c` – Example usage


## 🔧 Getting Started

### Prerequisites

- Nuvoton NuMaker board with M031 MCU
- NuTool/NuEclipse or Keil IDE
- I2C0 or I2C1 properly initialized
- OLED display with SSD1306 controller connected over I2C

### Wiring Example (Default I2C0)

| OLED Pin | M031 Pin |
|----------|----------|
| VCC      | 3.3V     |
| GND      | GND      |
| SCL      | I2C0_SCL (e.g., PB.4) |
| SDA      | I2C0_SDA (e.g., PB.5) |

> 📌 Use pull-up resistors (4.7kΩ recommended) on SDA and SCL.

### Initialization

In `main.c`:

```c
#include "ssd1306.h"

int main(void)
{
    SYS_Init();         // System & peripheral clocks
    I2C0_Init();        // Your I2C setup here
    SSD1306_Init();     // Initialize OLED

    SSD1306_Fill(SSD1306_COLOR_BLACK);
    SSD1306_UpdateScreen();

    SSD1306_GotoXY(0, 0);
    SSD1306_Puts("Hello from M031!", &Font_7x10, SSD1306_COLOR_WHITE);
    SSD1306_UpdateScreen();

    while(1);
}
