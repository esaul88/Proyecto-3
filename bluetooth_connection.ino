#include <SoftwareSerial.h>

//Se configuran pines RX y TX.
SoftwareSerial BTSerial(10, 11);

//Esta variable guarda el comando enviado
char receivedChar;

void setup() {
  
  //Configuración de pin 13 (controla el LED integrado en el Arduino)
  pinMode(13, OUTPUT);

  //Inicialización de comunicación Serial y Bluetooth.
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {
  // Mientras que el módulo reciba información nueva, el código revisará
  // si se ha mandado un 0, un 1 o un comando incorrecto y actuará acordemente.
  while (BTSerial.available() > 0) {
    receivedChar = BTSerial.read();
    Serial.print("Mensaje recibido: ");
    Serial.println(receivedChar);

    if(receivedChar == '1') {
      Serial.println("Se recibió comando de encendido.");
      digitalWrite(13, HIGH);
      BTSerial.println("Se ha encendido el LED.");
    }
    else if (receivedChar == '0') {
      Serial.println("Se recibió comando de apagado.");
      digitalWrite(13, LOW);
      BTSerial.println("Se ha apagado el LED.");
    }
    else {
      Serial.println("Se recibió comando inválido.");
      BTSerial.println("No hubo acción, comando inválido.");
    }
  }
}


