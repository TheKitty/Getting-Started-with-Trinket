/* Trinket Software Serial Test Program */
 
#include <SoftwareSerial.h> 
 
SoftwareSerial Serial(2,0);   // Receive Pin 2 (RX), Transmit Pin 0 (TX)
 
void setup(void) {
  Serial.begin(9600);         // Establish serial comms at 9600 baud
  Serial.println("Hello from Trinket");  // Verify comms working
  pinMode(1,OUTPUT);                     // Red LED pin
}
 
void loop(void) {
  Serial.println(millis());  // Print the time in milliseconds
  digitalWrite(1,HIGH);      // Flash the LED for half a second
  delay(500);
  digitalWrite(1,LOW);
  delay(2000);               // Wait 2 seconds
}


