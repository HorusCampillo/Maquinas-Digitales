//mandar lecturas por BT


#include <Adafruit_BMP085.h>
#define LED 33
#define LDR 32
Adafruit_BMP085 bmp;

char payload[80]; //payload de lecturas



void setup() {
  
  bmp.begin(0x77); //iniciamos el bmp
  Serial.begin(115200);



}

void loop() {

  sprintf(payload, "%d , %f", 
          bmp.readPressure(), 
          bmp.readTemperature() );
          
  Serial.println(payload);
  delay(500);

}
