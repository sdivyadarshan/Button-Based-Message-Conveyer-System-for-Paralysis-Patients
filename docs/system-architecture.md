# System Architecture

~~~text
+---------------------------+
|       User / Patient      |
+-------------+-------------+
              |
              v
+---------------------------+
|  Three Push-Button Inputs |
|        D2, D3, D4         |
+-------------+-------------+
              |
              v
+---------------------------+
|        Arduino MCU        |
| Read -> Debounce -> Map   |
|    3-bit input pattern    |
+-------------+-------------+
              |
              v
+---------------------------+
|       I2C LCD Output      |
|          16 x 2           |
+---------------------------+
~~~

## Functional Blocks
- **Input:** Three momentary push buttons with 10 kΩ pull-down resistors.
- **Processing:** Arduino samples inputs, debounces the pattern and maps it to a predefined message.
- **Output:** The I2C LCD displays the selected message.

Signal flow: button state → digital sampling → debounce → pattern encoding → message lookup → LCD.

The prototype is standalone. It does not send messages to a phone, cloud service or remote caregiver and has no audio output.
