
#include <SoftwareSerial.h>// import the serial library

SoftwareSerial Bluetooth(10, 11); // RX, TX
int transistorPin=13; // led on D13 will show blink on / off
int bluetoothData; // the data given from Computer
char stillHere = '2';
int pollDelay = 100;
int aliveCounter = 0;
int aliveCheckTime = 5000; // time in ms to check how often to check if controller is still communicating
int keepAliveCounter = 0;
int timeOut = 5000;

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
  else {
    if(keepAliveCounter >= (aliveCheckTime/pollDelay)) {
      bool isAlive = false;
      Bluetooth.print(stillHere);
      int timeOutCounter = 0;
      while(timeOutCounter < (timeOut/pollDelay)) {
        delay(pollDelay);
        if(Bluetooth.available()) {
          int data = Bluetooth.read();
          if(data == stillHere) {
            isAlive = true;
          }
        }
        timeOutCounter++;
      }
      keepAliveCounter = 0;
      if(!isAlive) {
        restartBluetooth();
      }
    }
    keepAliveCounter++;
  }
  delay(pollDelay);// prepare for next data ...
}

void restartBluetooth() {
  Serial.print("restarting bluetooth");
}

