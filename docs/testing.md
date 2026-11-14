# Testing Checklist and Observations

## Reported Observation
The student reported that the LCD initially showed unintended messages while button inputs were not fully connected. After completing all button and pull-down resistor connections, the student reported that the button combinations and LCD worked. This is a user-reported observation, not independent formal validation. No test logs, dates, measured response times or photographs were supplied.

## Bench Checklist
- [ ] Confirm board selection and operating voltage.
- [ ] Confirm common GND for Arduino, LCD and button circuit.
- [ ] Verify Button 1 changes D2 from LOW to HIGH when pressed.
- [ ] Verify Button 2 changes D3 from LOW to HIGH when pressed.
- [ ] Verify Button 3 changes D4 from LOW to HIGH when pressed.
- [ ] Confirm all released inputs read LOW.
- [ ] Confirm LCD initializes and displays text.
- [ ] Confirm LCD I2C address.
- [ ] No buttons: WAITING.
- [ ] Button 1: HELLO EVERYONE.
- [ ] Button 2: BYE EVERYONE.
- [ ] Button 3: I NEED HELP.
- [ ] Button 1 + 2: EMERGENCY.
- [ ] Button 1 + 3: PLEASE COME HERE.
- [ ] Button 2 + 3: WATER PLEASE.
- [ ] All three: I AM NOT OK / HELP ME.
- [ ] Repeat tests to check for missed or false inputs.
- [ ] Confirm message remains stable after release.

## Test Record
| Test | Expected output | Actual output | Pass/Fail |
|---|---|---|---|
| No buttons | WAITING | Not formally recorded | Not recorded |
| Button 1 | HELLO EVERYONE | Not formally recorded | Not recorded |
| Button 2 | BYE EVERYONE | Not formally recorded | Not recorded |
| Button 3 | I NEED HELP | Not formally recorded | Not recorded |
| Button 1 + 2 | EMERGENCY | Not formally recorded | Not recorded |
| Button 1 + 3 | PLEASE COME HERE | Not formally recorded | Not recorded |
| Button 2 + 3 | WATER PLEASE | Not formally recorded | Not recorded |
| All three | I AM NOT OK / HELP ME | Not formally recorded | Not recorded |

## Troubleshooting
- Random messages: inspect floating inputs, missing pull-down resistors, loose GND and switch leg orientation.
- One input always active: check for a short to 5V or incorrect switch wiring.
- LCD backlight but no text: check I2C address, contrast, SDA/SCL and library compatibility.
- Flickering or missed input: inspect loose wires and confirm the debounce sketch is uploaded.
