//LED con boton


#define LED 33
#define BOT 34
void setup() {
  pinMode(LED,OUTPUT);
  pinMode(BOT,INPUT);

  Serial.begin(115200);

}

void loop() {
  bool button_status= digitalRead(BOT);
  Serial.println(button_status);

  if(button_status){

    digitalWrite(LED,HIGH);
  }

  else {
     digitalWrite(LED,LOW);

  }

  delay(500);
}
