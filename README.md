⏰ LCD Clock with Arduino Uno

A small project for practicing Embedded Systems and LCD interfacing with AVR (Arduino Uno).
It runs a simple digital clock on a 16x2 LCD, showing the time in HH:MM:SS format.

📌 What it does

Displays a real-time clock on a 16x2 LCD.

Uses a simple software counter to increment seconds, minutes, and hours.

LCD is driven in 8-bit mode using direct AVR ports.

Built in C using Microchip Studio.

Zoom in on the code, and you’ll see the classic embedded concepts:

LCD initialization and commands

GPIO port control

Delay functions (_delay_ms)

Modular design for LCD functions

🛠️ Hardware Used

Arduino Uno (ATmega328P)

16x2 Character LCD (HD44780 / LM016L compatible)

10k Potentiometer (for contrast control)

220Ω Resistor (for LCD backlight)

Breadboard + jumper wires

🔌 Wiring Connections
LCD Pin	Function	Arduino Uno Pin
VSS	GND	GND
VDD	+5V	5V
VEE	Contrast (via pot)	Potentiometer middle
RS	Register Select	D8 (PB0)
RW	Read/Write	GND
E	Enable	D10 (PB2)
D0–D7	Data Lines	D0–D7 (PD0–PD7)
LED+	Backlight	+5V via 220Ω
LED–	Backlight	GND
💻 Software Requirements

Microchip Studio (for compiling and uploading)

AVR Toolchain (GCC-AVR)

AVRDUDE (for programming, optional if using Arduino bootloader)

🚀 Running it

Open the project in Microchip Studio.

Build the project (Ctrl+Shift+B).

Upload the HEX file to your Arduino Uno using:

avrdude -c arduino -p m328p -P COM3 -b 115200 -U flash:w:project.hex


(adjust COM port as needed)

Power up the Arduino Uno.

The LCD will display the running digital clock.
