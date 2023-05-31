const byte gPin = 11; // digital output pin for the green LED
const byte bPin = 10; // digital output pin for the blue LED
const byte rPin = 9; // digital output pin for the red LED
const byte buttonPin = 2; // digital input pin for the pushbutton
// state of the pushbutton (LOW = not pressed, HIGH = pressed)
volatile byte buttonState = LOW; 

void setup() {
  // set the button pin as input with pull-up resistor and attach an interrupt handler
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(rPin, OUTPUT); // set the red LED pin as output
  pinMode(gPin, OUTPUT); // set the green LED pin as output
  pinMode(bPin, OUTPUT); // set the blue LED pin as output
  // attach the interrupt handler for the pushbutton
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonPressed, FALLING); 
}

void loop() {
  // set the LED colors based on the current state of the pushbutton
  switch(buttonState) {
    case LOW:
      digitalWrite(bPin, LOW);
      digitalWrite(rPin, HIGH);
      digitalWrite(gPin, LOW);
      break;
    case HIGH:
      digitalWrite(bPin, HIGH);
      digitalWrite(rPin, LOW);
      digitalWrite(gPin, HIGH);
      break;
  }
  
  delay(500); // wait for 500 milliseconds
}

// interrupt handler for the pushbutton
void buttonPressed() {
  buttonState = !buttonState; // toggle the button state between LOW and HIGH
}
