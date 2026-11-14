# Button-Based Message Conveyer System for Paralysis Patients

A low-cost Arduino assistive-communication prototype. Three physical push buttons select predefined messages displayed on a 16×2 I2C LCD.

## Objectives
- Support basic communication for a person who may have difficulty speaking but can operate a button.
- Provide a simple, low-cost interface.
- Map individual and simultaneous button presses to distinct messages.
- Demonstrate digital input handling and Boolean decision logic.

## System Architecture
**Input:** Button 1, Button 2 and Button 3 on Arduino D2, D3 and D4.  
**Processing:** Arduino reads and debounces the input states, then matches the exact combination.  
**Output:** 16×2 I2C LCD.

## Button Command Table
1 = pressed; 0 = not pressed.

| Button 1 | Button 2 | Button 3 | LCD message |
|---:|---:|---:|---|
| 0 | 0 | 0 | WAITING |
| 1 | 0 | 0 | HELLO EVERYONE |
| 0 | 1 | 0 | BYE EVERYONE |
| 0 | 0 | 1 | I NEED HELP |
| 1 | 1 | 0 | EMERGENCY |
| 1 | 0 | 1 | PLEASE COME HERE |
| 0 | 1 | 1 | WATER PLEASE |
| 1 | 1 | 1 | I AM NOT OK / HELP ME |

## Hardware Requirements
- Arduino Uno or compatible Nano — 1
- Momentary push buttons — 3
- 10 kΩ pull-down resistors — 3
- 16×2 I2C LCD — 1
- 1 kΩ resistor — 1 (purchased; intended use not confirmed in the documented circuit)
- Jumper wires and breadboard

## Pin Connections
| Component | Arduino |
|---|---|
| Button 1 signal | D2 |
| Button 2 signal | D3 |
| Button 3 signal | D4 |
| LCD SDA | A4 (Uno/Nano) |
| LCD SCL | A5 (Uno/Nano) |
| LCD VCC / GND | 5V / GND |

Each button connects between 5V and its input pin. A separate 10 kΩ resistor connects each input pin to GND. All grounds are common. Check the LCD module voltage rating. Full details: [wiring and components](hardware/wiring-and-components.md).

## Software Setup
1. Install Arduino IDE.
2. Select Arduino Uno or the exact compatible Nano board.
3. Install a compatible LiquidCrystal_I2C library through Library Manager.
4. Open `src/message_conveyer.ino`.
5. The default LCD address is `0x27`; change it to `0x3F` if your module uses that address.
6. Select the correct port and upload.

Wire is included with the Arduino environment. LiquidCrystal_I2C is an external library.

## Repository Structure
- `src/` — complete Arduino sketch
- `hardware/` — pinout CSV and wiring/component guide
- `docs/` — algorithm, architecture, design decisions, testing, contribution and AI disclosure
- `media/` — location for original project photographs and demo links

## Testing Status
The student reported that the LCD and button combinations worked after completing all button connections. This is a user-reported observation, not independent formal validation. Formal test logs and photographs have not been supplied. See the [testing checklist](docs/testing.md).

## Contributions and AI Disclosure
The student proposed the project, selected and assembled the hardware, completed wiring, and exercised the prototype. AI assistance was used for code structuring, troubleshooting explanations and repository documentation. See [contribution and AI disclosure](docs/contribution-and-ai-disclosure.md).

## Limitations and Safety
This is an educational prototype, not a certified medical device or replacement for clinically prescribed communication aids. It has fixed messages, no wireless alert, no speech output and no clinical validation. Do not connect the circuit to mains voltage.

## License
No license file has been added because no license choice or authorization was provided. Reuse is not expressly granted until a license is selected.

## Future Improvements
Larger accessible switches, adjustable messages, audio output, caregiver notification with privacy safeguards, and user-centred usability evaluation.
