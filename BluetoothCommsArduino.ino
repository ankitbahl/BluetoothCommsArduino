
#include <SoftwareSerial.h>// import the serial library

SoftwareSerial Bluetooth(10, 11); // RX, TX
int transistorPin=13; // led on D13 will show blink on / off
int BluetoothData; // the data given from Computer
String stillHere = "2";
int pollDelay = 100
int aliveCounter = 0;
int aliveCheckTime = 5; // time in s to check how often to check if controller is still communicating

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
     BluetoothData = Bluetooth.read();
     
     if(BluetoothData == '1'){   // if number 1 pressed ....
      Serial.print(BluetoothData);
      digitalWrite(transistorPin, HIGH);
     }
     
    if (BluetoothData == '0'){// if number 0 pressed ....
      Serial.print(BluetoothData);
      digitalWrite(transistorPin, LOW);
    }
  }
  else {
    if(keepAliveCounter == 
    Bluetooth.write(stillHere);
    keepAliveCounter++:
  }
  delay(pollDelay);// prepare for next data ...
}
