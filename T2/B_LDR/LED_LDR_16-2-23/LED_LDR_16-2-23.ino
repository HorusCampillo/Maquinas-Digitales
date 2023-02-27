//Mostrar en el Serial Plotter la señal  
// al oscurecer e iluminar el LDR

#define LED 33
#define LDR 35
#define THRLD 1000

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);

}

void loop() {
  int ldr_sgl=analogRead(LDR);
  
  if(ldr_sgl>THRLD){
    digitalWrite(LED,LOW);
    }
  else{
    digitalWrite(LED,HIGH);
  }

  Serial.println(ldr_sgl);
  delay(100);
}
