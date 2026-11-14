# Design Decisions

1. **Three-button interface:** A small physical interface was chosen to keep operation straightforward. Three binary inputs provide eight possible patterns, including the no-button state.
2. **External pull-down resistors:** Each input uses a 10 kΩ resistor to hold the pin LOW while its button is released. This matches INPUT mode and HIGH-when-pressed firmware.
3. **Exact combination mapping:** Every 3-bit pattern maps to one message. Multi-button presses are evaluated as their own patterns rather than being mistaken for a single press.
4. **I2C LCD:** A 16×2 I2C display reduces the number of Arduino pins needed. On Uno/Nano, SDA is A4 and SCL is A5.
5. **Debouncing:** A 35 ms stable interval is used to reduce false transitions caused by mechanical contact bounce.
6. **Unconfirmed 1 kΩ resistor:** It was listed among purchased components, but its circuit role was not established. It is not inserted into the signal path without confirmation.
7. **Prototype boundary:** This is an educational prototype, not a clinically validated communication aid. Accessibility, mounting, reliability and intended-user usability need further evaluation.
