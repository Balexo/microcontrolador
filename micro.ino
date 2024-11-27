long ctr1 =0; 
long ctr2 =0;
long previousMicroCtr1=0;
long previousMicroCtr2=0;
long intervalDecimoSegundo = 100000;
long intervalDosSegundos= 2000000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  long currentMicro = micros();
 
  if(currentMicro - previousMicroCtr1 >= intervalDecimoSegundo){
    previousMicroCtr1 = currentMicro;
    Serial.print("C1 : ");
    ctr1++;
    Serial.print(ctr1);
    Serial.print(" C2 : ");
    Serial.println(ctr2);
  }
    
  if(currentMicro - previousMicroCtr2 >= intervalDosSegundos){
    previousMicroCtr2 = currentMicro;
  ctr2++;
  ctr1 -= ctr2;
  Serial.println("2 segundos");
  Serial.print("C1 : ");
  Serial.print(ctr1);
  Serial.print(" C2 : ");
  Serial.println(ctr2);
  }
}