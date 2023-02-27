//Mostrar en el Serial Plotter la señal  
// al oscurecer e iluminar el LDR

#define LED 33
#define POT 35
#define THRLD 3500

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);

}

void loop() {
  int pot_sgl=analogRead(POT);
  
  if(pot_sgl>THRLD){
    digitalWrite(LED,LOW);
    }
  else{
    digitalWrite(LED,HIGH);
  }

  Serial.println(pot_sgl);
  delay(100);
}
