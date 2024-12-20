int ctr1 =0;   
int ctr2 =0;
int unSegundo= 1000;
unsigned long previousMicroCtr1 =0;
unsigned long previousMicroCtr2 =0;
int decimoSegundo = 100000;
int dosSegundos = 2000000;


 void Print( int ctr1, int ctr2){
     Serial.println(" C1: " + String(ctr1) + " C2 : " + String(ctr2));
  }

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMicros = micros();
  
  if(currentMicros - previousMicroCtr1 >= decimoSegundo){
    previousMicroCtr1 = currentMicros;
    ctr1++;
    Print(ctr1, ctr2);
  }

  if(currentMicros - previousMicroCtr2 >= dosSegundos){
    previousMicroCtr2 = currentMicros;
    ctr2++;
    ctr1 -= ctr2;
    Print(ctr1, ctr2);
  }
}