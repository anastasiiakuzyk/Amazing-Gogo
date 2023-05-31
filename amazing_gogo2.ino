const byte ledPins[] = {11, 10, 9}; // digital output pins for the RGB LED
const byte buttonPins[] = {2, 3}; // digital input pins for the pushbuttons
volatile byte color = 0; // current color of the LED (0 = green, 1 = blue, 2 = red)
volatile unsigned int delayTime = 500; // delay time between LED on/off cycles (in milliseconds)

void setup() {
  // set the LED pins as outputs
  for (byte i = 0; i < sizeof(ledPins); i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  // set the button pins as inputs with pull-up resistors and attach interrupt handlers
  for (byte i = 0; i < sizeof(buttonPins); i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
    if (i == 0) {
      // attach the interrupt handler for the first button (changes the LED color)
      attachInterrupt(digitalPinToInterrupt(buttonPins[i]), changeColor, FALLING);
    } else {
      // attach the interrupt handler for the second button (changes the delay time)
      attachInterrupt(digitalPinToInterrupt(buttonPins[i]), changeDelay, FALLING);
    }
  }
}

void loop() {
  // select the LED pin corresponding to the current color and turn the LED on and off with the current delay time
  switch(color) {
    case 0:
      ledOnOff(ledPins[0]);
      break;
    case 1:
      ledOnOff(ledPins[1]);
      break;
    case 2:
      ledOnOff(ledPins[2]);
      break;
  }
}

// interrupt handler for the first button (changes the LED color)
void changeColor() {
  color++;
  if(color > 2) {
    color = 0;
  }
}

// interrupt handler for the second button (changes the delay time)
void changeDelay() {
  delayTime += 100;
  if(delayTime > 1000) {
    delayTime = 100;
  }
}

// function to turn the LED on and off with a given delay time
void ledOnOff(byte pin) {
  digitalWrite(pin, HIGH);
  delay(delayTime);
  digitalWrite(pin, LOW);
  delay(delayTime);
}
