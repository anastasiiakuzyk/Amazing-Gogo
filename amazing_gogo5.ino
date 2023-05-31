const int nRows = 5;    // Set the number of rows in the LED matrix
const int nCols = 5;    // Set the number of columns in the LED matrix
int leds[nRows][nCols]; // Create a 2D array of LEDs

void setup() {
  for (int row = 0; row < nRows; row++) {    // Iterate through the rows
    for (int col = 0; col < nCols; col++) {  // Iterate through the columns
      leds[row][col] = row * nCols + col;   // Assign the pin number to each LED
      pinMode(leds[row][col], OUTPUT);     // Set the pin as output
    }
  }
}

void loop() {
  for (int row = nRows-1; row > 0; row--) {   // Iterate through the rows, starting from the bottom
    for (int col = 0; col <= nCols; col++) {   // Iterate through the columns
      int brightness = row * 50 + random(-20, 20);  // Generate a fire-like brightness value
      if (brightness < 0) brightness = 0;    // Ensure the brightness level is within the valid range
      if (brightness > 255) brightness = 255;
      analogWrite(leds[row][col], brightness); // Set the brightness of the LED
      delay(10);                              // Delay for a short time
      analogWrite(leds[row][col], 0);         // Turn off the LED
    }
    delay(50);  // Delay for a short time between rows
  }
}