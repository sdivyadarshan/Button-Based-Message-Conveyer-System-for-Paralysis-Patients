# Algorithm and Message Logic

## Input Encoding
UP (D2) is bit 0, DOWN (D3) is bit 1, and LEFT (D4) is bit 2. Pressed is HIGH (1); released is LOW (0).

## Message Table
| UP | DOWN | LEFT | Pattern (UP, DOWN, LEFT) | Message |
|---:|---:|---:|:---:|---|
| 0 | 0 | 0 | 000 | WAITING |
| 1 | 0 | 0 | 001 | HELLO EVERYONE |
| 0 | 1 | 0 | 010 | BYE EVERYONE |
| 0 | 0 | 1 | 100 | I NEED HELP |
| 1 | 1 | 0 | 011 | EMERGENCY |
| 1 | 0 | 1 | 101 | PLEASE COME HERE |
| 0 | 1 | 1 | 110 | WATER PLEASE |
| 1 | 1 | 1 | 111 | I AM NOT OK / HELP ME |

## Algorithm
1. Configure D2 (UP), D3 (DOWN) and D4 (LEFT) as inputs.
2. Initialize the I2C LCD.
3. Read the three button states and encode them as a 3-bit pattern.
4. Wait for the input pattern to remain stable for the debounce interval.
5. Match the exact pattern to its predefined message.
6. Update the LCD when the accepted pattern changes.
7. Repeat continuously.

## Boolean Logic
AND describes a condition where all specified inputs are active together. OR describes a condition where at least one specified input is active. The firmware uses exact pattern matching so every combination has one unique message; OR is not implemented as a separate user command.

## Pseudocode
~~~text
START
  initialize UP, DOWN, LEFT buttons and LCD
  REPEAT
    read all button states
    debounce input pattern
    identify exact combination
    display corresponding message
  FOREVER
~~~
