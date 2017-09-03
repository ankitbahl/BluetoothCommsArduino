
#include <SoftwareSerial.h>// import the serial library

SoftwareSerial Bluetooth(10, 11); // RX, TX
int transistorPin=13; // led on D13 will show blink on / off
int bluetoothData; // the data given from Computer
int pollDelay = 100;

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
     if(bluetoothData == '1'){   // if number 1 pressed ....
      Serial.print(bluetoothData);
      digitalWrite(transistorPin, HIGH);
     }
     
    if (bluetoothData == '0'){// if number 0 pressed ....
      Serial.print(bluetoothData);
      digitalWrite(transistorPin, LOW);
    }
  }
  delay(pollDelay);// prepare for next data ...
}

