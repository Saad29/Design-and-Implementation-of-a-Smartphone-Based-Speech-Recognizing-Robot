#include "SoftwareSerial.h" // import the serial library \

 const int IN1 = 3;
 const int IN2 = 5;
 const int IN3 = 6;
 const int IN4 = 9;
 int BluetoothData;
 SoftwareSerial HC05 (10, 11); // RX, TX
 int SPEED_Control = 200;
 void setup () {
 // FIRST, define the Motor's pin as an OUTPUT

 pinMode (IN1, OUTPUT); // Right Motor 1st wire
 pinMode (IN2, OUTPUT); // Right Motor 2nd wire
 pinMode (IN3, OUTPUT); // left Motor 1st wire
 pinMode (IN4, OUTPUT); // left Motor 2nd wire
 HC05. begin (9600);
 }
 void FORWARD (int Speed) {
 // When we want to let Motor To Rotate clock wise
 // Just void this part on the loop section.

 analogWrite (IN1,0);
 analogWrite (IN2, Speed);
 analogWrite (IN3, Speed);
 analogWrite (IN4,0);
 }
 void BACKWARD (int Speed) {
 // When we want to let Motor To Rotate Counter clock wise
 // Just void this part on the loop section.
 analogWrite (IN1, Speed);
 analogWrite (IN2,0);
 analogWrite (IN3,0);
 analogWrite (IN4, Speed);
 }
 void LEFT (int Speed) {
 // When we want to let Motor To Rotate Counter clock wise
 // Just void this part on the loop section.
 analogWrite (IN1,0);
 analogWrite (IN2, Speed);
 analogWrite (IN3,0);
 analogWrite (IN4, Speed);
 }
 void RIGHT (int Speed) {
 // When we want to let Motor To Rotate Counter clock wise
 // Just void this part on the loop section.
 analogWrite (IN1, Speed);
 analogWrite (IN2,0);
 analogWrite (IN3, Speed);
 analogWrite (IN4,0);
 }

 void Stop () {
 // When we want to let Motor To Rotate clock wise
 // Just void this part on the loop section.
 analogWrite (IN1,0);
 analogWrite (IN2,0);
 analogWrite (IN3,0);
 analogWrite (IN4,0);
 }

 void loop () {
 // Rise Up

 if (HC05. available ()) {
 BluetoothData = HC05. read ();
 Serial. println (BluetoothData);

 if (BluetoothData == 'F') {// if number 1 pressed ....
 FORWARD (SPEED_Control);
 }
 if (BluetoothData == 'B') {// if number 1 pressed ....
 BACKWARD (SPEED_Control);
 }
 if (BluetoothData == 'L') {// if number 1 pressed ....
 RIGHT (SPEED_Control);

 }
 if (BluetoothData == 'R') {// if number 1 pressed ....
 LEFT (SPEED_Control);
 }
 if (BluetoothData == 'S') {// if number 1 pressed ....
 Stop ();
 }
 if (BluetoothData == '0') {SPEED_Control = 0;} // Speed
 if (BluetoothData == '1') {SPEED_Control = 50;  } // Speed
 if (BluetoothData == '2') {SPEED_Control = 100;  } // Speed
 if (BluetoothData == '3') {SPEED_Control = 120;  } // Speed
 if (BluetoothData == '4') {SPEED_Control = 140;  } // Speed
 if (BluetoothData == '5') {SPEED_Control = 160;  } // Speed
 if (BluetoothData == '6') {SPEED_Control = 180;  } // Speed
 if (BluetoothData == '7') {SPEED_Control = 200;  } // Speed
 if (BluetoothData == '8') {SPEED_Control = 220;  } // Speed
 if (BluetoothData == '9') {SPEED_Control = 240;  } // Speed
 if (BluetoothData == 'q') {SPEED_Control = 255;  } // Speed
 }
 }
