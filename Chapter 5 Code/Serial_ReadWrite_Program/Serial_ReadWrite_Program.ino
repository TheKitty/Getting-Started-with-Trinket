/* Trinket Software Serial Echo Program */
 
#include <SoftwareSerial.h>   // Use the Arduino IDE library (no upload needed)
#include <ctype.h> 
 
SoftwareSerial Serial(2,0);   // Receive Pin 2 (RX), Transmit Pin 0 (TX)
 
#define LED 1  // The Trinket onboard LED is on Pin #1
 
void setup(void) {
  Serial.begin(9600);         // Establish serial comms at 9600 baud
  Serial.println("Hello from Trinket");  // Verify comms working
  Serial.println(" ");
  Serial.println("Type text and I will echo it back");
  Serial.println("Any time I see a number, I will flash the LED");
  Serial.println(" ");
  pinMode(LED, OUTPUT);                     // Red LED pin
}
 
void loop(void) {
  char c;
  if (Serial.available()) {  // Has something been received?
    c = Serial.read();       //  yes, read it
    Serial.write(toupper(c));         // write it back out capitalized
    if(c >='0' and c <='9') flash();  // if it was a number, flash Trinket LED
  }
}

void flash() {
  digitalWrite(LED, HIGH);      // Flash the LED for half a second
  delay(500);
  digitalWrite(LED, LOW);
}
