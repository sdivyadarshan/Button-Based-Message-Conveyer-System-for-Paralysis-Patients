# Wiring and Components

## Bill of Materials
| Component | Quantity | Purpose |
|---|---:|---|
| Arduino Uno / compatible Nano | 1 | Main controller |
| Momentary push buttons | 3 | User inputs |
| 10 kΩ resistors | 3 | Pull-down resistors |
| 16×2 I2C LCD | 1 | Message output |
| 1 kΩ resistor | 1 | Purchased item; use not confirmed |
| Jumper wires | As required | Interconnections |
| Breadboard | 1 | Prototyping |

## Button Wiring: External Pull-Down
Repeat this circuit for all three buttons:

~~~text
5V ----[ PUSH BUTTON ]----+---- Arduino digital input
                          |
                        [10 kΩ]
                          |
                         GND
~~~

| Button | Input pin | Button connection | Resistor |
|---|---|---|---|
| Button 1 | D2 | 5V to D2 | D2 to GND |
| Button 2 | D3 | 5V to D3 | D3 to GND |
| Button 3 | D4 | 5V to D4 | D4 to GND |

Released = LOW; pressed = HIGH. Each input needs its own pull-down resistor. Resistors are non-polar and can be installed in either orientation.

### Four-Leg Tactile Switch
On common 4-leg tactile switches, the two legs on each side are internally connected. The switch connects the two sides only while pressed. Place it across the breadboard centre gap and use one leg from each side. Verify continuity if the footprint is unfamiliar.

## I2C LCD
| LCD pin | Arduino Uno/Nano |
|---|---|
| VCC | 5V (check module rating) |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

The sketch defaults to address 0x27. Some modules use 0x3F. If the backlight is on but text is absent, verify address, contrast, SDA/SCL and library compatibility.

## Jumper Wire Types
- Male–male: Arduino/breadboard and breadboard-to-breadboard connections.
- Male–female: Arduino header to a module with female header.
- Female–female: only when both endpoints expose male pins.

## 1 kΩ Resistor
The 1 kΩ resistor appears in the purchased component list, but its intended role was not established. The documented button and I2C LCD circuit does not require it. Do not add it arbitrarily to button or I2C lines; update this guide if its actual use is confirmed.

Use only low-voltage Arduino power. Never connect this circuit directly to mains voltage.
