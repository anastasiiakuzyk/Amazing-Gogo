const byte gPin = 11; // digital output pin for the green component of the RGB LED
const byte bPin = 10; // digital output pin for the blue component of the RGB LED
const byte rPin = 9; // digital output pin for the red component of the RGB LED

void setup() {
  pinMode(rPin, OUTPUT); // set the red LED pin as output
  pinMode(gPin, OUTPUT); // set the green LED pin as output
  pinMode(bPin, OUTPUT); // set the blue LED pin as output
}

void loop() {
  digitalWrite(bPin, LOW); // turn off the blue LED
  digitalWrite(rPin, HIGH); // turn on the red LED
  delay(500); // wait for half a second
  
  digitalWrite(rPin, LOW); // turn off the red LED
  digitalWrite(gPin, HIGH); // turn on the green LED
  delay(500); // wait for half a second
  
  digitalWrite(gPin, LOW); // turn off the green LED
  digitalWrite(bPin, HIGH); // turn on the blue LED
  delay(500); // wait for half a second
}
