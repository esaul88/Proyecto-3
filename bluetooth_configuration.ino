#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11);
char receivedChar;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BT.begin(38400);
  Serial.println("Enviar comandos AT: ");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
    BT.write(Serial.read());
  
  if(BT.available())
    Serial.write(BT.read());
}

