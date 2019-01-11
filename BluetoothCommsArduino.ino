
#include <SoftwareSerial.h>// import the serial library

SoftwareSerial Bluetooth(10, 11); // RX, TX
int transistorPin=13; // led on D13 will show blink on / off
int bluetoothData; // the data given from Computer
int pollDelay = 10000;
int trip = 7;

void setup() {
  // put your setup code here, to run once:
  Bluetooth.begin(9600);
  Bluetooth.println("Bluetooth On please press 1 or 0 blink LED ..");
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(trip, INPUT_PULLUP);
}

void loop() {
  
  // put your main code here, to run repeatedly:

  if( digitalRead(trip) ) {
    Bluetooth.write("1");
  } else {
    Bluetooth.write("0");
  }
  delay(pollDelay);// prepare for next data ...
}

