const byte rPin = 9; // digital output pin for the red component of the RGB LED
const byte bPin = 10; // digital output pin for the green component of the RGB LED
const byte gPin = 11; // digital output pin for the blue component of the RGB LED
const byte potPin = A0; // analog input pin for the potentiometer
byte colors[][3] = { // 2D array containing RGB values for different colors
  {255, 0, 0},  // Red
  {0, 255, 0},  // Green
  {0, 0, 255},  // Blue
  {255, 255, 0},  // Yellow
  {255, 0, 255},  // Magenta
  {0, 255, 255}   // Cyan
};
int colorIndex = 0; // index of the current color in the colors array

void setup() {
  pinMode(rPin, OUTPUT); // set the red LED pin as output
  pinMode(gPin, OUTPUT); // set the green LED pin as output
  pinMode(bPin, OUTPUT); // set the blue LED pin as output
  pinMode(potPin, INPUT); // set the potentiometer pin as input
}

void loop() {
  int potValue = analogRead(potPin); // read the value of the potentiometer
  
  // Calculate the index of the color in the colors array based on the potentiometer value
  int numColors = sizeof(colors)/sizeof(colors[0]); // get the number of colors in the array
  int index = (potValue * numColors) / 1023; // map the potentiometer value to the range of array indices
  
  // Check that the color index is not greater than the size of the colors array
  if (index >= numColors) {
    index = numColors - 1;
  }

  setColor(colors[index][0], colors[index][1], colors[index][2]); // set the LED color based on the index of the colors array
}

// Set the color of the RGB LED based on the given values for the red, green, and blue components
void setColor(byte r, byte g, byte b) {
  analogWrite(rPin, r); // set the red component of the LED to the given value
  analogWrite(gPin, g); // set the green component of the LED to the given value
  analogWrite(bPin, b); // set the blue component of the LED to the given value
}