#include "FS.h"
#include "SD.h"
#include "SPI.h"
#include <Adafruit_BMP085.h>


#define LED 33
#define LDR 32


File readings;

Adafruit_BMP085 bmp;
char payload[80]; //payload de lecturas


void setup() {
  pinMode(LED,OUTPUT);
  bmp.begin(0x77);
  
  Serial.begin(115200);

  if(!SD.begin()){

    Serial.println("Card mount failed");
    return;

  }

}

void loop() {

  //Hacemos el payload de las lecturas
  sprintf(payload,"%6.2f, %3.2f,%d",
          bmp.readPressure(),
          bmp.readTemperature(),
          analogRead(LDR));
  
  digitalWrite(LED, LOW);
  readings = SD.open("/lecturas_sensor.csv", FILE_APPEND);
  readings.println(payload);
  readings.close();
  Serial.println(payload);  //imprime la informacion del payload en el archivo creado
  digitalWrite(LED, HIGH);
  delay(500);


















}
