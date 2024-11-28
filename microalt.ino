int ctr1 =0;   
int ctr2 =0;
int unSegundo= 1000;
unsigned long previousMicroCtr1 =0;
int decimoSegundo = 100000;


 void Print( int ctr1, int ctr2){
     Serial.println(" C1: " + String(ctr1) + " C2 : " + String(ctr2));
  }

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMicros = micros();
  
  if(currentMicros - previousMicroCtr1 > decimoSegundo){
    previousMicroCtr1 = currentMicros;
    ctr1++;
    Print(ctr1, ctr2);
    if(ctr1%20==0){
      ctr2++;
      ctr1-=ctr2;
      Serial.println("2 segundos");
      Print(ctr1, ctr2);
    }
  }
}