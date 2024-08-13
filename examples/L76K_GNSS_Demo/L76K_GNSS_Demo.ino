/* Demo Code to read GPS location using L76K GPS breakout with Arduino UNO & compatible boards
 * Follow below connection for interfacing Arduino and Breakout
     ------------------------------------------------------
     |Arduino | L76 Breakout | Function                   |
     ------------------------------------------------------
     |D8 (TX) | RX           | Serial UART connection     |
     |D7 (RX) | TX           | Serial UART connection     |
     |5V      | 5V           | Positive Supply connection |
     |GND     | GND          | Ground Supply connection   |
     ------------------------------------------------------
 */
#include "L76K.h"

SoftwareSerial mySerial(7, 8); // RX, TX, change this pins if you use different digital pins
#define L76K_BAUDRATE 9600     // default, change if you have modified 

GNRMC gpsData;

void setup()
{
 Serial.begin(9600); // for COM Port and Arduino 
 mySerial.begin(L76K_BAUDRATE); // for L76K GNSS module and Arduino Communication
 delay(500);
}

void loop()
{  
  gpsData = L76K_Gat_GNRMC();
  Serial.println();
  Serial.print("Lat:");
  Serial.print(gpsData.Lat);

  Serial.print("  Lon:");
  Serial.print(gpsData.Lon);
  Serial.println();
}
