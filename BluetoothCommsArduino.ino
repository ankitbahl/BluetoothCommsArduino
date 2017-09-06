
#include <SoftwareSerial.h>// import the serial library
#include "pitches.h"

SoftwareSerial Bluetooth(10, 11); // RX, TX
int transistorPin=13; // led on D13 will show blink on / off
int bluetoothData; // the data given from Computer
int pollDelay = 20;
int notes[] = {NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6};

void setup() {
  // put your setup code here, to run once:
  Bluetooth.begin(9600);
  Bluetooth.println("Bluetooth On please press 1 or 0 blink LED ..");
  Serial.begin(9600);
  pinMode(transistorPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   if (Bluetooth.available()){
     bluetoothData = Bluetooth.read();
     if(bluetoothData == '1') {
      digitalWrite(transistorPin, HIGH);
     }
     else {
      int num = bluetoothData - '0';
      tone(transistorPin, notes[num - 2]);
     }
     
    if (bluetoothData == '0'){// if number 0 pressed ....
      Serial.print(bluetoothData);
      digitalWrite(transistorPin, LOW);
      noTone(transistorPin);
    }
  }
  delay(pollDelay);// prepare for next data ...
}

