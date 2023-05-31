const int n = 10;    // Set the number of LEDs in the array
int leds[n];         // Create an array of n LEDs

void setup() {
  for (int i = 0; i < n; i++) {   // Iterate through the array
    leds[i] = i + 2;              // Assign the pin number to each LED
    pinMode(leds[i], OUTPUT);    // Set the pin as output
  }
}

void loop() {
  for (int i = 0; i < n; i++) {   // Iterate through the array
    digitalWrite(leds[i], HIGH); // Turn on the current LED
    delay(random(50, 200));      // Delay for a random amount of time
    digitalWrite(leds[i], LOW);  // Turn off the current LED
  }
}
